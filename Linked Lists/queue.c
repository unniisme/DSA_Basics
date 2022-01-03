#include <stdio.h>
#include <stdlib.h>

//Node
typedef struct node
{
    int item;
    struct node *next;
} node;

//A simple datatype to hold head and tail node pointers
//Note that the tail pointer is identical to the front pointer and head is identical to the rear pointer
typedef struct queue
{
    node *head;
    node *tail;
} queue;

queue Q;

//Function to return if the Queue is empty
int isEmpty()
{
    return (Q.head == NULL);
}

//Function to enqueue, that is, add an element in the next of the current head
void Enqueue(int item, int *errorcode)
{
    node *add = (node*) malloc(sizeof(node));
    if (add == NULL)
    {
        *errorcode = 1;
        return;
    }
    add -> item = item;

    //If queue is empty, add the element directly
    if (isEmpty())
    {
        Q.head = add;
        Q.tail = Q.head;
        *errorcode = 0;
        return;        
    }

    //Add the element after head and move head accordingly
    Q.head->next = add;
    Q.head = Q.head->next;
    return;
}

//Function to dequeue, that is, remove the element that is currently the tail
int Dequeue(int *errorcode)
{
    if(isEmpty())
    {
        *errorcode = 1;
        return 0;        
    }

    node* remove = Q.tail;
    int item = remove->item;

    //If there is only 1 element, set it to null instead of deallocation it
    if(Q.tail == Q.head)
    {
        Q.head = NULL;
    }

    //Move tail pointer and free the now unconnected node
    Q.tail = Q.tail->next;
    free(remove);
        
    *errorcode = 0;
    return item;           
}

//Function to peek, that is, print the tail (frontmost) element
int Peek(int *errorcode)
{
    if (isEmpty())
    {
        *errorcode = 1;
        return 0;
    }
    *errorcode = 0;
    return Q.tail->item;
}

//Function to Display the Queue from tail to head (front to rear)
void Display(int *errorcode)
{
    if (isEmpty())
    {
        *errorcode = 1;
        return;
    }

    node *curr = Q.tail;
    while(curr != NULL)
    {
        printf("%d\n", curr->item);
        curr = curr -> next;
    }
    return;
}


int main()
{
    Q.head = NULL;
    Q.tail = NULL;
    int *errorcode = malloc(sizeof(int));
    int input, item;

    while(1)
    {
        scanf("%d",&input);

        //Each case
        switch(input)
        {
            case 0:
                if(isEmpty())
                {
                    printf("Empty\n");
                }
                else
                {
                    printf("Non Empty\n");
                }
                break;

            case 1:
                scanf("%d",&input);
                Enqueue(input, errorcode);
                if(*errorcode)
                {
                    printf("Enqueue Failure\n");
                    exit(0);
                }
                break;
            
            case 2:
                item = Dequeue(errorcode);
                if(*errorcode)
                {
                    printf("Dequeue Failure\n");
                }
                else
                {
                    printf("%d\n", item);
                }
                break;
                
            case 3:
                item = Peek(errorcode);
                if(*errorcode)
                {
                    printf("Peek Failure\n");
                }
                else
                {
                    printf("%d\n", item);
                }
                break;

            case 4:
                if(isEmpty())
                {
                    printf("Empty List\n");
                }
                else
                {
                    Display(errorcode);
                }
                break;

            default:
                exit(1);
        }        
    }            
    return 0;
}