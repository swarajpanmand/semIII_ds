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

// Function to insert a term into the polynomial in decreasing order of exponents
void insertTerm(PolyNode** poly, int coeff, int exp) {
    PolyNode* newNode = createNode(coeff, exp);
    if (*poly == NULL || (*poly)->exp < exp) {
        newNode->next = *poly;
        *poly = newNode;
    } else {
        PolyNode* temp = *poly;
        while (temp->next != NULL && temp->next->exp > exp) {
            temp = temp->next;
        }
        if (temp->next != NULL && temp->next->exp == exp) {
            temp->next->coeff += coeff; // Combine like terms
            free(newNode); // No need for a new node if terms are combined
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to multiply two polynomials
PolyNode* multiplyPolynomials(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;  // The result polynomial

    // Multiply each term in poly1 with each term in poly2
    for (PolyNode* p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (PolyNode* p2 = poly2; p2 != NULL; p2 = p2->next) {
            int coeff = p1->coeff * p2->coeff;  // Multiply the coefficients
            int exp = p1->exp + p2->exp;        // Add the exponents
            insertTerm(&result, coeff, exp);    // Insert the term into the result
        }
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

// Main function to test the polynomial multiplication
int main() {
    // Polynomial 1: 5x^3 + 4x^2 + 2x + 1
    PolyNode* poly1 = createNode(5, 3);
    poly1->next = createNode(4, 2);
    poly1->next->next = createNode(2, 1);
    poly1->next->next->next = createNode(1, 0);

    // Polynomial 2: 3x^2 + 2x + 6
    PolyNode* poly2 = createNode(3, 2);
    poly2->next = createNode(2, 1);
    poly2->next->next = createNode(6, 0);

    // Display the input polynomials
    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Multiply the polynomials
    PolyNode* result = multiplyPolynomials(poly1, poly2);

    // Display the result
    printf("Result of multiplication: ");
    displayPolynomial(result);

    return 0;
}
    