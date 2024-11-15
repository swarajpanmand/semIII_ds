#include <stdio.h>
#include <string.h>

#define SIZE 5

typedef struct
{
    int front, rear;
    int items[SIZE];
} CircularQueue;


void init(CircularQueue *q)
{
    q->front = q->rear = -1;
}

int isEmpty(CircularQueue *q)
{
    return (q->front == -1);
}

int isFull(CircularQueue *q)
{
    return ((q->rear + 1) % SIZE == q->front);
}

void enqueue(CircularQueue *q, int value)
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
    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = value;
    printf("Inserted value: %d\n", value);
}

int dequeue(CircularQueue *q)
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
        q->front = q->rear = -1;
    }
    else{
        q->front = (q->front + 1) % SIZE;
    }
    printf("Deleted value: %d\n", value);
    return value;
}

int front(CircularQueue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->front];
}

int rear(CircularQueue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    return q->items[q->rear];
}

int main(){
    CircularQueue q;
    init(&q);
    enqueue(&q, 1); 
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    printf("Front element is: %d\n", front(&q));
    printf("Rear element is: %d\n", rear(&q));
    dequeue(&q);
    dequeue(&q);
    printf("Front element is: %d\n", front(&q));
    printf("Rear element is: %d\n", rear(&q));
    return 0;
}