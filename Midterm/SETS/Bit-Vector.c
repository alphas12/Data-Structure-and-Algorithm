#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 0XA

typedef int SET[SIZE];

void initSet(SET);
SET *Union(SET, SET);
SET *Difference(SET, SET);
SET *Intersection(SET, SET);
SET *SymmetricSetDifference(SET, SET);

int main(){
    
    SET B = {0,1,0,1,0,1,1,0};
    SET C = {1,1,1,0,1,1,0,1};
    SET *A = Union(B, C);
    printf("Union of B and C: \n");
    for(int i = 0; i < SIZE; i++){
        printf("Index %d: %d ", i, (*A)[i]);
        printf("\n");
    }

    printf("\n");

    SET *D = Difference(B,C);
    printf("\nDifference of B and C: \n");
    for(int i = 0; i < SIZE; i++){
        printf("Index %d: %d ", i, (*D)[i]);
         printf("\n");
    }

    SET *E = Intersection(B,C);
    printf("\nIntersection of B and C: \n");
    for(int i = 0; i < SIZE; i++){
        printf("Index %d: %d", i, (*E)[i]);
         printf("\n");
    }

    SET *F = SymmetricSetDifference(B,C);
    printf("\nSymmetric Difference of B and C: \n");
    for(int i = 0; i < SIZE; i++){
        printf("Index %d: %d", i, (*F)[i]);
         printf("\n");
    }
    
     printf("\n");

    return 0;
}

void initSet(SET A){
    memset(A, 0, sizeof(int) * SIZE);
}

SET *Union(SET A, SET B){
    SET* C = (SET *)malloc(sizeof(SET));

    int i;
    for(i = 0; i < SIZE; i++){
        (*C)[i] = A[i] || B[i];
    }

  return C; 
}


SET *Intersection(SET A, SET B){
    SET *C = (SET *)malloc(sizeof(SET));
    
    int i;
    for(i = 0; i < SIZE; i++){
        (*C)[i] = A[i] && B[i];
    }
    return C;
}

SET *Difference(SET A, SET B){
    SET *C = (SET *)malloc(sizeof(SET));

    int i;
    for(i = 0; i < SIZE; i++){
        (*C)[i] = A[i] && !B[i];
    }
    return C;
}

SET * SymmetricSetDifference(SET A, SET B){
    SET *C = (SET *)malloc(sizeof(SET));
    
    int i;
    for(i = 0; i < SIZE; i++){
        (*C)[i] = A[i] ^ B[i];
    }
    return C;
}
