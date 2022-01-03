#include <stdio.h>
#include <stdlib.h>

//A vertexNode datatype to make lists of neighbours of a vertex
typedef struct vertexNode
{
    int value;
    struct vertexNode *next;
}vertexNode;

//A vertex datatype to hold all information about a vertex
typedef struct vertex
{
    int value;
    vertexNode* edges;
    int visited;
    int completed;
    int entryTime;
    int exitTime;

    struct vertex* parent;
}vertex;

//Global clock
int CLOCK = 0;
int Tick()
{
    CLOCK++;
    return CLOCK-1;
}

//Function Dfs explore
//When called on a node, it marks the node as visited, recursively calls dfs explore on all the unvisited neighbouring trees and notes the entry and exit time
void DfsExplore(vertex** Graph, vertex* v)
{
    if (v->visited)
    {
        return;
    }

    //Note entry time and mark node as visited
    v->entryTime = Tick();
    v->visited = 1;


    vertexNode* curr = v->edges;

    //For each unvisited vertex, set the current vertex as parent and Dfs explore that vertex
    while (curr != NULL)
    {
        if (!(Graph[curr->value]->visited))
        {
            Graph[curr->value]->parent = v;
            DfsExplore(Graph, Graph[curr->value]);
        }
        curr = curr->next;
    }

    v->completed = 1;
    v->exitTime = Tick();
}

//Function to perform DepthFirstSearch
//Calls Dfs explore on all unvisited vertices
void DepthFirstSearch(vertex** Graph, int n)
{
    for (int i=0; i<n; i++)
    {
        if (!(Graph[i]->visited))
        {
            DfsExplore(Graph, Graph[i]);
        }
    }

    return;
}

//Function to initialise an array of vertices
void MakeVertices(vertex** Graph, int size)
{
    for (int i=0; i<size; i++)
    {
        Graph[i] = malloc(sizeof(vertex));
        vertex* vert = Graph[i];
        vert->value = i;
        vert->edges = NULL;
        vert->visited = 0;
        vert->parent = NULL;
        vert->entryTime = -1;
        vert->exitTime = -1;
    }
    return;
}

//Function to create an edge between 2 vertices
//Adds the pointer to b in the list of neighbours of a
void MakeEdge(vertex** Graph, int a, int b)
{
    vertex* vert = Graph[a];
    if(vert->edges == NULL)
    {
        vert->edges = (vertexNode*)malloc(sizeof(vertexNode));
        vert->edges->value = b;
        vert->edges->next = NULL;
        return;
    }

    vertexNode* curr = vert->edges;
    
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = (vertexNode*)malloc(sizeof(vertexNode));
    curr->next->value = b;
    curr->next->next = NULL;
    return;
}

int main()
{
    int n, m, entry;
    
    scanf("%d", &n);
    scanf("%d",&m);

    //Graph is treated as an array of vertices
    vertex* Graph[n];

    MakeVertices(Graph, n);

    int i,j;

    for (int index=0; index<m; index++)
    {
        scanf("%d %d", &i,&j);
        MakeEdge(Graph, i,j);
        MakeEdge(Graph, j,i);
    }

    scanf("%d",&entry);


    CLOCK = 0;

    DfsExplore(Graph, Graph[entry]);
    DepthFirstSearch(Graph, n);

    for (int i=0; i<n; i++)
    {
        printf("%d %d\n", Graph[i]->entryTime, Graph[i]->exitTime);
    }    

    return 0;
}