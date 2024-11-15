#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct Graph{
    int numVertices; 
    Node ** adjLists;
    bool * visited;
} Graph;

void createNode(int vertex){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = vertex;
    newNode->next = NULL;
    return newNode;
}

void createGraph(int vertices){
    Graph * graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices *sizeof(Node*));
    graph->visited = (bool*)malloc(vertices* sizeof(bool));

    for(int i=0;i<vertices; i++){
        graph->adjLists[i]=NULL;
        graph->visited[i]=false;
    }
    return graph;
}

void addEdge()