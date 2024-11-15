#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
#define N 3

typedef struct MutipleQueue
{
    int front[N], rear[N];
    int items[MAX];
    int size;
} MutipleQueue;

void init(MutipleQueue *q, int size)
{
    q->size = size;
    for (int i = 0; i < N; i++)
    {
        q->front[i] = q->rear[i] = -1;
    }
}

int isFull(MutipleQueue *q, int qNum)
{
    return (q->rear[qNum] == q->size - 1);
}

int isEmpty(MutipleQueue *q, int qNum)
{
    return (q->front[qNum] == -1);
}

void enqueue(MutipleQueue *q, int data, int qNum){
    if(isFull(q, qNum)){
        printf("Queue %d is full\n", qNum);
        return;
    }
    if(isEmpty(q, qNum)){
        q->front[qNum] = qNum * (q->size);
        q->rear[qNum] = q->front[qNum] - 1;
    }
    q->rear[qNum]++;
    q->items[q->rear[qNum]] = data;
    printf("Inserted %d in queue %d\n", data, qNum);
}

int dequeue(MutipleQueue *q, int qNum){
    if(isEmpty(q, qNum)){
        printf("Queue %d is empty\n", qNum);
        return -1;
    }
    int data = q->items[q->front[qNum]];
    if(q->front[qNum] >= q->rear[qNum]){
        q->front[qNum] = q->rear[qNum] = -1;
    }
    else{
        q->front[qNum]++;
    }
    printf("Deleted %d from queue %d\n", data, qNum);
    return data;
}

void display(MutipleQueue *q){
    for(int i=0; i<N; i++){
        printf("Queue %d: ", i);
        for(int j=q->front[i]; j<=q->rear[i]; j++){
            printf("%d ", q->items[j]);
        }
        printf("\n");
    }
}

int main(){
    MutipleQueue q;
    init(&q, 4);

    enqueue(&q, 1, 0);
    enqueue(&q, 2, 1);
    enqueue(&q, 3, 2);
    enqueue(&q, 4, 0);
    enqueue(&q, 5, 1);
    enqueue(&q, 6, 2);
    enqueue(&q, 7, 0);
    enqueue(&q, 8, 1);
    enqueue(&q, 9, 2);
    enqueue(&q, 10, 0);
    enqueue(&q, 11, 1);
    enqueue(&q, 12, 2);

    dequeue(&q, 0);
    dequeue(&q, 1);
    dequeue(&q, 2);
    dequeue(&q, 0);
    dequeue(&q, 1);
    dequeue(&q, 2);
    dequeue(&q, 0);
    dequeue(&q, 1);
    dequeue(&q, 2);
    dequeue(&q, 0);
    dequeue(&q, 1);
    dequeue(&q, 2);

    display(&q);

    return 0;
}
