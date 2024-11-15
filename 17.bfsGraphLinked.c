#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Queue
{
    int front;
    int rear;
    int items[MAX];
} Queue;

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q)
{
    return q->rear == MAX - 1;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;

    q->items[q->rear] = value;
}

int dequeue(Queue *q)
{
    int value;
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    value = q->items[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return value;
}

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph{
    int numVertices;
    Node ** adjLists;
    bool * visited;
} Graph;

Node * createNode(int v){
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
}

Graph * createGraph(int vertices){
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

void addEdge(Graph *graph, int src, int dest){
    Node * newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(Graph* graph){
    for(int v=0; v<graph->numVertices; v++){
        Node * temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d head", v);
        while(temp){
            printf("-> %d", temp->vertex);
            temp = temp->next;
        }
    }
    printf("\n");
}

void BFS(Graph * graph, int startVertex){
    Queue * q;
    q = (Queue*)malloc(sizeof(Queue));
    initQueue(q);

    graph->visited[startVertex]=true;
    enqueue(q, startVertex);
    printf("BFS Traversal: ");

    while(!isEmpty(q)){
        int currVer = dequeue(q);
        printf("%d ", currVer);

        Node * temp = graph->adjLists[currVer];
        while(temp){
            int adjVertex = temp->vertex;
            if(graph->visited[adjVertex]==false){
                graph->visited[adjVertex]=true;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}


int main(){
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    Graph * graph = createGraph(vertices);

    printf("Enter the edges: \n");
    for(int i=0;i<edges;i++){
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    printf("\n");
    printGraph(graph);
    
    int startVertex;
    printf("Enter the start vertex: ");
    scanf("%d", &startVertex);
    BFS(graph, startVertex);
    return 0;
}