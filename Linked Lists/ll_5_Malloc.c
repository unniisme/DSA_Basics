#include <stdio.h>
#include <stdlib.h>

//The node structure
typedef struct node
{
    int item;
    struct node* next;
} node;

node * HEAD = NULL;
node * CURR = NULL; 

//Function to append a node at the end of the linked list
void AppendNode(int item)
{
    node *add = malloc(sizeof(node));
    add -> next = NULL;
    
    //If the list is empty, add the node as the first node
    if(HEAD == NULL)
    {
        HEAD = add;
        add -> item = item;
        return;
    }

    CURR = HEAD;

    //Take the current node to the last nod
    while (CURR -> next != NULL)
    {
        CURR = CURR -> next;
    }

    //Append a node
    CURR -> next = add;
    add -> item = item;
    return;
}

//Function to insert a node in place of a given node
void AddNode(int item, node *pos)
{
    node *add = malloc(sizeof(node));
    add -> item = item;

    //If the given node is the head node, change the head node to the new node
    if (pos == HEAD)
    {
        add -> next = pos;
        HEAD = add;
        return;
    }

    CURR = HEAD;
    node *lookahead = CURR -> next;

    //Go through the list considering both the current and the next node
    while (lookahead != pos && lookahead != NULL)
    {
        CURR = lookahead;
        lookahead = lookahead -> next;
    }

    if (lookahead == NULL)
    {
        return;
    }

    //Insert the new node in the corresponding place
    CURR -> next = add;
    add -> next = lookahead;
}

//Function to perform the insertion action given a number
void InsertNode(int item)
{
    CURR = HEAD;
    node *back = CURR;

    //Go through the list until an element of larger size is encountered
    while (CURR -> item < item && CURR->next != NULL)
    {
        CURR = CURR -> next;
    }

    //If no such element exist, append the new node
    if (CURR -> item < item)
    {
        AppendNode(item);
        return;
    }

    //Else insert it in place of the larger element
    AddNode(item, CURR);
}

//Function to print the linked list
void PrintList()
{
    CURR = HEAD;

    while (CURR != NULL)
    {
        printf("%d\n", CURR -> item);
        CURR = CURR -> next;
    }
    return;
}


int main()
{
    int a;
    for(int i = 0; i<5; i++)
    {
        scanf("%d", &a);
        AppendNode(a);
    }
    int x;
    scanf("%d", &x);

    PrintList();
    InsertNode(x);
    PrintList();

    return 0;
}