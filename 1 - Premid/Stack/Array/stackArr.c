#include <stdio.h>
#include "stackArr.h"

int main(){
    STACK S;
    initStack(&S);
    Push(&S, 1);
    Push(&S, 2);
    Push(&S, 5);
    Push(&S, 3);
    insertSorted(&S, 4);

    printStack(&S);
    sortStack(&S, true);
    printStack(&S);
    return 0;
}
