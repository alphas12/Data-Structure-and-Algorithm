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


void initAdjList(dirAdjList* List);
void initMatrix(dirAdjMatrix* Mat);
void dirAdjL(dirAdjList* List, edgeType arr[], int size);
void convertAdjLtoM(dirAdjList L, dirAdjMatrix* Mat);
void printAdjList(dirAdjList L);
void printMatrix(dirAdjMatrix Mat);


int main(){
    dirAdjList L;
    initAdjList(&L);

    edgeType arr[] = {{'A', 'B'}, {'E', 'D'}, {'B', 'C'}, {'C', 'D'}, {'D', 'E'}, {'E', 'F'}, {'F', 'G'}, {'G', 'H'}, {'C', 'B'}, {'D', 'G'}, {'E', 'H'}, {'F', 'A'}};
    int size = sizeof(arr) / sizeof(arr[0]);

    dirAdjL(&L, arr, size);
    printAdjList(L);

    dirAdjMatrix M;
    initMatrix(&M);
    convertAdjLtoM(L, &M);
    printMatrix(M);

    return 0;
}

void initAdjList(dirAdjList* List){
    List->numEdges = 0;
    int i;
    for(i = 0; i < MAX_VERTEX; i++){
        List->adj[i] = NULL;
    }
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

void dirAdjL(dirAdjList* List, edgeType arr[], int size){
    int i;
    for(i = 0; i < size; i++){
        adjList *trav = &(List->adj[arr[i].tail - 'A']);
        adjList temp = (adjList)malloc(sizeof(struct node));
        if(temp != NULL){
            temp->info = arr[i].head;
            temp->next = NULL;
            while(*trav != NULL){
                trav = &(*trav)->next;
            }
            *trav = temp;
            List->numEdges++;
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


void convertAdjLtoM(dirAdjList L, dirAdjMatrix* Mat){
    int i;
    for(i = 0; i < MAX_VERTEX; i++){
        adjList *trav = &(L.adj[i]);
        while(*trav != NULL){
            Mat->edges[i][(*trav)->info - 'A'] = 1;
            Mat->numEdges++;
            trav = &(*trav)->next;
        }
    }
}

void printMatrix(dirAdjMatrix Mat){
    int i, j;
    printf("\nMatrix:\n");
    for(i = 0; i < MAX_VERTEX; i++){
        printf("%c: ", i + 'A');
        for(j = 0; j < MAX_VERTEX; j++){
            printf("%d ", Mat.edges[i][j]);
        }
        printf("\n");
    }
}