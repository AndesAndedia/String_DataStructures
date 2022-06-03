/*Program tugas pertemuan 12 (Directed Graph)
Nama        : Andes Andedia Fanansa
NIM         : 2110512101
Prodi/Kelas : S1 Sistem Informasi / Kelas C */

#include<stdio.h>

int matriks[20][20];

void displayMatrix(int v){
    int i, j;
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            printf("%3d", matriks[i][j]);
        }
        printf("\n");
    }
}

void add_edge(int u, int v){
    matriks[u][v]=1;
}

int main(){
    int n,m, asal, tujuan;
    printf("Masukkan jumlah simpul : ");
    scanf("%d",&n);
    printf("Masukkan jumlah sisi : ");
    scanf("%d",&m);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            matriks[i][j]=0;
        }
    }
    for(int i=0; i<m; i++){
        printf("simpul asal: ");
        scanf("%d",&asal);
        printf("simpul tujuan: ");
        scanf("%d",&tujuan);
        add_edge(asal,tujuan);
    }
    displayMatrix(n);
    return 0;
}
