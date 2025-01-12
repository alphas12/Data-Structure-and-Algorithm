#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 9
#define INF 0xFFFFFFF

typedef char vertexType; // A, B, C, D, E, F, G, H, I
typedef int labelType;   // weight of edge

typedef enum{ TRUE, FALSE } boolean;
typedef struct{
    vertexType u;
    vertexType w;
    labelType weight;
} edgeType;

typedef struct{
    int edges[MAX_VERTEX][MAX_VERTEX];
    int numEdges;
} LabeledAdjMatrix; // version 1

typedef struct node
{
    vertexType info;
    labelType weight;
    struct node *next;
} *adjListWeight;

typedef struct
{
    adjListWeight adj[MAX_VERTEX];
    int numEdges;
} LabeledAdjList;

void initMatrix(LabeledAdjMatrix *);
void initList(LabeledAdjList *);
void LabeledAjdM(LabeledAdjMatrix *, edgeType [], int);
int *dijkstraAlgo(LabeledAdjMatrix , vertexType);
LabeledAdjMatrix *floydAlgo(LabeledAdjMatrix Mat);
boolean **warshallAlgo(LabeledAdjMatrix M);
void printBooleanMatrix(boolean **matrix);
void printMatrix(LabeledAdjMatrix Mat);
void printArray(int arr[], int size);

int main(){
    LabeledAdjMatrix Mat;
    LabeledAdjList List;
    initList(&List);
    initMatrix(&Mat);
    
    
    edgeType arr[] = {
        {'A', 'B', 4}, {'A', 'H', 8}, // A
        {'B', 'A', 4}, {'B', 'C', 8}, {'B', 'H', 11}, // B
        {'C', 'B', 8}, {'C', 'D', 7}, {'C', 'F', 4},// C
        {'D', 'C', 7}, {'D', 'E', 9}, {'D', 'F', 14}, // D
        {'E', 'D', 9}, {'E', 'F', 10}, {'E', 'I', 5}, // E
        {'F', 'C', 4}, {'F', 'D', 14}, {'F', 'E', 10}, {'F', 'G', 2}, // F
        {'G', 'F', 2}, {'G', 'H', 1}, {'G', 'I', 6}, // G
        {'H', 'A', 8}, {'H', 'B', 11}, {'H', 'G', 1}, {'H', 'I', 7}, // H
        {'I', 'H', 7}, {'I', 'G', 6}, {'I', 'E', 5} // I
    };
    
    int size = sizeof(arr) / sizeof(arr[0]);

    LabeledAjdM(&Mat, arr, size);
    printMatrix(Mat);

    int *SP_REC = dijkstraAlgo(Mat, 'A');
    printArray(SP_REC, MAX_VERTEX);


    printf("===FLOYD ALGO===");
    LabeledAdjMatrix *M = floydAlgo(Mat);
    printMatrix(*M);


    printf("===Warshall Algo===");
    boolean **result = warshallAlgo(Mat);
    printBooleanMatrix(result);


    
    return 0;
}

void initMatrix(LabeledAdjMatrix *M){
    
    M->numEdges = 0;
    for (int i = 0; i < MAX_VERTEX; i++){
        for (int j = 0; j < MAX_VERTEX; j++){
            M->edges[i][j] = INF;
        }
    }
}

void initList(LabeledAdjList *List){
    List->numEdges = 0;
    for (int i = 0; i < MAX_VERTEX; i++){
        List->adj[i] = NULL;
    }
}

void LabeledAjdM(LabeledAdjMatrix *Mat, edgeType arr[], int size){
    int i;
    for (i = 0; i < size; i++){
        Mat->edges[arr[i].u - 'A'][arr[i].w - 'A'] = arr[i].weight;
        Mat->numEdges++;
    }
}

