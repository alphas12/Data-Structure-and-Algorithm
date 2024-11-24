#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 8

typedef char vertexType; //A, B, C, D, E, F, G, H, I
typedef int labelType; //weight of edge

typedef struct {
    vertexType head;
    vertexType tail; 
} edgeType;

typedef struct {
    int edges[MAX_VERTEX][MAX_VERTEX];
    int numEdges;
}dirAdjMatrix; //version 1

typedef struct node{
    vertexType info;
    struct node *next;
}*adjList;

typedef struct{
    adjList adj[MAX_VERTEX];
    int numEdges;
}dirAdjList;


void initMatrix(dirAdjMatrix*);
void dirAjdM(dirAdjMatrix*, edgeType[], int);
void printMatrix(dirAdjMatrix);
void convertAdjMatrixtoList(dirAdjMatrix, dirAdjList*);
void initAdjList(dirAdjList*);
void printAdjList(dirAdjList);
int main(){
    dirAdjMatrix M;
    dirAdjList L;

    edgeType arr[] = {{'A', 'B'}, {'B', 'C'}, {'C', 'D'}, {'D', 'E'}, {'E', 'F'}, {'F', 'G'}, {'G', 'H'}, {'C', 'B'}, {'D', 'G'}, {'E', 'H'}, {'F', 'A'}};
    int size = sizeof(arr) / sizeof(arr[0]);

    initMatrix(&M);

    dirAjdM(&M, arr, size);
    printMatrix(M);

    initAdjList(&L);
    convertAdjMatrixtoList(M, &L);
    printAdjList(L);
   
 
    return 0;
}

void initMatrix(dirAdjMatrix* Mat){
    Mat->numEdges = 0;
    int i, j;
    for(i = 0; i < MAX_VERTEX; i++){
        for(j = 0; j < MAX_VERTEX; j++){
            Mat->edges[i][j] = 0;
        }
    }
}

void initAdjList(dirAdjList* List){
    List->numEdges = 0;
    int i;
    for(i = 0; i < MAX_VERTEX; i++){
        List->adj[i] = NULL;
    }
}


void dirAjdM(dirAdjMatrix* Mat, edgeType arr[], int size){
    int i;
    for(i = 0; i < size; i++){
        Mat->edges[arr[i].tail - 'A'][arr[i].head - 'A'] = 1;
        Mat->numEdges++;
    }
}

void printMatrix(dirAdjMatrix Mat){
    int i, j;
    char value = 'A';
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < MAX_VERTEX; i++){
        printf("%c ", value++);
        for(j = 0; j < MAX_VERTEX; j++){
            printf("%d ", Mat.edges[i][j]);
        }
        printf("\n");
    }
}


void convertAdjMatrixtoList(dirAdjMatrix M, dirAdjList* L){
    int i, j;
    adjList *trav;
    for(i = 0; i < MAX_VERTEX; i++){
        trav = &(L->adj[i]);
        for(j = 0; j < MAX_VERTEX; j++){
            if(M.edges[i][j] == 1){
                adjList temp = (adjList)malloc(sizeof(struct node));
                if(temp != NULL){
                    temp->info = j + 'A'; // if it is in B to C, it will be 'B'. so index 1 + 'A' = 'B'
                    temp->next = NULL;
                    while(*trav != NULL){
                        trav = &(*trav)->next;
                    }
                    *trav = temp;
                    L->numEdges++;
                }         
            }
        }
    }
}


void printAdjList(dirAdjList L){
    adjList *trav;
    int x;
    char value = 'A';
    printf("\nAdjacency List:\n");
    for(x = 0; x < MAX_VERTEX; x++){
        trav = &(L.adj[x]);
        printf("%c: ", value++);
        while(*trav != NULL){
            printf("%c", (*trav)->info);
            trav = &(*trav)->next;
            if(*trav != NULL){
                printf("->");
            }
        }
        printf("\n");
    }      
}