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

// Function to reverse a linked list
ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // Reverse both linked lists
    l1 = reverse(l1);
    l2 = reverse(l2);
    
    ListNode* result = NULL;
    ListNode* tail = NULL;
    int carry = 0;
    
    // Perform addition while either list has digits or there is a carry
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        // Update carry for next iteration
        carry = sum / 10;
        
        // Create a new node for the current sum's digit
        ListNode* newNode = createNode(sum % 10);
        
        // Attach the new node to the result list
        if (result == NULL) {
            result = newNode;
            tail = result;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    
    // Reverse the result list to restore the most significant digit at the head
    return reverse(result);
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
    // Creating first operand linked list: 7 -> 2 -> 3 -> 3
    ListNode* l1 = createNode(7);
    l1->next = createNode(2);
    l1->next->next = createNode(3);
    l1->next->next->next = createNode(3);

    // Creating second operand linked list: 5 -> 7 -> 4
    ListNode* l2 = createNode(5);
    l2->next = createNode(7);
    l2->next->next = createNode(4);

    // Print the operands
    printf("Operand 1: ");
    printList(l1);
    printf("Operand 2: ");
    printList(l2);

    // Add the two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Print the result
    printf("Result: ");
    printList(result);

    return 0;
}