void printMatrix(LabeledAdjMatrix Mat){
    int i, j;
    printf("\nMatrix:\n");
    for (i = 0; i < MAX_VERTEX; i++){
        printf("%c: ", i + 'A');
        for (j = 0; j < MAX_VERTEX; j++){
            if(Mat.edges[i][j] == INF){
                printf("INF ");
            } else {
                printf("%d ", Mat.edges[i][j]);
            }
        }
        printf("\n");
    }
}


void printBooleanMatrix(boolean **matrix) {
    printf("\nBoolean Matrix:\n");
    for (int i = 0; i < MAX_VERTEX; i++) {
        for (int j = 0; j < MAX_VERTEX; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int *dijkstraAlgo(LabeledAdjMatrix Mat, vertexType source){
    boolean visited[MAX_VERTEX];

    //initialize the components set to FALSE
    for(int i = 0; i < MAX_VERTEX; i++){
        visited[i] = FALSE;
    }

    int *SP_REC = (int *)malloc(sizeof(int) * MAX_VERTEX);

    if (SP_REC != NULL){
        
        int x;
        for (x = 0; x < MAX_VERTEX; x++){
            SP_REC[x] = Mat.edges[source - 'A'][x];
        }

        SP_REC[source - 'A'] = 0;

        int min, minIndex;
        for (x = 0; x < MAX_VERTEX; x++){
            min = INF; // set the min to INF
            for (int y = 0; y < MAX_VERTEX; y++){
                if (visited[y] == FALSE && SP_REC[y] < min){
                    min = SP_REC[y];
                    minIndex = y;
                } // check for the min
            }

            visited[minIndex] = TRUE;
            for (int z = 0; z < MAX_VERTEX; z++){ //Update the SP_REC only when valid
                if (visited[z] == FALSE && SP_REC[z] > SP_REC[minIndex] + Mat.edges[minIndex][z]){
                    SP_REC[z] = SP_REC[minIndex] + Mat.edges[minIndex][z];
                }
            }
        }
    }

    return SP_REC;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

LabeledAdjMatrix *floydAlgo(LabeledAdjMatrix Mat) {
    LabeledAdjMatrix *SP_REC = (LabeledAdjMatrix *)malloc(sizeof(LabeledAdjMatrix));

    for (int i = 0; i < MAX_VERTEX; i++) {
        for (int j = 0; j < MAX_VERTEX; j++) {
            SP_REC->edges[i][j] = Mat.edges[i][j];
        }
    }

    for(int k = 0; k < MAX_VERTEX; k++){
        SP_REC->edges[k][k] = 0;
    }
    for (int k = 0; k < MAX_VERTEX; k++) {
        for (int i = 0; i < MAX_VERTEX; i++) {
            for (int j = 0; j < MAX_VERTEX; j++) {
                if (SP_REC->edges[i][j] > SP_REC->edges[i][k] + SP_REC->edges[k][j]) {
                    SP_REC->edges[i][j] = SP_REC->edges[i][k] + SP_REC->edges[k][j];
                }
            }
        }
    }

    return SP_REC;
}



boolean **warshallAlgo(LabeledAdjMatrix M) {
    boolean **SP_REC = (boolean **)malloc(MAX_VERTEX * sizeof(boolean *));
    for (int i = 0; i < MAX_VERTEX; i++) {
        SP_REC[i] = (boolean *)malloc(MAX_VERTEX * sizeof(boolean));
    }

    for (int i = 0; i < MAX_VERTEX; i++) {
        for (int j = 0; j < MAX_VERTEX; j++) {
            SP_REC[i][j] = (M.edges[i][j] != INF);
        }
    }

    for (int k = 0; k < MAX_VERTEX; k++) {
        for (int i = 0; i < MAX_VERTEX; i++) {
            for (int j = 0; j < MAX_VERTEX; j++) {
                if (SP_REC[i][k] && SP_REC[k][j]) {
                    SP_REC[i][j] = TRUE;
                }
            }
        }
    }

    return SP_REC;
}
