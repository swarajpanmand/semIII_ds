#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void insertAtEnd(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *tail = *head;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
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
    newNode->prev = tail;
    return;
}

void insertAtBeginning(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    *head = newNode;
}

void insert(Node **head, int position, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    Node *temp = *head;
    if (position == 0)
    {
        newNode->next = *head;
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next = newNode;
    return;
}

void delete(Node **head, int position)
{
    Node *temp = *head;
    if (position == 0)
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
        return;
    }
    for (int i = 0; i < position - 1; i++)
    {
        temp = temp->next;
    }
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next->prev = temp;
    free(temp2);
    return;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

void concatenate(Node **head1, Node **head2)
{
    Node *temp = *head1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = *head2;
    (*head2)->prev = temp;
}

Node *sortList(Node **head){
    Node *temp = *head;
    Node *temp2 = *head;
    while(temp != NULL){
        temp2 = temp->next;
        while (temp2!=NULL)
        {
            if(temp->data > temp2->data){
                int tempData = temp->data;
                temp->data = temp2->data;
                temp2->data = tempData;

            }
            temp2 = temp2->next;
        }
        temp = temp->next;
        
    }
    return *head;
}

void deleteDuplicates(Node ** head){
    Node *temp = *head;
    // Node *temp2 = NULL;
    while(temp->next!= NULL){
        if(temp->data == temp->next->data){
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }
}



int main(){
    Node *head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    insertAtEnd(&head, 7);
    insertAtEnd(&head, 8);
    insertAtEnd(&head, 9);
    insertAtEnd(&head, 10);
    insertAtBeginning(&head, 11);
    insert(&head, 5, 12);
    printList(head);
    printf("\n");
    sortList(&head);
    printList(head);
    printf("\n");
    deleteDuplicates(&head);
    printList(head);
    printf("\n");

    return 0;
}