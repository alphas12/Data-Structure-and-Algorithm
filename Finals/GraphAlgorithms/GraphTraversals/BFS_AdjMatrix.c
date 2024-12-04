#include <stdio.h>
#include <stdlib.h>

#define MAX 7

typedef int AdjMatrix[MAX][MAX];

typedef enum{FALSE, TRUE}Boolean;

typedef struct{
    int u;
    int w;
}Edgetype;

typedef struct{
    int elem[MAX];
    int front;
    int rear;
} QUEUE;

void initAdjMatrix(AdjMatrix);
void setAdjMatrix(AdjMatrix, Edgetype [], int);
void BFS(AdjMatrix, int);

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

    AdjMatrix A;
    initAdjMatrix(A);
    setAdjMatrix(A, arr, size);

    BFS(A, 0);

    return 0;
}

void initAdjMatrix(AdjMatrix M){
    int i, j;
    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            M[i][j] = 0;
        }
    }
}

void setAdjMatrix(AdjMatrix M,Edgetype arr[], int size){
   int i;
   for(i = 0; i < size; i++){
        M[arr[i].u][arr[i].w] = 1;
        M[arr[i].u][arr[i].w] = 1;
   }
}



void BFS(AdjMatrix M, int v){ 
    QUEUE Q;    
    Q.front = 0;
    Q.rear = MAX - 1;
    int curr;
    // Set initialize components to false
    Boolean mark[MAX];
    for(int u = 0; u < MAX; u++) {
        mark[u] = FALSE;
    }

    mark[v] = TRUE;
    printf("%d", v);

    // Enqueue starting vertex
    if(Q.front != (Q.rear + 2) % MAX){
        Q.rear = (Q.rear + 1) % MAX;
        Q.elem[Q.rear] = v;
    }

    Edgetype T[MAX];
    int T_count = 0;

    while(Q.front != (Q.rear + 1) % MAX) { 
        // Dequeue
        curr = Q.elem[Q.front];
        Q.front = (Q.front + 1) % MAX;
        
        // Traverse adjacency list of vertex x
        int x;
        for(x = 0; x < MAX; x++) {
            if(M[curr][x] != 0 && mark[x] == FALSE) {
                mark[x] = TRUE;
                printf("%d ", x);
                // Enqueue if queue is not full
                    Q.rear = (Q.rear + 1) % MAX;
                    Q.elem[Q.rear] = x;


                    T[T_count].u = curr;
                    T[T_count].w = x;
                    T_count++;
            }
        }
    }

    // Print BFS tree edges
    printf("\nBFS Tree Edges: ");
    for(int i = 0; i < T_count; i++) {
        printf("(%d,%d) ", T[i].u, T[i].w);
    }
    printf("\n");
}


