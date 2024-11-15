#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Function to get precedence of operators
int precedence(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

// Function to check if the character is an operand (a digit or letter)
int isOperand(char c) {
    return isalpha(c) || isdigit(c);
}

// Function to convert infix expression to postfix
void infixToPostfix(char* infix, char* postfix) {
    int top = -1;
    char stack[100];  // Stack to hold operators
    int k = 0;  // Index for the postfix expression

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isOperand(c)) {
            postfix[k++] = c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            stack[++top] = c;
        }
        // If the character is ')', pop and output until '(' is found
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--;  // Pop '(' from the stack
        }
        // If the character is an operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    // Pop all remaining operators in the stack
    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0';  // Null-terminate the postfix expression
}

int main() {
    char infix[100], postfix[100];

    // Input infix expression
    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Convert to postfix
    infixToPostfix(infix, postfix);

    // Output postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
