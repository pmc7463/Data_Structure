#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 5      // 그래프의 정점 개수
#define INF 10000

int weight[MAX_VERTICES][MAX_VERTICES] = {  // 그래프 G11의 가중치 인접 행렬
    {0, 10, 5, INF, INF},
    {INF, 0, 2, 1, INF},
    {INF, 3, 0, 9, 2},
    {INF, INF, INF, 0, 4},
    {7, INF, INF, 6, 0},
};

int A[MAX_VERTICES][MAX_VERTICES];  // k - 최단 경로 배열

// 최단 경로를 구하는 과정을 출력하는 연산
void printStep(int step) {
    int i, j;
    printf("\n A%d : ", step);
    for (i = 0; i < MAX_VERTICES; i++){
        printf("\t");
        for (j = 0; j < MAX_VERTICES; j++){
            if(A[i][j] == 10000)
                printf("%4c", '*');
            else printf("%4d", A[i][j]);
        }
        printf("\n\n");
    }
}

void Floyd_shortestPath(int n) {
    int v, w, k, step = -1;

    for (v = 0; v < n; v++)
        for (w = 0; w < n; w++)
            A[v][w] = weight[v][w];

    printStep(step);

    for(k = 0; k < n; k++){
        for(v = 0; v < n; v++)
            for(w = 0; w < n; w++)
                if(A[v][k] + A[k][w] < A[v][w])
                    A[v][w] = A[v][k] + A[k][w];
        printStep(++step);
    }
}

void main(void){
    int i,j;
    printf("가중치 인접 행렬 \n");
    for(i = 0; i < MAX_VERTICES; i++){
        for(j = 0; j < MAX_VERTICES; j++){
            if(weight[i][j] == 10000)
                printf("%4c", '*');
            else printf("%4d", weight[i][j]);
        }
        printf("\n\n");
    }

    printf("플로이드 최단 경로 구하기\n");
    Floyd_shortestPath(MAX_VERTICES);
}