#include <stdio.h>
#include <stdlib.h>

#define MAX 7

typedef int AdjMatrix[MAX][MAX];

typedef enum{FALSE, TRUE}Boolean;

typedef struct{
    int u;
    int w;
}Edgetype;

typedef struct node{
    Edgetype N;
    struct node *next;
}*AdjList;

typedef struct{
    int elem[MAX];
    int front;
    int rear;
} QUEUE;

void initAdjList(AdjList []);
void setAdjList(AdjList[], Edgetype [], int);
void BreadthFirstSearch(AdjList[], int);

int main(){
    Edgetype arr[] = {{0, 1}, {0, 3}, {0, 2},
                       {1, 0}, {1, 2}, {1, 3}, {1, 5},
                       {2, 0}, {2, 1}, {2, 3}, 
                       {3, 0}, {3, 1}, {3, 2}, {3, 6},
                       {4, 5}, {4, 6},
                       {5, 4}, {5, 1}, {5,6},
                       {6, 4}, {6, 5}, {6, 3}
    };

    int size = sizeof(arr)/sizeof(arr[0]);

    AdjList A[MAX];
    initAdjList(A);
    setAdjList(A, arr, size);
    BreadthFirstSearch(A, 2);

    return 0;
}

void initAdjList(AdjList A[]){
    int i;
    for(i = 0; i < MAX; i++){
        A[i] = NULL;
    }
}

void setAdjList(AdjList A[],Edgetype arr[], int size){
    int i;
    AdjList *trav;
    for(i = 0; i < size; i++){
        trav = &(A[arr[i].u]);
        AdjList temp = (AdjList)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->N.u = arr[i].u;
            temp->N.w = arr[i].w;
            temp->next = NULL;
            while(*trav != NULL){
                trav = &(*trav)->next;
            }
            *trav = temp;
        }
    }
}

void BreadthFirstSearch(AdjList A[], int v) {  // Changed to receive array of AdjList
    QUEUE Q;    
    Q.front = 0;
    Q.rear = MAX - 1;
    int x;
    AdjList trav;  // For traversing the adjacency list

    // Set initialize components to false
    Boolean mark[MAX];
    for(int u = 0; u < MAX; u++) {
        mark[u] = FALSE;
    }

    mark[v] = TRUE;

    // Enqueue starting vertex
    if(Q.front != (Q.rear + 2) % MAX){
        Q.rear = (Q.rear + 1) % MAX;
        Q.elem[Q.rear] = v;
    }

    Edgetype T[MAX];
    int T_count = 0;

    while(Q.front != (Q.rear + 1) % MAX) {  // While queue is not empty
        // Dequeue
        x = Q.elem[Q.front];
        Q.front = (Q.front + 1) % MAX;
        
        // Traverse adjacency list of vertex x
        trav = A[x];
        while(trav != NULL) {
            int y = trav->N.w;  // Get adjacent vertex
            if(mark[y] == FALSE) {
                mark[y] = TRUE;
                printf("%d ", y);
                // Enqueue if queue is not full
                    Q.rear = (Q.rear + 1) % MAX;
                    Q.elem[Q.rear] = y;


                    T[T_count].u = x;
                    T[T_count].w = y;
                    T_count++;
            }
            trav = trav->next;
        }
    }

    // Print BFS tree edges
    printf("\nBFS Tree Edges: ");
    for(int i = 0; i < T_count; i++) {
        printf("(%d,%d) ", T[i].u, T[i].w);
    }
    printf("\n");
}



