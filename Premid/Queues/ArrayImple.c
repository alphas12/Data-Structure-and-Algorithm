#include <stdio.h>

#define QUEUESIZE 10

typedef struct{
    int elem[QUEUESIZE];
    int front;
    int back;
} QUEUE;


typedef enum{TRUE, FALSE} boolean;

void initQueue(QUEUE *);
void enqueue(QUEUE *, int);
void dequeue(QUEUE *);
int isFull(QUEUE );
int isEmpty(QUEUE );
int front(QUEUE);
void insertFirst(QUEUE *, int );
void printQueue(QUEUE);

int main(){ 

    QUEUE arr;
    initQueue(&arr);
    enqueue(&arr, 5);
    enqueue(&arr, 10);
    enqueue(&arr, 15);
    enqueue(&arr, 20);
    enqueue(&arr, 1);
    enqueue(&arr, 3);
    enqueue(&arr, 2);
    enqueue(&arr, 4);
    // enqueue(&arr, 20);
    insertFirst(&arr, 6);
    printQueue(arr);
    return 0;
}

void initQueue(QUEUE* Q){ //the position for front and back can be anywhere as long as it is ahead by 1 cell
   Q->front = 0;
   Q->back = QUEUESIZE - 1;

}
void enqueue(QUEUE *Q, int data){
    if(!isFull(*Q)){
        Q->back = (Q->back + 1) % QUEUESIZE;
        Q->elem[Q->back] = data;
    }
}

void dequeue(QUEUE *Q){
    if(!isEmpty(*Q)){
        Q->front = (Q->front + 1) % QUEUESIZE;
    }
}
int isFull(QUEUE Q){
    return (Q.front == (Q.back + 2) % QUEUESIZE) ? 1 : 0; //relative position of front and rear by 2 cells
}

int isEmpty(QUEUE Q){
    return (Q.front == (Q.back + 1) % QUEUESIZE) ? 1 : 0; //1 cell
}

int front(QUEUE Q){
    return (isEmpty(Q)) ? -1 : Q.elem[Q.front];
}

void insertFirst(QUEUE *Q, int data){
    if(!isFull(*Q)){
        enqueue(Q, data);
        int temp = 0;
        int stop = Q->back % QUEUESIZE;
        while(stop != Q->front){
            temp = front(*Q);
            dequeue(Q);
            enqueue(Q, temp);
        }
    }
}

void printQueue(QUEUE Q){
    int stop = (Q.back + 1) % QUEUESIZE;
    while(stop != Q.front){
        printf("%d ", front(Q));
        enqueue(&Q, Q.elem[Q.front]);
        dequeue(&Q);
    }
}

