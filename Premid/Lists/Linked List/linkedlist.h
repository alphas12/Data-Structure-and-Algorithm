#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
} nodetype, *LIST;

typedef enum {TRUE, FALSE} boolean;
void initList(LIST *L){
	*L = NULL;
};

void insertFirst(LIST *L, int x){
	LIST temp = (LIST)malloc(sizeof(nodetype));
    if(temp != NULL){
        temp->data = x;
	    temp->next = *L;
	    *L = temp;
    }
}

void insertLast(LIST *L, int y){
	LIST temp = (LIST)malloc(sizeof(nodetype));
	if(temp != NULL){
		LIST *trav = L;
		while(*trav != NULL){
			trav = &(*trav)->next;
		}
		temp->data = y;
		temp->next = NULL;
		*trav = temp;
	}
}

void deleteElem(LIST *L, int y){
	LIST *trav;
	for(trav = L; *trav != NULL && y != (*trav)->data; trav = &(*trav)->next) {}
	if(*trav != NULL){
		LIST temp = *trav;
		*trav = (*trav)->next;
		free(temp);
	}
}

LIST mergeLISTS(LIST A, LIST B) {
    LIST C = NULL;  // Initialize C to NULL
    LIST *travC = &C;  // Pointer to keep track of where to insert in C
    int lastInserted = -1;  // Keep track of the last inserted element (assume no negative elements in the list)

    while (A != NULL && B != NULL) {
        LIST temp = (LIST)malloc(sizeof(nodetype));
        if (temp != NULL) {
            if (A->data < B->data) {
                if (A->data != lastInserted) {  // Avoid duplicates
                    temp->data = A->data;
                    lastInserted = A->data;  // Update last inserted
                    A = A->next;
                } else {
                    A = A->next;  // Skip duplicate in A
                    free(temp);
                    continue;
                }
            } else {
                if (B->data != lastInserted) {  // Avoid duplicates
                    temp->data = B->data;
                    lastInserted = B->data;  // Update last inserted
                    B = B->next;
                } else {
                    B = B->next;  // Skip duplicate in B
                    free(temp);
                    continue;
                }
                if (A->data == B->data) {
                    A = A->next;  // Skip duplicate in A
                }
            }
            temp->next = NULL;
            *travC = temp;  // Attach temp to the current last node in C
            travC = &(*travC)->next;  // Move travC to the next pointer of temp
        }
    }

    // If one of the lists is not empty, add the remaining elements, skipping duplicates
    LIST finisher = (A != NULL) ? A : B;
    while (finisher != NULL) {
        if (finisher->data != lastInserted) {  // Avoid duplicates
            LIST temp = (LIST)malloc(sizeof(nodetype));
            if (temp != NULL) {
                temp->data = finisher->data;
                temp->next = NULL;
                *travC = temp;
                travC = &(*travC)->next;
                lastInserted = finisher->data;  // Update last inserted
            }
        }
        finisher = finisher->next;
    }

    return C;
}

void printList(LIST L){
	LIST curr = L;
	int arrow = 0;
	while(curr != NULL){
		if(arrow == 1){
			printf("->");
		}
		printf("%d", curr->data);
		curr = curr->next;
		arrow = 1;
	}
}

bool isMember(LIST L, int x){
    LIST trav;
    for(trav = L; trav->data != x && trav != NULL; trav = trav->next){}
    return (trav != NULL) ? true : false;
}
#endif