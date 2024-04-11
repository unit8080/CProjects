#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <queue>
typedef struct AdjListNode_ {
    int nodeId; // vertex (src ->dest)
    struct AdjListNode_ *next;
} AdjListNode;

typedef struct AdjList_ {
    AdjListNode *head;
} AdjList;

typedef struct Graph_ {
    int V; // number of vertices;
    AdjList *array;
} Graph;

AdjListNode *newAdjListNode (int nodeId)
{
    AdjListNode *newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
    newNode->nodeId = nodeId;
    newNode->next = NULL;
    return newNode;
}
Graph *createGraph (int V)
{
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (AdjList *) malloc(V * sizeof(AdjList));
    for (int i=0; i < V; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}
void addEdge (Graph *graph, int src, int nodeId, bool dir)
{
    AdjListNode *newNode = newAdjListNode(nodeId);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    if (!dir) {
        newNode = newAdjListNode(src);
        newNode->next = graph->array[nodeId].head;
        graph->array[nodeId].head = newNode;
    }
}
void printGraph (Graph *graph)
{
    for (int v=0; v < graph->V; v++) {
        AdjListNode *node = graph->array[v].head;
        printf("\n Adjaceny list of vertex %d\n head", v);
        while (node != NULL) {
            printf(" -> %d", node->nodeId);
            node = node->next;
        }
        printf("\n");
    }
}
using namespace std;
bool visited[10];
void GraphBFS(Graph *graph, int v)
{
    int delimiter = -1;
    int level = 0;
    if (graph == NULL)
        return;
    for (int i=0; i < graph->V; i++)
        visited[i] = false;

    queue<int> vQueue;
    printf("\nStarting BFS: \n");
    printf("Level ---> %d\n", level++);
    vQueue.push(v);
    vQueue.push(delimiter);
    while (!vQueue.empty()) {
        if (vQueue.front() == -1) {
            vQueue.pop();
            vQueue.push(delimiter);
            if (vQueue.front() == -1)
                break;
            printf("\nLevel ---> %d\n", level);
            level += 1;
            continue;
        }
        getchar();
        int w = vQueue.front(); // visit v
        if (!visited[w]) {
            printf("    Visiting vertex -> %d\n", w);
            visited[w] = true;
        }
        vQueue.pop();
        AdjListNode *node = graph->array[w].head;
        while (node != NULL) {
            if (!visited[node->nodeId])
                vQueue.push(node->nodeId);
            node = node->next;
        }
    }
}
void GraphDFS (Graph *graph, int v)
{
    printf("Visiting vertex %d\n", v);
    visited[v] = true;
    AdjListNode *node = graph->array[v].head;
    while (node != NULL) {
        if (!visited[node->nodeId]) {
            GraphDFS(graph, node->nodeId);
        }
        node = node->next;
    }
}
int main ()
{
    int V = 6;
    // 0---> 1, 4
    // 1---> 2, 3, 4
    // 2---> 3, 5
    // 3---> 4
    Graph *graph = createGraph(V);
    bool dir = false;
    addEdge(graph, 0, 1, dir);
    addEdge(graph, 0, 4, dir);
    addEdge(graph, 1, 2, dir);
    addEdge(graph, 1, 3, dir);
    addEdge(graph, 1, 4, dir);
    addEdge(graph, 2, 3, dir);
    addEdge(graph, 2, 5, dir);
    addEdge(graph, 3, 4, dir);
 
    // print the adjacency list representation of the above graph
    printGraph(graph);
    GraphBFS(graph, 0);
    //GraphBFS(graph, 1);
    //GraphBFS(graph, 2);
    //GraphBFS(graph, 3);
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;
    printf("\nStart Graph DFS at vertex %d: ", 0);
    GraphDFS(graph, 0);
    for (int i = 0; i < graph->V; i++)
        visited[i] = false;
    printf("\nStart Graph DFS at vertex %d: ", 1);
    GraphDFS(graph, 1);
    return 0;
}
