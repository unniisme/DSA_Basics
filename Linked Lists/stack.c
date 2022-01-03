#include <stdio.h>
#include <stdlib.h>

//Structure node
typedef struct node
{
    int item;
    struct node *below;
} node;

node *STACK = NULL;

//Function to return if the stack is empty
int isEmpty()
{
    return STACK==NULL;
}


//All the remaining functions take an errorcode pointer as input and changes its value accordingly
//Function to push an element into the stack
void Push(int item, int *errorcode)
{
    node *add = (node*) malloc(sizeof(node));
    if (add == NULL)
    {
        *errorcode = 1;
        return;
    }
    add -> item = item;

    //If stach is empty, the item is added at the top
    if (isEmpty())
    {
        STACK = add;
        *errorcode = 0;
        return;        
    }

    add->below = STACK;
    STACK = add;
    *errorcode = 0;
    return;
}

//Function to remove the top element and return it
int Pop(int *errorcode)
{
    //If array is empty, set errorcode value
    if(isEmpty())
    {
        *errorcode = 1;
        return 0;        
    }

    node*temp = STACK;
    STACK = STACK->below;
    int item = temp->item; 
    free(temp);
    *errorcode = 0;
    return item;           
}

//Function to return the top element
int Top(int *errorcode)
{
    //Error if list is empty
    if (isEmpty())
    {
        *errorcode = 1;
        return 0;
    }
    *errorcode = 0;
    return STACK->item;
}

//Function to print the stack top to bottom
void Display(int *errorcode)
{
    //Error if empty
    if (isEmpty())
    {
        *errorcode = 1;
        return;
    }

    node *curr = STACK;
    while(curr != NULL)
    {
        printf("%d\n", curr->item);
        curr = curr -> below;
    }
}


int main()
{
    int *errorcode = malloc(sizeof(int));
    int input, item;
    
    //Indefinite input
    while(1)
    {
        scanf("%d",&input);
        
        //Each case and corresponding presentation of outputs
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
                Push(input, errorcode);
                if(*errorcode)
                {
                    printf("Push Failure\n");
                    exit(0);
                }
                break;
            
            case 2:
                item = Pop(errorcode);
                if(*errorcode)
                {
                    printf("Pop Failure\n");
                }
                else
                {
                    printf("%d\n", item);
                }
                break;
                
            case 3:
                item = Top(errorcode);
                if(*errorcode)
                {
                    printf("Top Failure\n");
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