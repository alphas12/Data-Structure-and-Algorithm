#include <stdio.h>

#define infinity 999
#define MAX 9
#define MAX_SIZE 20

typedef int Vertex;

typedef int LabelAdjMat[MAX][MAX];
typedef enum{TRUE, FALSE}Boolean;
typedef struct{
    int u, v;
    int weight;
} edgetype;

typedef struct{
    edgetype edges[MAX_SIZE];
    int lastNdx;
} minHeapOrList;

typedef struct{
    minHeapOrList eList;
    int cost;
} MST;

void initHeap(minHeapOrList *);
void insertMinHeap(minHeapOrList *, edgetype edge);
void minHeapify(minHeapOrList *, int);
minHeapOrList createMinHeap(LabelAdjMat);
MST Kruskals(LabelAdjMat);
MST Prims(LabelAdjMat, int);
edgetype deleteMinheap(minHeapOrList *Q);
void printMST(MST);
void initMatrix(LabelAdjMat);
void LabAdjM(LabelAdjMat, edgetype[], int);

int main(){

    LabelAdjMat M;
    initMatrix(M);
    edgetype arr[] = {
        {0, 1, 4}, {0, 7, 8}, // A
        {1, 0, 4}, {1, 2, 8}, {1, 7, 11}, // B
        {2, 1, 8}, {2, 3, 7}, {2, 5, 4},// C
        {3, 2, 7}, {3, 4, 9}, {3, 5, 14}, // D
        {4, 3, 9}, {4, 5, 10}, {4, 8, 5}, // E
        {5, 2, 4}, {5, 3, 14}, {5, 4, 10}, {5, 6, 2}, // F
        {6, 5, 2}, {6, 7, 1}, {6, 8, 6}, // G
        {7, 0, 8}, {7, 1, 11}, {7, 6, 1}, {7, 8, 7}, // H
        {8, 7, 7}, {8, 6, 6}, {8, 4, 5} // I
    };
    
    int size = sizeof(arr) / sizeof(arr[0]);
    LabAdjM(M, arr, size);

    MST K = Kruskals(M);
    printf("======Kruskal======");
    MST P = Prims(M, 0);
    printf("======Prims======");
    printMST(P);
    return 0;
}



void initMatrix(LabelAdjMat M) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            M[i][j] = infinity;
        }
    }
}

void LabAdjM(LabelAdjMat M, edgetype arr[], int size) {
    for (int i = 0; i < size; i++) {
        M[arr[i].u][arr[i].v] = arr[i].weight;
        M[arr[i].v][arr[i].u] = arr[i].weight;
    }
}


void initHeap(minHeapOrList *Q){
    Q->lastNdx = -1;
}

void insertMinHeap(minHeapOrList *Q, edgetype edge){
    if (Q->lastNdx < MAX_SIZE - 1){
        Q->lastNdx++;
        Q->edges[Q->lastNdx].u = edge.u;
        Q->edges[+Q->lastNdx].v = edge.v;
        Q->edges[Q->lastNdx].weight = edge.weight;
        for (int i = (Q->lastNdx / 2); i >= 0; i--){
            minHeapify(Q, i);
        }
    }
}

void minHeapify(minHeapOrList *Q, int parent){

    int smallest = parent;
    int LC = 2 * parent + 1;
    int RC = LC + 1;

    if (LC <= Q->lastNdx && Q->edges[LC].weight < Q->edges[smallest].weight){
        smallest = LC;
    }

    if (RC <= Q->lastNdx && Q->edges[RC].weight < Q->edges[smallest].weight){
        smallest = RC;
    }

    if (smallest != parent){
        edgetype temp = Q->edges[parent];
        Q->edges[parent] = Q->edges[smallest];
        Q->edges[smallest] = temp;
        minHeapify(Q, smallest);
    }
}

minHeapOrList createMinHeap(LabelAdjMat M){
    minHeapOrList Q;
    initHeap(&Q);

    int i, j;
    for (i = 1; i < MAX; i++){
        for (j = 0; j < i; j++){
            if (M[i][j] != infinity){
                // insertPOT
                edgetype temp = {i,j,M[i][j]};
                insertMinHeap(&Q, temp);
            }
        }
    }
    return Q;
}

MST Kruskals(LabelAdjMat A){
    minHeapOrList M = createMinHeap(A);

    int vertex[MAX];
    for (int i = 0; i < MAX; i++){
        vertex[i] = i;
    }

    MST Kruskals;
    Kruskals.cost = 0;
    Kruskals.eList.lastNdx = -1;

    while(M.lastNdx >= 0){
        edgetype Min = deleteMinheap(&M);


        if (vertex[Min.u] != vertex[Min.v]){
            int oldSet = vertex[Min.u];
            int newSet = vertex[Min.v];

            for (int i = 0; i < MAX; i++){
                if (vertex[i] == oldSet){
                    vertex[i] = newSet;
                }
            } // change value

            insertMinHeap(&(Kruskals.eList), Min);
            Kruskals.cost += Min.weight;
        }
    }

    return Kruskals;
}

MST Prims(LabelAdjMat A, int start){

    MST Prims = {.eList.lastNdx = -1, .cost = 0};
    minHeapOrList PQ = {.lastNdx = -1};
    Boolean visited[MAX];

    for(int i = 0; i < MAX; i++){
        visited[i] = FALSE;
    }

    visited[start] = TRUE;

    int i;
    for(i = 0; i < MAX; i++){
        if(A[start][i] != infinity) {
            edgetype edgeList = {start, i, A[start][i]};
            insertMinHeap(&PQ, edgeList);
        }
    }

    int numEdges = MAX - 1;

    while(Prims.eList.lastNdx + 1 < numEdges){
        edgetype min = deleteMinheap(&PQ);

        if(visited[min.u] != visited[min.v]){
            Prims.cost += min.weight;
            Prims.eList.edges[++Prims.eList.lastNdx] = min;

            int notVisited = (visited[min.u] == FALSE) ? min.u : min.v;
            visited[notVisited] = TRUE; // set notVisited to visited


             // add newly potential edges to the MinHeap 
            for(int i = 0; i < MAX; i++) {
                if(A[notVisited][i] != infinity && visited[i] == FALSE) {
                    edgetype edgeList = {notVisited, i, A[notVisited][i]};
                    insertMinHeap(&PQ, edgeList);
                }
            }
        }
    }
    return Prims;
}


edgetype deleteMinheap(minHeapOrList *Q){
    edgetype temp = {-1, -1, -1};

    if (Q->lastNdx >= 0){
        temp = Q->edges[0];
        Q->edges[0] = Q->edges[Q->lastNdx--];
        for (int i = 0; i <= Q->lastNdx / 2; i++){
            minHeapify(Q, i); // swapping
        }
    }
    return temp;
}


void printMST(MST result) {
    printf("\nMinimum Spanning Tree Edges:\n");
    printf("Edge \tWeight\n");
    for(int i = 0; i <= result.eList.lastNdx; i++) {
        printf("%d - %d\t%d\n", 
            result.eList.edges[i].u, 
            result.eList.edges[i].v, 
            result.eList.edges[i].weight);
    }
    printf("\nTotal MST Cost: %d\n", result.cost);
}


//Reference:
//Prims Function: Zeus D. Elderfield :)