#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
typedef struct{
    int arr[SIZE];
    int count;
}LIST;

typedef int Position;


void initLIST(LIST *);
void insertAtPos(LIST *, char, Position);
void deleteAtPos(LIST *, Position);
void deleteAllOccur(LIST *, char );
Position Locate(LIST, char);
char retrieve(LIST, Position);
void insertSorted(LIST *, char);
void display(LIST);


int main(){
    
    LIST A;
    initLIST(&A);
	insertSorted(&A, 'A');
	insertSorted(&A, 'B');
	insertSorted(&A, 'C');
	insertSorted(&A, 'D');
	insertSorted(&A, 'E');
	insertSorted(&A, 'F');
	insertSorted(&A, 'G');

	
    return 0;
}

void initLIST(LIST * B){
    B->count = 0;
}

void insertAtPos(LIST *L, char y, Position P){
	if(L->count < SIZE){
		if(P <= L->count){
			int x;
			for(x = L->count; x > P; x--){
	            L->arr[x] = L->arr[x - 1];
            }
            L->arr[x] = y;
            L->count++;
		}
	}
}


void deleteAtPos(LIST *L, Position P){
	int i;
	if(P < L->count && P >= 0){	//Position P has to be less than count and in some cases != -1 for it to be valid array Position
        for(i = P; i < L->count; i++){
	        L->arr[i] = L->arr[i + 1]; //curr = next;
        }
	        --L->count;
    }
}

void deleteAllOccur(LIST *L, char x){ //1,1,2,2,4,4
	int i, y;
	for(i = 0; i < L->count; ){
		if(x == L->arr[i]){ //1 = 1
			for(y = i; y < L->count - 1; y++){
				L->arr[y] = L->arr[y+1];
			}
			L->count--;
		}else{
			i++;
		}
	}
}


Position Locate (LIST L, char data){
	Position i;
	for(i = 0; i < L.count && data != L.arr[i]; i++){}
	return (i < L.count)? i : -1;
}

char retrieve(LIST L, Position P){
	return (P != - 1 && P < L.count) ? L.arr[P]: '\0';
}


void insertSorted(LIST *L, char data){
	int x;
    if(L->count < SIZE){
        for(x = L->count - 1; x >= 0 && data < L->arr[x]; x--){
	        L->arr[x + 1] = L->arr[x];
        }
    }
        L->arr[x + 1] = data;
        L->count++;
}

void display(LIST L){
	int i;
	for(i = 0; i < L.count; i++){
        printf("%c ", L.arr[i]);
    }
}



