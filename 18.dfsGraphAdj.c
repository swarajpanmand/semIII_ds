#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100

void DFS(int adjMat[MAX][MAX], int visited[MAX], int vertices, int startVertice){
    printf("%d ", startVertice);
    visited[startVertice]=1;
    for(int i=0; i<vertices; i++){
        if(adjMat[startVertice][i]==1 && !visited[i]){
            DFS(adjMat, visited, vertices, i);
        }
    }
}

int main(){
    int vertices, edges, startVertice;
    int adjMat[MAX][MAX];
    int visited[MAX] = {0};
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges(source, destination): \n");
    for(int i=0; i<edges;i++){
        int src , dest;
        scanf("%d %d", &src, &dest);
        adjMat[src][dest] = 1;
        adjMat[dest][src] = 1;
    }

    printf("Adjacency Matrix: \n");
    for(int i=0; i<vertices; i++){
        for(int j=0; j<vertices; j++){
            printf("%d ", adjMat[i][j]);
        }
        printf("\n");
    }

    int startVertex;
    printf("Enter the start vertex: ");
    scanf("%d", &startVertex);

    printf("DFS Traversal: ");
    DFS(adjMat, visited, vertices, startVertex);
    printf("\n");
    return 0;
}