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

// Function to reverse the string
void reverse(char* expr) {
    int n = strlen(expr);
    for (int i = 0; i < n / 2; i++) {
        char temp = expr[i];
        expr[i] = expr[n - i - 1];
        expr[n - i - 1] = temp;
    }
}

// Function to convert infix to postfix
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

// Function to convert infix to prefix
void infixToPrefix(char* infix, char* prefix) {
    // Step 1: Reverse the infix expression
    reverse(infix);

    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    // Step 3: Convert the modified infix expression to postfix
    char postfix[100];
    infixToPostfix(infix, postfix);

    // Step 4: Reverse the postfix expression to get the prefix expression
    reverse(postfix);

    // Copy the result to the prefix array
    strcpy(prefix, postfix);
}

int main() {
    char infix[100], prefix[100];

    // Input infix expression
    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Convert to prefix
    infixToPrefix(infix, prefix);

    // Output prefix expression
    printf("Prefix expression: %s\n", prefix);

    return 0;
}
