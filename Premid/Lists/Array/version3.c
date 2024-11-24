#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct{
    char *elem;
    int count;
} nodetype, LIST;

typedef int Position;

void initList(LIST *);
void insertAtPos(LIST *, char, Position);
void insertSorted(LIST *, char);
Position Locate(LIST, char);
void deleteAtPos(LIST *, Position);
void deleteAllOccur(LIST*, char);
char Retrieve(LIST, Position);
void printList(LIST);

int main(){
    LIST L;
    initList(&L);
    insertAtPos(&L, 'A', 0);
    insertAtPos(&L, 'B', 1);
    insertAtPos(&L, 'C', 2);
    insertAtPos(&L, 'D', 3);

    printList(L);

    int x = Locate(L, 'A');
    printf("Position of A: %d\n", x);
    return 0;
}

void initList(LIST *L){
    L->elem = (char *)malloc(sizeof(char) * SIZE);
    L->count = 0;
}

void insertAtPos(LIST* y, char x, Position P){
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

void deleteAtPos(LIST *L, Position P){
	int i;
	if(P < L->count && P != - 1){	//Position P has to be less than count and in some cases != -1 for it to be valid array Position
    for(i = P; i < L->count; i++){
	    L->elem[i] = L->elem[i + 1]; //curr = next;
    }
        L->count--;
    }
}



Position Locate (LIST L, char data){
	Position i;
	for(i = 0; i < L.count && data != L.elem[i]; i++){}
	return (i < L.count)? i : -1;
}

void printList(LIST L){
	int i;
	for(i = 0; i < L.count; i++){
        printf("%c ", L.elem[i]);
    }
}


void deleteAllOccur(LIST *L, char x){
	int i, y;
	for(i = 0; i < L->count; ){
		if(x == L->elem[i]){
			for(y = i; y < L->count - 1; y++){
				L->elem[y] = L->elem[y + 1];
			}
			L->count--;
		}else{
			i++;
		}
	}
}

char retrieve(LIST L, Position P){
	return (P != - 1 && P < L.count) ? L.elem[P]: '\0';
}


void insertSorted(LIST *L, char data){
	int x;
    if(L->count < SIZE){  
        for(x = L->count - 1; x >= 0 && data < L->elem[x]; x--){
	    L->elem[x + 1] = L->elem[x];
	}
}
    L->elem[x + 1] = data;
    L->count++;
}