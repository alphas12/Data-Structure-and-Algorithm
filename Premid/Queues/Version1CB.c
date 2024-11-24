#include <stdio.h>
#define SIZE 10

typedef struct{
    int elem;
    int next;
} Nodetype;

typedef struct{
    Nodetype Nodes[SIZE];
    int Avail;
}Vheap;

typedef struct{
    int front;
    int rear;
}QUEUE;

typedef enum { TRUE, FALSE} boolean;

int allocSpace(Vheap *);
void deallocSpace(Vheap *, int);
void initQueue(QUEUE *);
void initVH(Vheap *);
void Enqueue(Vheap *, QUEUE *, int);
void Dequeue(Vheap *, QUEUE *);
boolean isFull(Vheap);
boolean isEmpty(QUEUE);

int main(){
    Vheap VH;
    QUEUE q;
    initVH(&VH);
    initList(&q);
    
    

    return 0;
}


int allocSpace(Vheap *VH){
    int result = VH->Avail;
    if(result != -1){
        VH->Avail = VH->Nodes[result].next;
    }
    return result;
}

void deallocSpace(Vheap *VH, int idx){
    if(idx >= 0 && idx < SIZE){
        VH->Nodes[idx].next = VH->Avail;
		VH->Avail = idx;
    }
}

void initQueue(QUEUE *Q){
    Q->front = -1;
    Q->rear = -1;
}

void initVH(Vheap *VH){
    int i;
    VH->Avail = 0;
    for(i = 0; i < SIZE - 1; i++){
        VH->Nodes[i].next = i + 1;
    }
    VH->Nodes[i].next = -1;
}

void Enqueue(Vheap * VH, QUEUE *Q, int val){
    int y = allocSpace(VH);
    if(y != 1){
        VH->Nodes[y].elem = val;
        VH->Nodes[y].next = -1;
        if(Q->front != -1){
            VH->Nodes[Q->rear].next = y; //q->rear->next = y
        }else{
            Q->front = y; //q->front = y
        }
        Q->rear = y; //q->rear = y
    }
}

void Dequeue(Vheap *VH, QUEUE *Q){
    if(Q->front != -1){
        int y = Q->front;
        Q->front = VH->Nodes[y].next;
        deallocSpace(VH, y);
    }
}

boolean isFull(Vheap VH){
    return(VH.Avail == -1) ? TRUE : FALSE;
}

boolean isEmpty(QUEUE Q){
    return(Q.front == -1) ? TRUE : FALSE;
}

int front

void printQueue(Vheap *Vheap, QUEUE *Q){
    if(!isEmpty(*Q)){
        QUEUE temp;
        initQueue(&temp);

        while(!isEmpty(*Q)){
            printf("%d", )
        }
    }
}