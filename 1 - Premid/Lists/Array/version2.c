#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct{
    char elem[SIZE];
    int count;
} nodetype, *LIST;

typedef int Position;

void initLIST(LIST *);
void deleteAtPos(LIST , Position);
void insertFirst(LIST, char);
void insertAtPos(LIST, char, Position);
void deleteAllOccur(LIST, char x);
Position Locate(LIST, char);
void insertSorted(LIST, char);
void printList(LIST);

int main(){
    LIST L = NULL;
    initLIST(&L);
    insertFirst(L, 'A');
    insertFirst(L, 'B');
    insertFirst(L, 'C');
    insertSorted(L, 'S');
    printList(L);
    return 0;
}

void initLIST(LIST *L){
    *L = (LIST)malloc(sizeof(nodetype));
    (*L)->count = 0;
}

void insertFirst(LIST L, char data){
    if(L->count == SIZE){
        printf("LIST is full\n");
    } else{
        L->elem[L->count] = data;
        L->count++;
    }
}

void insertAtPos(LIST y, char x, Position P){
   if(y->count < SIZE){
        if(P <= y->count){
            int a;
            for(a = y->count; a > P; a--){
                y->elem[a] = y->elem[a-1];
            }
            y->elem[P] = x;
            y->count++;
        }
   }
}
void deleteAtPos(LIST L, Position P){
	int i;
	if(P < L->count && P != - 1){	//Position P has to be less than count and in some cases != -1 for it to be valid array Position
        for(i = P; i < L->count; i++){
	        L->elem[i] = L->elem[i + 1]; //curr = next;
        }
            L->count--;
    }
}

void deleteAllOccur(LIST L, char x){
	int i, y;
	for(i = 0; i < L->count; ){
		if(x == L->elem[i]){
			for(y = i; y < L->count - 1; y++){
				L->elem[y] = L->elem[y+1];
			}
			L->count--;
		}else{
			i++;
		}
	}
}

Position Locate (LIST L, char data){
	Position i;
	for(i = 0; i < L->count && data != L->elem[i]; i++){}
	return (i < L->count)? i : -1;

}

char retrieve(LIST L, Position P){
	return (P != - 1 && P < L->count) ? L->elem[P]: '\0';
}

void insertSorted(LIST L, char data){
	int x;
    if(L->count < SIZE){
        for(x = L->count - 1; x >= 0 && data < L->elem[x]; x--){
	    L->elem[x + 1] = L->elem[x];
	}
}
    L->elem[x + 1] = data;
    L->count++;
}

void printList(LIST L){
    int i;
    for(i = 0; i < L->count; i++){
        printf("%c ", L->elem[i]);
    }
}
