#include <stdio.h>
#include <stdlib.h>

//A datatype 'vertex' to hold the information about a vertex
//A datatype 'node' to define a linked list
//Note that this specific question does not require 2 datatypes to be defined, I did it for generalisation
//A linked list will be made for each vertex, consisting of its neighbouring vertices

typedef struct node node;

typedef struct vertex
{
    int value;
    node* edge;
} vertex;

struct node 
{
   int vertex;
   node* next; 
};

//Function to initialise all vertices in a graph of n vertices
void MakeVertices(vertex** vertices, int size)
{
    for (int i=0; i<size; i++)
    {
        vertices[i] = malloc(sizeof(vertex));
        vertices[i]->value = i;
        vertices[i]->edge = NULL;
    }
    return;
}

//function to create a directed edge from vertex a to vertex b
void MakeEdge(vertex** vertices, int a, int b)
{
    vertex* vert = vertices[a];
    if(vert->edge == NULL)
    {
        vert->edge = (node*)malloc(sizeof(node));
        vert->edge->vertex = b;
        vert->edge->next = NULL;
        return;
    }

    //If the vertex already has neighbours, add this vertex as the last neighbour in the list of neighbours
    node* curr = vert->edge;
    
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = (node*)malloc(sizeof(node));
    curr->next->vertex = b;
    curr->next->next = NULL;
    return;
}

//Function to print all neighbours of a vertex
void PrintAdjacent(vertex** vertices, int i)
{
    //If there are no neighbours, print Nil
    if (vertices[i]->edge == NULL)
    {
        printf("Nil\n");
        return;
    }

    node* curr = vertices[i]->edge;

    while (curr->next != NULL)
    {
        printf("%d ", curr->vertex);
        curr = curr->next;
    }

    printf("%d\n", curr->vertex);
}


int main()
{
    int n, m;
    
    scanf("%d", &n);
    scanf("%d",&m);

    //The graph is expressed as an array of vertices
    vertex* vertices[n];

    MakeVertices(vertices, n);

    int i,j;
    
    for (int index=0; index<m; index++)
    {
        scanf("%d %d", &i,&j);
        MakeEdge(vertices, i,j);
        MakeEdge(vertices, j,i);
    }

    for (int i=0; i<n; i++)
    {
        PrintAdjacent(vertices, i);
    }    

    return 0;
}