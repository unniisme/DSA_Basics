#include <stdio.h>
#include <stdlib.h>

//The node structure
typedef struct node
{
    int item;
    struct node* next;
} node;

node* HEAD = NULL;

//Function to append a node at the end of the linked list
void AppendNode(int item)
{
    node* add = (node*) malloc(sizeof(node));
    add -> next = NULL;
    
    //If the list is empty, add the node as the first node
    if(HEAD == NULL)
    {
        HEAD = add;
        add -> item = item;
        return;
    }

    node * curr = HEAD;

    //Take the current node to the last nod
    while (curr -> next != NULL)
    {
        curr = curr -> next;
    }

    //Append a node
    curr -> next = add;
    add -> item = item;
    return;
}

//Function to insert a node in place of a given node
void AddNode(int item, node *pos)
{
    node* add = (node*) malloc(sizeof(node));
    add -> item = item;

    //If the given node is the head node, change the head node to the new node
    if (pos == HEAD)
    {
        add -> next = pos;
        HEAD = add;
        return;
    }

    node* curr = HEAD;
    node* lookahead = curr -> next;

    //Go through the list considering both the current and the next node
    while (lookahead != pos && lookahead != NULL)
    {
        curr = lookahead;
        lookahead = lookahead -> next;
    }

    if (lookahead == NULL)
    {
        return;
    }

    //Insert the new node in the corresponding place
    curr -> next = add;
    add -> next = lookahead;
}

//Function to perform the insertion action given a number
void InsertNode(int item)
{
    node* curr = HEAD;
    node* back = curr;

    if (HEAD == NULL)
    {
        AppendNode(item);
        return;
    }

    //Go through the list until an element of larger size is encountered
    while (curr -> item < item && curr->next != NULL)
    {
        curr = curr -> next;
    }

    //If no such element exist, append the new node
    if (curr -> item < item)
    {
        AppendNode(item);
        return;
    }

    //Else insert it in place of the larger element
    AddNode(item, curr);
}

//Function to print the linked list
void PrintList()
{
    node* curr = HEAD;

    while (curr != NULL)
    {
        printf("%d\n", curr -> item);
        curr = curr -> next;
    }
    return;
}


int main()
{
    int a;
    int n;

    scanf("%d", &n);
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &a);
        InsertNode(a);
    }
    PrintList();

    return 0;
}