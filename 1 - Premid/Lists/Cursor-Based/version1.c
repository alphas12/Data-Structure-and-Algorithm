#include <stdio.h>
#define SIZE 10

typedef struct node{
    int data;
    int next;
}Nodetype;

typedef struct{
    Nodetype Nodes[SIZE];
    int Avail;
}VHeap;

typedef int LIST;	
typedef enum {TRUE, FALSE} boolean;

int allocSpace(VHeap *);
void deallocSpace(VHeap *, int);
void initList(LIST *);
void initVirtualHeap(VHeap *);
void insertFirst(VHeap *, LIST *, int);
void insertLast(VHeap *, LIST *, int);
void insertSorted(VHeap *, LIST *, int);
void deleteElem(VHeap *, LIST *, int);
void deleteAllOccur(VHeap *, LIST *, int);
void printList(VHeap , LIST);
boolean isEqualList(VHeap, LIST, LIST);

int main(){
    LIST L;
    VHeap H;   
    initList(&L);
    initVirtualHeap(&H);
    insertFirst(&H, &L, 6);
    insertFirst(&H, &L, 5);
    insertLast(&H, &L, 10);
    insertSorted(&H, &L, 8);
    insertLast(&H, &L, 10);
    insertLast(&H, &L, 14);
    insertLast(&H, &L, 10);
    printList(H, L);
    deleteElem(&H, &L, 10);
    deleteAllOccur(&H, &L, 10);
    printList(H, L);

    LIST M;
    initList(&M);
    insertFirst(&H, &M, 12);
    insertFirst(&H, &M, 8);
    insertFirst(&H, &M, 6);
    insertFirst(&H, &M, 5);
    printList(H, M);

    if(isEqualList(H, L, M)){
        printf("TRUE");
    }else{
        printf("FALSE");
    }

    return 0;
}


boolean isEqualList(VHeap VH, LIST L, LIST M){ //sorted
	LIST trav, trav2;
	for(trav = L, trav2 = M; trav != -1 && trav2 != -1 && VH.Nodes[trav].data == VH.Nodes[trav2].data; trav = VH.Nodes[trav].next, trav2 = VH.Nodes[trav2].next){}
	
	return(trav == -1 && trav2 == -1) ? TRUE : FALSE;
}


// boolean isEqualList(VHeap VH, LIST L, LIST M){//unsorted
//     LIST trav, trav2, isEqual = 1;
//     for(trav = L; trav != -1 && isEqual == 1; trav = VH.Nodes[trav].next){
//         for(trav2 = M; trav2 != -1 && VH.Nodes[trav].data != VH.Nodes[trav2].data; trav2 = VH.Nodes[trav2].next){}
//             if(trav2 == -1) isEqual == 0;
// 	}
//     return(isEqual == 1) ? TRUE : FALSE;
// }



void initVirtualHeap(VHeap * VH){
    int i;
    VH->Avail = 0;
    for(i = 0; i < SIZE - 1; i++){
        VH->Nodes[i].next = i + 1;
    }
    VH->Nodes[i].next = -1;
}

int allocSpace (VHeap *VH){
	int result = VH->Avail; //0
	if(result != -1){
        VH->Avail = VH->Nodes[result].next; //1
	}
	return result; //0
}

void deallocSpace(VHeap *VH, int idx){
	if(idx >= 0 && idx < SIZE){
		VH->Nodes[idx].next = VH->Avail;
		VH->Avail = idx;
    }
}

void initList(LIST *L){
    *L = -1;
}

void insertFirst(VHeap *VH, LIST *L, int x){
	int y = allocSpace(VH); //0
    if(y != - 1){
        VH->Nodes[y].data = x;
	    VH->Nodes[y].next = *L;
	    *L = y;//0
    }
}



// void insertFirst(LIST *L, int x){
// 	LIST temp = (LIST)malloc(sizeof(nodetype));
//     if(temp != NULL){
//         temp->data = x;
// 	    temp->next = *L;
// 	    *L = temp;
//     }
// }

void insertLast(VHeap *VH, LIST *L, int x){
	int y = allocSpace(VH);
    
    if(y != - 1){
		LIST *trav;
		for(trav = L; *trav != -1; trav = &(VH->Nodes[*trav].next)){}
		VH->Nodes[y].data = x;
		VH->Nodes[y].next = -1;
		*trav = y;
	}	
}


void insertSorted(VHeap *VH, LIST *L, int x){
	int y = allocSpace(VH);
	if(y != -1){
		LIST *trav;
		for(trav = L; *trav != -1 && VH->Nodes[*trav].data < x; trav = &(VH->Nodes[*trav].next)){}
		VH->Nodes[y].data = x;
		VH->Nodes[y].next = *trav;
		*trav = y;
	}
}

void printList(VHeap VH, LIST L){
    LIST trav;
    printf("DATA\t NEXT\n");
    for(trav = L; trav != -1; trav = VH.Nodes[trav].next){
        printf("%d: %d\t%d\n", trav, VH.Nodes[trav].data, VH.Nodes[trav].next);
    }
    printf("%d\n", L);
}

void deleteElem(VHeap *VH, LIST *L, int x){
	LIST *trav;
	for(trav = L; *trav != -1 && VH->Nodes[*trav].data != x; trav = &(VH->Nodes[*trav].next)){}

	if(*trav != -1){
		LIST temp = *trav;
		*trav = VH->Nodes[temp].next;
		deallocSpace(VH, temp);
    }	
}

void deleteAllOccur(VHeap *VH, LIST *L, int x){
	LIST *trav;

    for(trav = L; *trav != -1; ){
		if(VH->Nodes[*trav].data == x){
		LIST temp = *trav;//considered as the index to be deleted
			*trav = VH->Nodes[temp].next;
			deallocSpace(VH, temp);
        } else {    
        trav = &VH->Nodes[*trav].next;
        }
    }
}


