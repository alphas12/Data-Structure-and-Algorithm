#include <stdio.h>
#include "linkedlist.h"

int main(){
    LIST A;
    LIST B;

    initList(&A);
    initList(&B);
    insertLast(&A, 5);
    insertLast(&A, 8);
    insertLast(&A, 8);
    insertLast(&A, 10);
    insertLast(&A, 12);
    insertLast(&A, 15);

    insertLast(&B, 1);
    insertLast(&B, 2);
    insertLast(&B, 4);
    insertLast(&B, 6);
    insertLast(&B, 7);
    insertLast(&B, 8);

    printf("A:");
    printList(A);
    printf("\n");
    printf("B:");
    printList(B);

    LIST C = mergeLISTS(A, B);
    printf("\nMerged C: ");
    printList(C);
    printf("\n");
    return 0;
}