#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

char stack[MAX];
int top =-1;

void push(char item){
    if(top==(MAX-1)){
        printf("Stack Overflow\n");
        return; 
    }
    stack[++top]=item;
}

char pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

char peek(){
    if(top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top];
}

