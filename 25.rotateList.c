#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// Function to create a new node
ListNode* createNode(int val) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate the linked list by k places
ListNode* rotateList(ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0) {
        return head; // No rotation needed for empty or single-node lists, or when k is 0
    }

    // Step 1: Find the length of the list
    ListNode* temp = head;
    int length = 1; // Start with 1 because we are already at the head node
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Step 2: Make the list circular by connecting the last node to the head
    temp->next = head;

    // Step 3: Find the new head position after k rotations
    k = k % length; // In case k is larger than the length
    if (k == 0) {
        temp->next = NULL; // No rotation needed
        return head;
    }

    // Find the node that will be the new tail
    ListNode* newTail = head;
    for (int i = 1; i < length - k; i++) {
        newTail = newTail->next;
    }

    // Step 4: The new head is the node after the new tail
    ListNode* newHead = newTail->next;
    
    // Step 5: Break the circular link
    newTail->next = NULL;

    return newHead;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) {
            printf(" -> ");
        }
        head = head->next;
    }
    printf("\n");
}

// Main function to test the code
int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Print the original list
    printf("Original List: ");
    printList(head);

    // Rotate the list by 1 place
    head = rotateList(head, 1);
    printf("After rotating by 1: ");
    printList(head);

    // Rotate the list by 2 places
    head = rotateList(head, 2);
    printf("After rotating by 2: ");
    printList(head);

    return 0;
}
