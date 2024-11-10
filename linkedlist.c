#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = 0, *newnode, *temp;

void make_node()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
}
void create_node()
{
    make_node();
    newnode->next = 0;
    if (head == 0)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}

void display()
{
    if (head == 0)
    {
        printf("There is no element in the linked list !!");
    }

    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int count()
{
    int count = 0;
    temp = head;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insert_beginning()
{
    make_node();
    newnode->next = head;
    head = newnode;
}
void insert_end()
{
    if (head == 0)
    {
        insert_beginning();
    }
    else
    {
        make_node();
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = 0;
    }
}

void insert_pos()
{
    int pos;
    printf("Enter the position after which you want to insert: ");
    scanf("%d", &pos);
    if (pos < 0 || pos > count())
    {
        printf("Invalid position");
    }
    else
    {
        if (pos == 0)
        {
            insert_beginning();
        }
        else
        {
            make_node();
            int i = 1;
            temp = head;
            while (i < pos)
            {
                temp = temp->next;
                i++;
            }
            newnode->next = temp->next;
            temp->next = newnode;

            /* OR
            make_node();
            temp = head;

            while (--pos > 0)
            {
                temp = temp->next;
            }

            newnode->next = temp->next;
            temp->next = newnode;
            */
        }
    }
}

void delete_beginning()
{
    if (head == 0)
    {
        printf("Error !! List is already empty");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("\n1st element deleted !! ");
    }
}

void delete_end()
{
    if (head == 0)
    {
        printf("Error !! List is already empty");
    }
    else if (head->next == 0)
    {
        free(head);
        head = 0;
        printf("\nLast element deleted !! ");
    }
    else
    {
        temp = head;
        while (temp->next->next != 0)
        {
            temp = temp->next;
        }
        // temp is now the second-last node
        free(temp->next); // Free the last node
        temp->next = 0;   // Set next of second-last node to 0
        printf("\nLast element deleted !! ");
    }
}

void delete_pos()
{
    struct node *node_to_delete;
    if (head == 0)
    {
        printf("Error !! List is already empty");
    }
    else
    {
        int pos;
        printf("Enter the position which you want to delete: ");
        scanf("%d", &pos);
        if (pos <= 0 || pos > count())
        {
            printf("Invalid Position");
        }
        else if (pos == 1)
        {
            delete_beginning();
        }
        else
        {
            int i = 1;
            temp = head;
            while (i < pos - 1)
            {
                temp = temp->next;
                i++;
            }
            node_to_delete = temp->next;
            temp->next = node_to_delete->next;
            free(node_to_delete);
        }
    }
}

void reverse()
{
    struct node *prev = 0;
    struct node *nextnode;
    temp = nextnode = head;
    while (nextnode != 0)
    {
        nextnode = nextnode->next;
        temp->next = prev;
        prev = temp;
        temp = nextnode;
    }
    head = prev;
}

void sort()
{
    struct node *nextnode;
    int t;
    temp = head;
    while (temp->next != 0)
    {
        nextnode = temp->next;
        while (nextnode != 0)
        {
            if (temp->data > nextnode->data)
            {
                t = temp->data;
                temp->data = nextnode->data;
                nextnode->data = t;
            }
            nextnode = nextnode->next;
        }
        temp = temp->next;
    }
}

int main()
{
    int choice;
    printf("\nSELECT:\n1.Create node\n2.Display\n3.Count\n4.Insert at Beginning\n5.Insert at End\n6.Insert at position\n7.Delete from beginning\n8.Delete from end\n9.Delete from position\n10.Reverse\n11.Sort\n12.Exit");
    do
    {
        printf("\n\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_node();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("The number of elements in the list are:  %d\n", count());
            break;
        case 4:
            insert_beginning();
            break;
        case 5:
            insert_end();
            break;
        case 6:
            insert_pos();
            break;
        case 7:
            delete_beginning();
            break;
        case 8:
            delete_end();
            break;
        case 9:
            delete_pos();
            break;
        case 10:
            reverse();
            break;
        case 11:
            sort();
            break;
        case 12:
            return 0;
            break;

        default:
            printf("\nPlease enter a valid choice !! ");
            break;
        }
    } while (choice != 12);
    return 0;
}
