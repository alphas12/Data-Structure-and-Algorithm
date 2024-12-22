// #include "stackArr.h"
#include "stackLinkedList.h"
#include <stdio.h>

int main(){
    STACK S;
    initStack(&S);
    Push(&S, 1);
    Push(&S, 2);
    Push(&S, 3);

    Pop(&S);
    Pop(&S);
    Pop(&S);
    
    
    printStack(S);
    return 0;
}


