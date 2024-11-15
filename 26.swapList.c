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

// Function to swap nodes in pairs
ListNode* swapPairs(ListNode* head) {
    // If the list is empty or has only one node, no swap is needed
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Create a dummy node to simplify the head swap
    ListNode* dummy = createNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    
    // Traverse the list in pairs
    while (prev->next != NULL && prev->next->next != NULL) {
        // Identify the two nodes to be swapped
        ListNode* first = prev->next;
        ListNode* second = first->next;
        
        // Swap the nodes
        first->next = second->next;
        second->next = first;
        prev->next = second;
        
        // Move prev to the first node of the swapped pair
        prev = first;
    }

    // Return the new head (the next node of dummy)
    ListNode* newHead = dummy->next;
    free(dummy); // Free the dummy node
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
    // Creating a linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    // Print the original list
    printf("Original List: ");
    printList(head);

    // Swap nodes in pairs
    head = swapPairs(head);
    printf("After swapping pairs: ");
    printList(head);

    return 0;
}
