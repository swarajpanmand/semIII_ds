#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void BFS(int adjMatrix[MAX][MAX], int vertices, int startVertice)
{
    int visited[MAX] = {0};
    Queue q;
    initQueue(&q);

    visited[startVertice] = 1;
    enqueue(&q, startVertice);
    while (!isEmpty(&q))
    {
        int currentVertice = dequeue(&q);

        printf("%d ", currentVertice);
        for (int i = 0; i < vertices; i++)
        {
            if (adjMatrix[currentVertice][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main()
{
    int vertices, edges, startVertice;
    int adjMatrix[MAX][MAX];
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges: \n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
    }

    printf("Adjancency Matrix: \n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Enter the starting vertice: ");
    scanf("%d", &startVertice);

    BFS(adjMatrix, vertices, startVertice);
    return 0;
}