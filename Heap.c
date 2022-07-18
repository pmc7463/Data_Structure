#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

//히프에 대한 1차원 배열과 히프 원소의 개수를 구조체로 묶어서 선언
typedef struct {
    int heap[MAX_ELEMENT];
    int heap_size;
} heapType;

//공백 히프를 생성하는 연산
heapType * createHeap() {
    heapType *h = (heapType *)malloc(sizeof(heapType));
    h -> heap_size = 0;
    return h;
}

