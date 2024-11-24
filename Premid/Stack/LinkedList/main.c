
#include "stackLinkedList.h"
#include <stdio.h>

int main(){
    STACK S;
    initStack(&S);
    Push(&S, 1);
    Push(&S, 2);
    Push(&S, 3);
    insertBottom(&S, 4);
    printStack(S);

    reverseStack(&S);
    
    printStack(S);
    printf("%d", getSecondLargest(S));
    return 0;
}

