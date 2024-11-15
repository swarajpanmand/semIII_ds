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

struct Node * reverseList(struct Node * head){
    struct Node * prev = NULL;
    struct Node * current = head;
    struct Node * next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
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

int isPalindrome(struct Node * head){
    printf("Original List: ");
    printList(head);
    printf("\n");
    if(head == NULL || head->next == NULL){
        return 1;
    }

    struct Node * slow = head;
    struct Node * fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle element: %d\n", slow->data);

    struct Node * firstHalf = head;
    struct Node * secondHalf = reverseList(slow->next);
    printf("Second Half: ");
    printList(secondHalf);
    printf("\n");
    printf("First Half: ");
    printList(head);
    printf("\n");
    printList(firstHalf);
    printf("\n");
    while (secondHalf != NULL)
    {
        if(firstHalf->data != secondHalf->data){
            return 0;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return 1;
}

int main(){
    struct Node * head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 1);
    printList(head);
    printf("\n");
    head = reverseList(head);
    printList(head);

    printf("\n");
    if(isPalindrome(head)){
        printf("Palindrome\n");
    }else{
        printf("Not Palindrome\n");
    }

    return 0;
}