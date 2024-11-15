#include <stdio.h>
#include <stdlib.h>

// Node structure for representing a term in the polynomial
typedef struct PolyNode {
    int coeff;              // Coefficient of the term
    int exp;                // Exponent of the term
    struct PolyNode* next;  // Pointer to the next term
} PolyNode;

// Function to create a new polynomial node
PolyNode* createNode(int coeff, int exp) {
    PolyNode* newNode = (PolyNode*)malloc(sizeof(PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to add two polynomials
PolyNode* addPolynomials(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;  // The result polynomial
    PolyNode* last = NULL;    // To keep track of the last node in the result
    PolyNode* temp = NULL;    // Temporary node to store new terms

    // Traverse both polynomials
    while (poly1 != NULL && poly2 != NULL) {
        // Case 1: Same exponent
        if (poly1->exp == poly2->exp) {
            int sumCoeff = poly1->coeff + poly2->coeff;

            if (sumCoeff != 0) {
                temp = createNode(sumCoeff, poly1->exp);
                if (result == NULL) {
                    result = temp;  // First term in the result polynomial
                } else {
                    last->next = temp;  // Add the new term at the end
                }
                last = temp;  // Move the last pointer
            }

            poly1 = poly1->next;  // Move to the next term in poly1
            poly2 = poly2->next;  // Move to the next term in poly2
        }
        // Case 2: poly1's exponent is greater than poly2's exponent
        else if (poly1->exp > poly2->exp) {
            temp = createNode(poly1->coeff, poly1->exp);
            if (result == NULL) {
                result = temp;  // First term in the result polynomial
            } else {
                last->next = temp;  // Add the new term at the end
            }
            last = temp;  // Move the last pointer
            poly1 = poly1->next;  // Move to the next term in poly1
        }
        // Case 3: poly2's exponent is greater than poly1's exponent
        else {
            temp = createNode(poly2->coeff, poly2->exp);
            if (result == NULL) {
                result = temp;  // First term in the result polynomial
            } else {
                last->next = temp;  // Add the new term at the end
            }
            last = temp;  // Move the last pointer
            poly2 = poly2->next;  // Move to the next term in poly2
        }
    }

    // If poly1 still has terms, add them
    while (poly1 != NULL) {
        temp = createNode(poly1->coeff, poly1->exp);
        if (result == NULL) {
            result = temp;
        } else {
            last->next = temp;
        }
        last = temp;
        poly1 = poly1->next;
    }

    // If poly2 still has terms, add them
    while (poly2 != NULL) {
        temp = createNode(poly2->coeff, poly2->exp);
        if (result == NULL) {
            result = temp;
        } else {
            last->next = temp;
        }
        last = temp;
        poly2 = poly2->next;
    }

    return result;
}

// Function to display the polynomial
void displayPolynomial(PolyNode* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    while (poly != NULL) {
        if (poly->exp != 0) {
            printf("%dx^%d", poly->coeff, poly->exp);
        } else {
            printf("%d", poly->coeff);
        }

        if (poly->next != NULL && poly->next->coeff > 0) {
            printf(" + ");
        }

        poly = poly->next;
    }
    printf("\n");
}

// Main function to test the polynomial addition
int main() {
    // Polynomial 1: 5x^3 + 4x^2 + 2x + 1
    PolyNode* poly1 = createNode(5, 3);
    poly1->next = createNode(4, 2);
    poly1->next->next = createNode(2, 1);
    poly1->next->next->next = createNode(1, 0);

    // Polynomial 2: 3x^3 + 2x^2 + 6x + 2
    PolyNode* poly2 = createNode(3, 3);
    poly2->next = createNode(2, 2);
    poly2->next->next = createNode(6, 1);
    poly2->next->next->next = createNode(2, 0);

    // Display the input polynomials
    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Add the polynomials
    PolyNode* result = addPolynomials(poly1, poly2);

    // Display the result
    printf("Result of addition: ");
    displayPolynomial(result);

    return 0;
}
