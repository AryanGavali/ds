#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define max 10
char stack[max];
int top = -1;

void push(char x)
{
    if (top == max - 1)
    {
        printf("\nStack is Full !! ");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("\nStack is empty !! ");
    }
    else
    {
        char temp=stack[top];
        top--;
        return temp;
    }
}

void ispalindrome(char str[])
{
    int length = strlen(str);
    for (int i = 0; i < length; i++)
    {
        push(tolower(str[i]));
    }
    for (int i = 0; i < length; i++)
    {
        if (pop() != tolower(str[i]))
        {
            printf("Not a palindrome string"); 
           return;
        }
    }
    printf("It is a palindrome string");
}

int main()
{
    char str[max];
    printf("Enter a string: ");
    scanf("%s",str);
    ispalindrome(str);
    return 0;
}
