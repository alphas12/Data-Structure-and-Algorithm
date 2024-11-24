#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
} *STACK;


void initStack(STACK *S){
    *S = NULL;  
}

bool isEmpty(STACK S){
    return (S == NULL) ? true : false;
}

void Push(STACK *S, int data){
    STACK new_node = (STACK)malloc(sizeof(struct node));
    if(new_node != NULL){
        new_node->data = data;
        new_node->next = *S;
        *S = new_node;
    }
}

void Pop(STACK *S){
    if(!isEmpty(*S)){
        STACK temp = *S;
        *S = (*S)->next;
        free(temp);
    }
}

int Top(STACK S){
    return (isEmpty(S) == true) ? -1 : S->data;
}

void makeNull(STACK *S){
    while(!isEmpty(*S)){
        Pop(S);
    }
}

void insertBottom(STACK *S, int data){ //1,2,3,4 <- top
    
    STACK temp, new;
    initStack(&new);

    while(*S != NULL){
        temp = *S;
        *S = temp->next;
        temp->next = new;
        new = temp;
    }
    
    temp = (STACK)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = data;
        temp->next = *S;
        *S = temp;
        while(new != NULL){
            temp = new;
            new = temp->next;
            temp->next = *S;
            *S = temp;
        }
    }

}

void printStack(STACK S){
    while(S != NULL){
        printf("%d ", S->data);
        S = S->next;
    }
}


void insertSorted(STACK *S, int data){
    STACK temp, newStack;
    initStack(&new);
    
    while(*S != NULL){
        temp = *S;
        *S = temp->next;
        temp->next = new;
        new = temp;
    }

    temp = (STACK)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->data = data;
        temp->next = *S;
        *S = temp;
        while(new != NULL){
            temp = new;
            new = temp->next;
            temp->next = *S;
            *S = temp;
        }
    }
}

void reverseStack(STACK *s){
    STACK temp, newStack;
    initStack(&newStack);

    while(*s != NULL){
        temp = *s;
        *s = temp->next;

        //insertFirst
        temp->next = newStack;
        newStack = temp;
    }

      while(newStack != NULL){
        temp = *s;
        *s = temp->next;

        //insertFirst
        temp->next = newStack;
        newStack = temp;
    }
}

int getSecondLargest(STACK stack) {
  STACK dummySecondLargest = NULL;
  STACK dummyStack = NULL;
  
  int secondLargestCount = 0;
  int limit = 2;
  
  while (stack != NULL) {
    STACK *next = &(stack->next);
    
    stack->next = dummyStack;
    dummyStack = stack;
    
    int topStack = Top(stack);
    
    if (topStack > Top(dummySecondLargest) || secondLargestCount < limit) {
      insertSorted(&dummySecondLargest, topStack);
      secondLargestCount++;
      
      if (secondLargestCount > limit) {
        Pop(&dummySecondLargest);
      }
    }
    
    stack = *next;
  }
  
  while (dummyStack != NULL) {
    STACK *next = &(dummyStack->next);
    
    dummyStack->next = stack;
    stack = dummyStack;
    
    dummyStack = *next;
  }
  
  int secondLargest = Top(dummySecondLargest);
  
  while (dummySecondLargest != NULL) {
    Pop(&dummySecondLargest);
  }
  
  return secondLargest;
}
#endif