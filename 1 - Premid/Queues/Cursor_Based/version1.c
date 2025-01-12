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
int front(Vheap, QUEUE);
boolean isFull(Vheap);
boolean isEmpty(QUEUE);

int main(){
    Vheap VH;
    QUEUE q;
    initVH(&VH);
    initList(&q);

    Enqueue(&VH, &q, 5);
    Enqueue(&VH, &q, 10);
    Enqueue(&VH, &q, 15);
    printQueue(&VH, &q);

    
    

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
        // set the value of the node
        VH->Nodes[y].elem = val;
        // set the next node of the node to -1
        VH->Nodes[y].next = -1;
        // if the queue is not empty, set the next node of the rear node to y
        if(Q->front != -1){
            VH->Nodes[Q->rear].next = y;
        } else {
            // set the front of the queue to y
            Q->front = y;
        }
        // set the rear of the queue to y
        Q->rear = y;
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

int front(Vheap VH, QUEUE Q){
    return (!isEmpty(Q)) ? VH.Nodes[Q.front].elem : -1;
}

void printQueue(Vheap *Vheap, QUEUE *Q){
    if(!isEmpty(*Q)){
        QUEUE temp;
        initQueue(&temp);

        while(!isEmpty(*Q)){
            int val = front(*Vheap, *Q);
            printf("%d ", val);
            Enqueue(Vheap, &temp, val);
            Dequeue(Vheap, Q);
        }
        printf("\n");

        *Q = temp;
    }
}