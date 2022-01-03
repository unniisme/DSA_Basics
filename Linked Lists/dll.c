#include <stdio.h>
#include <stdlib.h>

//Node
typedef struct node
{
    int item;
    struct node* next;
    struct node* prev;
} node;

//Simple struct to hold head and tail pointers
typedef struct list
{
    node* head;
    node* tail;
}list;

list LIST;

//Function to append a node at the end of the list, at the tail
void AppendNode(int item)
{
    node *add = (node*) malloc(sizeof(node));
    add -> next = NULL;
    add -> prev = NULL;
    
    //If the list is empty, add the node as the first node
    if(LIST.head == NULL)
    {
        LIST.head = add;
        LIST.tail = add;
        add -> item = item;
        return;
    }

    node* curr = LIST.tail;

    //Append a node
    add -> prev = curr;
    curr -> next = add;
    add -> item = item;
    LIST.tail = add;
    return;
}

//Function to print the list in either direciton, that is, Head to tail and tail to head
int PrintBacknForth()
{
    if(LIST.head == NULL)
    {
        return 1;
    }

    node* curr = LIST.head;

    while (curr != NULL)
    {
        printf("%d\n", curr->item);
        curr = curr->next;
    }

    curr = LIST.tail;

    while (curr != NULL)
    {
        printf("%d\n", curr->item);
        curr = curr->prev;
    }

    return 0;
}

//Function to remove the head and tail elements and link the list accordingly
int PopEnds()
{
    if(LIST.head == NULL)
    {
        return 1;
    }

    //If list only has 1 element, change it to NULL
    if(LIST.tail == LIST.head)
    {
        LIST.head = NULL;
        return 1; 
    }

    //Remove the head element
    node* del = LIST.head;
    LIST.head = LIST.head->next;
    LIST.head->prev = NULL;
    free(del);

    //If list only has 1 element, change it to NULL
    if(LIST.tail == LIST.head)
    {
        LIST.head = NULL;
        return 0;
    }

    //Remove the tail element
    del = LIST.tail;
    LIST.tail = LIST.tail->prev;
    LIST.tail->next = NULL;
    free(del);

    return 0;
}

int main()
{
    LIST.head = NULL;
    LIST.tail = NULL;

    int n, input;
    scanf("%d", &n);

    for (int i = 0; i<n; i++)
    {
        scanf("%d",&input);
        AppendNode(input);
    }

    PrintBacknForth();

    PopEnds();

    PrintBacknForth();
}

