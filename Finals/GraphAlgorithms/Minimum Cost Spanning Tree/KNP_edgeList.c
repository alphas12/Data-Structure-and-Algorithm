#include <stdio.h>
#include <stdlib.h>


#define MAX 9
#define infinity 999

typedef int LabelAdjMat[MAX][MAX];
typedef enum{TRUE, FALSE}Boolean;

typedef struct {
    int u, w;
    int weight;
} Edgetype;

typedef struct node {
    Edgetype N;
    struct node *next;
} *EdgeList;

typedef struct {
    EdgeList L;
    int cost;
} MST;

void initMatrix(LabelAdjMat);
void LabAdjM(LabelAdjMat, Edgetype[], int);
EdgeList createEdgeList(LabelAdjMat M);
MST findMSTKruskal(LabelAdjMat M);
MST findMSTPrim(LabelAdjMat M, int);
void printEdgeList(EdgeList);
void deleteFirst(EdgeList *, EdgeList *);
void insertEdgeList(EdgeList *head, Edgetype data);

int main() {
    LabelAdjMat M;
    initMatrix(M);
    Edgetype arr[] = {
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

    MST Kruskal = findMSTKruskal(M);
    printf("Minimum Cost in Kruskal: %d\n", Kruskal.cost);

    printf("Edges in MST:\n");
    printEdgeList(Kruskal.L);

    MST Prim = findMSTPrim(M, 2);
    printf("Minimum Cost in Prim: %d\n", Prim.cost);

    printf("Edges in MST:\n");
    printEdgeList(Prim.L);
    

    return 0;
}

void initMatrix(LabelAdjMat M) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            M[i][j] = infinity;
        }
    }
}

void LabAdjM(LabelAdjMat M, Edgetype arr[], int size) {
    for (int i = 0; i < size; i++) {
        M[arr[i].u][arr[i].w] = arr[i].weight;
        M[arr[i].w][arr[i].u] = arr[i].weight;
    }
}

EdgeList createEdgeList(LabelAdjMat M) {
    EdgeList new = NULL;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < i; j++) {
            if (M[i][j] != infinity) {
                EdgeList temp = (EdgeList)malloc(sizeof(struct node));
                temp->N.u = i;
                temp->N.w = j;
                temp->N.weight = M[i][j];
                EdgeList *trav;
                for(trav = &(new); *trav != NULL && temp->N.weight >= (*trav)->N.weight; trav = &(*trav)->next){}
                temp->next = *trav;
                *trav = temp;
            }
        }
    }
    return new;
}

void insertEdgeList(EdgeList *head, Edgetype data){ //insertSorted
    EdgeList temp = (EdgeList)malloc(sizeof(struct node));
	if(temp != NULL){
		EdgeList *trav = head;
	
		temp->N.u = data.u;
        temp->N.w = data.w;
        temp->N.weight = data.weight;

        while(*trav != NULL && temp->N.weight > (*trav)->N.weight){
			trav = &(*trav)->next;
		}

        temp->next = *trav;
		*trav = temp;
	}
}


void deleteFirst(EdgeList *head, EdgeList *R){
    if(*head != NULL){
        *R = *head;
        (*head) = (*head)->next;
        (*R)->next = NULL;
    }
}

void printEdgeList(EdgeList L) {
    for (EdgeList trav = L; trav != NULL; trav = trav->next) {
        printf("Edge: (%d, %d) Weight: %d\n", trav->N.u, trav->N.w, trav->N.weight);
    }
}

MST findMSTKruskal(LabelAdjMat M) {
    EdgeList edgeList = createEdgeList(M);
    int vertex[MAX];
    for (int i = 0; i < MAX; i++) {
        vertex[i] = i;
    }

    MST Kruskal = {NULL, 0};

    while (edgeList != NULL) {
        EdgeList temp = edgeList;
        edgeList = edgeList->next;

        int u = temp->N.u;
        int w = temp->N.w;

        if (vertex[u] != vertex[w]) {
            Kruskal.cost += temp->N.weight;


            int oldSet = vertex[u];
            int newSet = vertex[w];

            for (int i = 0; i < MAX; i++) {
                if (vertex[i] == oldSet) {
                    vertex[i] = newSet;
                }
            }

            temp->next = Kruskal.L;
            Kruskal.L = temp;
        } else {
            free(temp);
        }
    }

    return Kruskal;
}



MST findMSTPrim(LabelAdjMat M, int src){
    MST Prim;
    Prim.L = NULL;
    Prim.cost = 0;

    int visited[MAX];
    for(int i = 0; i < MAX; i++){
        visited[i] = 0;
    }

    visited[src] = 1;

    EdgeList new = NULL;

    int j;
    for(j = 0; j < MAX; j++){
        if(M[src][j] != infinity) {
            Edgetype edgeList = {src, j, M[src][j]};
            insertEdgeList(&new, edgeList);
        }
    }

    while(new != NULL){
        EdgeList min;
        deleteFirst(&new, &min); //get the First Node
        if(visited[min->N.u] != visited[min->N.w]){
            Prim.cost += min->N.weight;
            min->next = Prim.L;
            Prim.L = min; //insertFirst

            int notVisited = (visited[min->N.u] == 0) ? min->N.u : min->N.w;
            visited[notVisited] = 1; // set notVisited to visited

            // add newly potential edges to the MinHeap 
            for(int i = 0; i < MAX; i++) {
                if(M[notVisited][i] != infinity && visited[i] == 0) {
                    Edgetype edgeList = {notVisited, i, M[notVisited][i]};
                    insertEdgeList(&new, edgeList);
                }
            }
        }
    }

    return Prim;
}
