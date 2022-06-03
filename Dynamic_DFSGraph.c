/*Program tugas pertemuan 13 (Nomor 3)
Nama        : Andes Andedia Fanansa
NIM         : 2110512101
Prodi/Kelas : S1 Sistem Informasi / Kelas C */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int vertex;
    struct node* next;
};

struct Graph{
    int numVertices;
    int* visited;
    struct node** adjLists;
};

//create a node
struct node* createNode(int v){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
};

//create a graph
struct Graph* createGraph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited=malloc(vertices*sizeof(int));

    int i;
    for(i=0; i < vertices; i++){
        graph->adjLists[i] = NULL;
        graph->visited[i]=0;
    }
    return graph;
}

// add edge
void addEdge(struct Graph* graph, int s, int d){
    //add edge from s to d
    struct node* newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;

    //add edge from d to s
    newNode = createNode(s);
    newNode->next = graph->adjLists[d];
    graph->adjLists[d] = newNode;
}

void DFS(struct Graph* graph, int vertex){
    struct node* adjLists = graph->adjLists[vertex];
    struct node* temp = adjLists;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while(temp != NULL){
        int connectedVertex = temp->vertex;

        if(graph->visited[connectedVertex]==0){
            DFS(graph, connectedVertex);
        }
        temp=temp->next;
    }
}

//print the Graph
void printGraph(struct Graph* graph){
    int v;
    for(v=0; v<graph->numVertices; v++){
        struct node* temp = graph->adjLists[v];
        printf("\n Vertex %d\n: ", v);
        while(temp){
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){
    int n, x, vertex, edge, dfs, i;
    printf("Selamat Datang di Program Adjency List Graph Tidak Berarah !\n");
    printf("Masukkan jumlah vertex : ");
    scanf("%d", &n);
    printf("Masukkan jumlah edge : ");
    scanf("%d", &x);
    struct Graph* graph = createGraph(n);
    printf("\n");
    // proses penambahan edge
    for(i=0;i<x;i++){
        printf("\nProses penambahan edge!\n");
        printf("Masukkan vertex : ");
        scanf("%d", &vertex);
        printf("masukkan edge : ");
        scanf("%d", &edge);
        addEdge(graph, vertex, edge);
    }
    printGraph(graph);

    printf("\nDFS Vertex : ");
    scanf("%d", &dfs);
    DFS(graph,dfs);
    return 0;
}
