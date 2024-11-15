#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node *tail = *head;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = newNode;
    return;
}

void insertAtBeginning(struct Node **head, int data){
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}


void printList(struct Node * head){
    struct Node * temp = head;
    while (temp->next != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

struct Node* createNode(int data){
    struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* partition(struct Node* head, int x){
    struct Node * beforeHead = createNode(0);
    struct Node * before = beforeHead;
    struct Node * afterHead = createNode(0);
    struct Node * after = afterHead;
    struct Node * current = head;
    while (current != NULL)
    {
        if(current->data < x){
            before->next = current;
            before = before->next;
        }else if(current->data > x){
            after->next = current;
            after = after->next;
        }
        current = current->next;
    }
    struct Node * newNode = createNode(x);

    after->next = NULL;
    before->next = newNode;
    newNode->next = afterHead->next;
    return beforeHead->next;
}


int main(){
    struct Node * head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 11);
    printList(head);
    printf("\n");
    head = partition(head, 5);
    printList(head);
    printf("\n");
    return 0;
}