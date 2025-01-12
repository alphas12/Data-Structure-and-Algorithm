#ifndef STACK_H
#define STACK_H
#define SIZE 10
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int arr[SIZE];
    int Top;
} STACK;

void initStack(STACK *S){
    S->Top = -1;
}

bool isFull(STACK S){
	return(S.Top == SIZE - 1) ? true : false;
}

bool isEmpty(STACK S){
    return(S.Top == -1) ? true : false;
}

void Push(STACK *S, int data){
    if(!isFull(*S)){
        S->arr[++S->Top] = data;
    }
}

void Pop(STACK *S){
    if(!isEmpty(*S)){
        S->Top--;
    }
}

int Top(STACK S){
    int temp = -1;
    if(!isEmpty(S)){
        temp = S.arr[S.Top];
    }
    return temp;
}


void printStack(STACK *S) { //2,2,3,5
    if (isEmpty(*S)) {
        printf("EMPTY\n");
    } else {
        STACK temp;
        initStack(&temp);  // Initialize the temp stack //top -1

        // Transfer elements from S to temp and print them
        while (!isEmpty(*S)) {
            int data = Top(*S);   // Get the top element //5, 3, 2
            printf("%d ", data);  // Print the top element //5, 3 , 
            Pop(S);               // Remove the element from S //2,2,
            Push(&temp, data);    // Push it onto the temp stack // 5, 3 
        }

     
        printf("\n");  // Newline after printing

        // Restore the original stack S
        while (!isEmpty(temp)) {
            Push(S, Top(temp));  // Push from temp back to S
            Pop(&temp);          // Pop from temp
        }
    }
}



void insertSorted(STACK *s, int data) {
    STACK temp;  
    initStack(&temp);            

    while (!isEmpty(*s) && Top(*s) > data) {
        Push(&temp, Top(*s)); // Push the popped element onto the temp stack
        Pop(s);               // Pop the top element from the original stack
    }

    // Now push the new data into the correct position in the original stack
    Push(s, data);

    // Restore the elements from the temporary stack back to the original stack
    while (!isEmpty(temp)) {
        Push(s, Top(temp));
        Pop(&temp);
    }
}


void sortStack(STACK *s, bool ascending) {
    STACK temp;
    initStack(&temp);

    while (!isEmpty(*s)) {
        int curr = Top(*s);
        Pop(s);

        while (!isEmpty(temp) &&
               ((ascending && Top(temp) > curr) ||
                (!ascending && Top(temp) < curr))) {
            Push(s, Top(temp));
            Pop(&temp);
        }

        Push(&temp, curr);
    }

    while (!isEmpty(temp)) {
        Push(s, Top(temp));
        Pop(&temp);
    }
}

void makeNull(STACK *S){
    S->Top = -1;
}

#endif