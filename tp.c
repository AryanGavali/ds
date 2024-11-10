#include<stdio.h>
#include<string.h>

struct Student
{
    int roll;
    int division;
    float percent;
    char name[20];
    char address[50];
};

void printArray(struct Student arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\nRoll Number: %d ",arr[i].roll);
        printf("\nName: %s ",arr[i].name);
        printf("\nDivision: %d ",arr[i].division);
        printf("\nPercentage: %f ",arr[i].percent);
        printf("\nAddress: %s ",arr[i].address);
    }
}
void bubbleSort(struct Student arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j].percent>arr[j+1].percent)
            {
                struct Student temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void selectionSort(struct Student arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j].percent<arr[min].percent)
            {
                min=j;
            }
        }
        if(min!=i)
        {
            struct Student temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}

void insertionSort(struct Student arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        struct Student key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j].percent>key.percent)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int ch;
    int size;
    struct Student arr[30];
    do
    {
        printf("\nEnter the number of students: ");
        scanf("%d",&size);
        
        for(int i=0;i<size;i++)
        {
            printf("\nEnter Details of Student %d: ",i+1);
             printf("\nRoll Number: ");
            scanf("%d", &arr[i].roll);
            printf("Name: ");
            scanf("%s", arr[i].name);
            printf("Address: ");
            scanf("%s", arr[i].address);
            printf("Division: ");
            scanf("%d", &arr[i].division);
            printf("Percent: ");
            scanf("%f", &arr[i].percent);
        }
        
        printf("\nArray Before Sorting: ");
        printArray(arr,size);
        
        printf("\n\n---------MENU--------------\n");
        printf("1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nArray After Sorting: ");
                bubbleSort(arr,size);
                printArray(arr,size);
                break;
            case 2:
                printf("\nArray After Sorting: ");
                selectionSort(arr,size);
                printArray(arr,size);
                break;
            case 3:
                printf("\nArray After Sorting: ");
                insertionSort(arr,size);
                printArray(arr,size);
                break;
            case 4:
                return 0;
        }
    }while(ch!=4);
    
    return 0;
}