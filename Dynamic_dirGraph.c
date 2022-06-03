/*Program tugas pertemuan 13 (Nomor 1b)
Nama        : Andes Andedia Fanansa
NIM         : 2110512101
Prodi/Kelas : S1 Sistem Informasi / Kelas C */

#include <stdio.h>
#include <stdlib.h>

struct node{
    int vertex;
    struct node* next;
};
struct node* createNode(int);

struct Graph{
    int numVertices;
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

    int i;
    for(i=0; i < vertices; i++){
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// add edge
void addEdge(struct Graph* graph, int s, int d){
    //add edge from s to d
    struct node* newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;
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
    int n, x, asal, tujuan, i;
    printf("Selamat Datang di Program Adjency List Graph Berarah !\n");
    printf("Masukkan jumlah vertex : ");
    scanf("%d", &n);
    printf("Masukkan jumlah edge : ");
    scanf("%d", &x);
    struct Graph* graph = createGraph(n);
    printf("\n");
    // proses penambahan edge
    for(i=0;i<x;i++){
        printf("\nProses penambahan edge!\n");
        printf("Masukkan vertex asal : ");
        scanf("%d", &asal);
        printf("masukkan vertex tujuan : ");
        scanf("%d", &tujuan);
        addEdge(graph, asal, tujuan);
    }
    printGraph(graph);

    return 0;
}
