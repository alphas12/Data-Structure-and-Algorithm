
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int *elem;
    int count;
} nodetype, *LIST;

// List initialization and utility functions
void initList(LIST *L);
int isEmpty(LIST L);
int isFull(LIST L);

// Core list operations
void insert(LIST *L, int elem);
void delete(LIST *L, int elem);
int locate(LIST L, int elem);

// Additional list operations
void display(LIST L);
LIST deleteAllOccur(LIST L, int x);

// Function implementations

void initList(LIST *L) {
    *L = (LIST)malloc(sizeof(nodetype));
    if (*L != NULL) {
        (*L)->elem = (int*)malloc(sizeof(int) * MAX);
        if ((*L)->elem != NULL) {
            (*L)->count = 0;
        } else {
            free(*L);
            *L = NULL;
        }
    }
}

int isEmpty(LIST L) {
    return (L == NULL || L->count == 0);
}

int isFull(LIST L) {
    return (L != NULL && L->count == MAX);
}

void insert(LIST *L, int elem) {
    if (*L != NULL && !isFull(*L)) {
        (*L)->elem[(*L)->count++] = elem;
    }
}

void delete(LIST *L, int elem) {
    if (*L != NULL) {
        int pos = locate(*L, elem);
        if (pos != -1) {
            for (int i = pos; i < (*L)->count - 1; i++) {
                (*L)->elem[i] = (*L)->elem[i + 1];
            }
            (*L)->count--;
        }
    }
}

int locate(LIST L, int elem) {
    if (L != NULL) {
        for (int i = 0; i < L->count; i++) {
            if (L->elem[i] == elem) {
                return i;
            }
        }
    }
    return -1;
}

void display(LIST L) {
    if (L == NULL || isEmpty(L)) {
        printf("EMPTY LIST\n");
    } else {
        for (int i = 0; i < L->count; i++) {
            printf("%d ", L->elem[i]);
        }
        printf("\n");
    }
}

LIST deleteAllOccur(LIST L, int x) {
    LIST temp;
    initList(&temp);
    if (L != NULL) {
        for (int i = 0; i < L->count; i++) {
            if (L->elem[i] != x) {
                insert(&temp, L->elem[i]);
            }
        }
    }
    return temp;
}

// Don't forget to add this function to free the allocated memory
void freeList(LIST *L) {
    if (*L != NULL) {
        if ((*L)->elem != NULL) {
            free((*L)->elem);
        }
        free(*L);
        *L = NULL;
    }
}

