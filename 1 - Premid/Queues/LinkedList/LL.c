#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} nodetype, *LIST;

typedef struct{
    LIST front;
    LIST rear;
} QUEUE;



void initQueue(QUEUE *);
void Enqueue(QUEUE *, int);
void Dequeue(QUEUE *);
bool isEmpty(QUEUE);
void printQueue(QUEUE*);
int front(QUEUE);
bool isAscending(QUEUE);

int main(){

    QUEUE q;
    initQueue(&q);
    Enqueue(&q, 5);
    Enqueue(&q, 10);
    Enqueue(&q, 15);
    printQueue(&q);
    printf("%d", isAscending(q));
    return 0;
}

void initQueue(QUEUE *q){
    q->front = NULL;
    q->rear = NULL;
}

void Enqueue(QUEUE *Q, int x){ //2 elems, 1 elems, 0 elem
    LIST temp = (LIST)malloc (sizeof(struct node));

    if(temp != NULL){
        temp->data = x;
        temp->next = NULL;
        if(Q->front != NULL){
            Q->rear->next = temp;
        } else {
            Q->front = temp;
        }
        Q->rear = temp;
    }
}


void Dequeue(QUEUE *q){
    if(!isEmpty(*q)){
        LIST temp = q->front;
        if(temp != NULL){
            q->front = temp->next;
            if(isEmpty(*q)){
                q->rear = NULL;
            }
        }
        free(temp);
    }
}

bool isEmpty(QUEUE Q){
    return(Q.front == NULL) ? true : false;
}

int front(QUEUE Q){
    return (!isEmpty(Q))? Q.front->data : -1;
}
 //no traverse

void printQueue(QUEUE *Q){
    if(isEmpty(*Q)){
        printf("Queue is empty.\n");
        
    } else {
        QUEUE tempQueue;
        initQueue(&tempQueue);

         printf("Queue: ");
    
        while (!isEmpty(*Q)){
        int val = front(*Q);      
        printf("%d ", val);      
        Enqueue(&tempQueue, val); 
        Dequeue(Q);               
         }
         printf("\n");

  
        *Q = tempQueue;
    }
    
}


bool isAscending(QUEUE Q){
   int val = -1;
   LIST temp = Q.front;
   while(temp != NULL && val <= temp->data){ ///
        val = temp->data;
        temp = temp->next;
   }

   return(temp == NULL)? true : false;
}
