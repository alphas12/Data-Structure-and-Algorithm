#include <stdio.h>
#include <stdlib.h>

#define MAX 7

typedef int AdjMatrix[MAX][MAX];
typedef enum{FALSE, TRUE}Boolean;

typedef struct{
    int u;
    int w;
}Edgetype;


void initAdjMatrix(AdjMatrix);
void setAdjMatrix(AdjMatrix, Edgetype [], int);
void DFS(AdjMatrix, int, Boolean[]);
void displayMatrix(AdjMatrix);

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
    Boolean mark[MAX];
    for(int u = 0; u < MAX; u++) {
        mark[u] = FALSE;
    }

    displayMatrix(A);

    printf("DFS: ");
    DFS(A, 0, mark);

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


void DFS(AdjMatrix M, int start_vertex, Boolean mark[]){
    printf("%d ", start_vertex);

    mark[start_vertex] = TRUE;

    int x;
    for(x = 0; x < MAX; x++){
        if(M[start_vertex][x] != 0 && mark[x] == FALSE){
            DFS(M, x, mark);
        }
    }
}

void displayMatrix(AdjMatrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}