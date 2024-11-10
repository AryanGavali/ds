#include <stdio.h>
#define size 8
int stack[size];
int top = -1;

void push(int x)
{
    if (top == size - 1)
    {
        printf("\nStack is Full !! ");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("\nStack is Empty !! ");
    }
    else
    {
        printf("The element deleted is: %d", stack[top]);
        top--;
    }
}

void display()
{
    if (top==-1)
    {
        printf("\nStack is empty !!");
    }
    
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}


int main()
{
    int ch, x;
    do
    {
        printf("\n-----------Stack Operations------------\n");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the element to be insrted: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            break;
        }
    } while (ch != 4);

    return 0;
}