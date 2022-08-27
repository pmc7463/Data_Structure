#include <stdio.h>
#include <limits.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 5      //그래프의 정점 개수
#define INF 10000

int weight[MAX_VERTICES][MAX_VERTICES] = {      // 그래프 G11의 가중치 인접 행렬
    {0, 10, 5, INF, INF},
    {INF, 0, 2, 1, INF},
    {INF, 3, 0, 9, 2},
    {INF, INF, INF, 0, 4},
    {7, INF, INF, 6, 0},
};

int distance[MAX_VERTICES];     // 시작 정점에서 시작하는 최단 경로 길이 저장
int S[MAX_VERTICES];            // 정점의 집합 S

// 최단 경로를 갖는 다음 정점을 찾는 연산
int nextVertex(int n) {
    int i, min, minPos;
    minPos = -1;
    for (i=0; i<n; i++)
        if((distance[i] < min) && !S[i]) {
            min = distance[i];
            minPos = i;
        }
    return minPos;
}

// 최단 경로 구하는 과정을 출력하는 연산
int printStep(int step) {
    int i;
    printf("\n %3d 단계 : S = {", step);
    for (i = 0; i < MAX_VERTICES; i++)
        if (S[i] == TRUE)
            printf("%3c", i + 65);
    
    if (step < 1) printf(" } \t\t");
    else if (step < 4) printf(" } \t\t");
    else printf(" } \t\t");
    printf("distance : [");
    for (i = 0; i < MAX_VERTICES; i++)
        if(distance[i] == 10000)
            printf("%4c", '*');
        else printf("%4d", distance[i]);
        printf("%4c",']');
        return ++step;
}

void Dijkstra_shortesPath(int start, int n){
    int i, u, w, step = 0;
    for (i = 1; i < n; i++) {               //초기화
        distance[i] = weight[start][i];
        S[i] = FALSE;
    }

    S[start] = TRUE;        //시작 정점을 집합 S에 추가
    distance[start] = 0;    //시작 정점의 최단 경로를 0으로 설정 

    step = printStep(0);    // 0단계 상태를 출력
    
    for ( i = 0; i < n - 1; i++) {
        u = nextVertex(n);      // 최단 경로를 만드는 다음 정점 u 찾기
        S[u] = TRUE;            // 정점 u를 집합 S에 추가
        for (w = 0; w < n; w++)
            if(!S[w])           // 집합 S에 포함되지 않은 정점 중에서
                if (distance[u] + weight[u][w] < distance[w])
                    distance[w] = distance[u] + weight[u][w];   // 경로 길이 수정

        step = printStep(step);     // 현재 단계 출력
    }
}

void main(void){
    int i, j;
    printf("***** 가중치 인접 행렬 *****\n");
    for (i = 0; i < MAX_VERTICES; i++){
        for(j = 0; j < MAX_VERTICES; j++){
            if(weight[i][j] == 10000)
                printf("%4c", '*');
            else printf("%4d", weight[i][j]);
        }
        printf("\n\n");
    }

    printf("***** 다익스트라 최단 경로 구하기 *****\n");
    Dijkstra_shortesPath(0, MAX_VERTICES);
}