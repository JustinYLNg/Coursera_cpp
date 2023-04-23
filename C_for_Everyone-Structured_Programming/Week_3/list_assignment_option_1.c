//Option 1
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define RANDOM_RANGE 200        //range of random number generated
#define NUMBER 100      //number of list elements to print

typedef struct list
{
    struct list *next;
    int data;
} LIST;

LIST *createList(int d)
{
    LIST *head = malloc(sizeof(LIST));
    head->data = d;
    head->next = NULL;
    return head;
}

LIST *addToFront(int d, LIST *h)
{
    LIST *head = createList(d);
    head->next = h;
    return head;
}

LIST *propagateList(int n)
{
    int i, num;
    num = rand() % RANDOM_RANGE;
    LIST *head = createList(num);
    for (i = 1; i < n; i++)
    {
        num = rand() % RANDOM_RANGE;
        head = addToFront(num, head);
    }
    return head;
}

void swapList(LIST *h1, LIST *h2)
{
    int temp = h1->data;
    h1->data = h2->data;
    h2->data = temp;
}

void bubbleSort(LIST *h)
{
    int swapped;
    LIST *leftPtr;
    LIST *rightPtr = NULL;
    
    if(h == NULL)
        return;
    do
    {
        swapped = 0;
        leftPtr = h;
        while(leftPtr->next != rightPtr)
        {
            if(leftPtr->data > leftPtr->next->data)
            {
                swapList(leftPtr, leftPtr->next);
                swapped = 1;
            }
            leftPtr = leftPtr->next;    //advance to next list
        }
        rightPtr = leftPtr;             //rightPtr points to previous list
    } while (swapped);
}

void printList(LIST *h)
{
    while(h != NULL)
    {
        int count = 0;
        while(count < 5)
        {
            printf("%d - ", h->data);
            count++;
            h = h->next;
        }
        printf("\n");
    }
}

int main()
{
    srand(time(0));
    LIST *head = NULL;

    head = propagateList(NUMBER);
    bubbleSort(head);
    printList(head);
    return 0;
}