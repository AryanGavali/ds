#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    int lbit, rbit;
    struct node *right;
    struct node *left;
};

void create(struct node *head)
{
    int ch;
    struct node *root;
    root = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Root Data: ");
    scanf("%d", &root->data);
    head->lbit = 1;
    head->left = root;
    root->left = head;
    root->right = head;
    root->lbit = 0;
    root->rbit = 0;
    do
    {
        // temp is used to  traverse the tree and find correct position where the insertion needs to takes place
        struct node *temp = root;
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->lbit = 0;
        newnode->rbit = 0;
        printf("Enter data for new node: ");
        scanf("%d", &newnode->data);

        // this loop is to find the correct position  where the insertion needs to take place
        while (1)
        {
            char choice;
            printf("Do you want to add as a left or right child of %d? (l: left, r: right): ", temp->data);
            scanf(" %c", &choice);

            if (choice == 'l' || choice == 'L')
            {
                if (temp->lbit == 0)
                {
                    newnode->right = temp;
                    newnode->left = temp->left;
                    temp->left = newnode;
                    temp->lbit = 1;
                    break;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else if (choice == 'r' || choice == 'R')
            {
                if (temp->rbit == 0)
                {
                    newnode->left = temp;
                    newnode->right = temp->right;
                    temp->right = newnode;
                    temp->rbit = 1;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
        printf("Do you want to continue adding nodes? (1: Yes, 2: No): ");
        scanf("%d", &ch);
    } while (ch == 1);
}

struct node *inordersucc(struct node *temp)
{
    if (temp->rbit == 0)
    {
        return temp->right;
    }
    struct node *x = temp->right;
    while (x->lbit == 1)
    {
        x = x->left;
    }
    return x;
}

void inorder(struct node *head)
{
    struct node *temp = head->left; //head
    printf("\nInorder Traversal: ");
    while (1)
    {
        temp = inordersucc(temp);
        if (temp == head)
        {
            break;
        }
        printf("%d ", temp->data);
    }
    printf("\n");
}

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));
    head->lbit = 0;
    head->rbit = 1;
    head->left = head;
    head->right = head;

    create(head);
    inorder(head);

    return 0;
}