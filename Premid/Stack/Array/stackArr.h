#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

typedef struct {
    int ARR[SIZE];
    int Top;
} STACK;

// Stack initialization and utility functions
void initStack(STACK *S);
void makeNull(STACK *S);
bool isEmpty(STACK S);
bool isFull(STACK S);

// Core stack operations
void Push(STACK *S, int data);
void Pop(STACK *S);
int Top(STACK S);

// Additional stack operations
void insertSorted(STACK *s, int data);
void sortStack(STACK *s, bool ascending);
void printList(STACK *S);

// Stack initialization and utility functions implementation
void initStack(STACK *S) {
    S->Top = -1;
}

void makeNull(STACK *S) {
    S->Top = -1;
}

bool isEmpty(STACK S) {
    return (S.Top == -1);
}

bool isFull(STACK S) {
    return (S.Top == SIZE - 1);
}

// Core stack operations implementation
void Push(STACK *S, int data) {
    if (!isFull(*S)) {
        S->ARR[++S->Top] = data;
    }
}

void Pop(STACK *S) {
    if (!isEmpty(*S)) {
        S->Top--;
    }
}

int Top(STACK S) {
    return (isEmpty(S)) ? -1 : S.ARR[S.Top];
}

// Additional stack operations implementation
void insertSorted(STACK *s, int data) {
    STACK temp;
    initStack(&temp);

    while (!isEmpty(*s) && Top(*s) > data) {
        Push(&temp, Top(*s));
        Pop(s);
    }

    Push(s, data);

    while (!isEmpty(temp)) {
        Push(s, Top(temp));
        Pop(&temp);
    }
}

void sortStack(STACK *s, bool ascending) {
    STACK tempStack;
    initStack(&tempStack);

    while (!isEmpty(*s)) {
        int curr = Top(*s);
        Pop(s);

        while (!isEmpty(tempStack) && 
               ((ascending && Top(tempStack) > curr) || 
                (!ascending && Top(tempStack) < curr))) {
            Push(s, Top(tempStack));
            Pop(&tempStack);
        }
        Push(&tempStack, curr);
    }

    while (!isEmpty(tempStack)) {
        Push(s, Top(tempStack));
        Pop(&tempStack);
    }
}

void printList(STACK *S) {
    if (isEmpty(*S)) {
        printf("EMPTY\n");
    } else {
        STACK temp = *S;
        while (temp.Top != -1) {
            printf("%d ", Top(temp));
            Pop(&temp);
        }
        printf("\n");
    }
}

#endif