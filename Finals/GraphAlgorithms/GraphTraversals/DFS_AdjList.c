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

void initAdjList(AdjList []);
void setAdjList(AdjList[], Edgetype [], int);
void DFS(AdjList[], int, Boolean[]);

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
    Boolean mark[MAX];
    for(int u = 0; u < MAX; u++) {
        mark[u] = FALSE;
    }

    printf("DFS: ");
    DFS(A, 0, mark);

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

void DFS(AdjList A[], int start_vertex, Boolean mark[]){
    printf("%d ", start_vertex);

    mark[start_vertex] = TRUE;

    AdjList trav;
    for(trav = A[start_vertex]; trav != NULL; trav = trav->next){
        if(mark[trav->N.w] == FALSE){
            DFS(A, trav->N.w, mark);
        }
    }
}