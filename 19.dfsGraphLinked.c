#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph{
    int numVertices; 
    Node ** adjLists;
    bool * visited;
} Graph;

Node* createNode(int vertex){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices){
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

void addEdge(Graph * graph,int src , int dest){
    Node * newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src]= newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest]= newNode;
}

void dfs(Graph * graph, int vertex){
    Node * temp = graph->adjLists[vertex];

    graph->visited[vertex]= true;
    printf("%d ", vertex);
    while(temp){
        int connectedVertex = temp->vertex;
        if(!graph->visited[connectedVertex]){
            dfs(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void printGraph(Graph * graph){
    for(int v=0; v<graph->numVertices; v++){
        Node * temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while(temp){
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL");
        printf("\n");
    }
    printf("\n");
}

int main(){
    Graph * graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);
    dfs(graph, 2);
    printf("\n");
    return 0;
}