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

// 히프에 item을 삽입하는 연산
void insertHeap(heapType *h, int item){
    int i;
    h -> heap_size = h -> heap_size + 1;    //히프의 크기를 +1하여 노드 위치를 확장
    i = h -> heap_size;                     //확장한 노드 번호가 임시 삽입 위치 i가 된다.    
    while((i != 1) && (item > h -> heap[i/2])) {
        h -> heap[i] = h -> heap[i/2];      //삽입할 원소 item이 부모 노드보다 크면, 자식의 노드의
    //자리를 맞바꿔 최대 히프의 관계를 만들어야 하므로 부모[┗i/2┛]의 원소를 현재의 임시
    //삽입 위치 heap[i]에 저장한다.        
        i /= 2; //┗i/2┛를 임시 삽입 위치 i로 하여 반복하면서 item을 삽입할 위치를 찾는다.
    }
    h -> heap[i] = item;   //찾은 위치에 삽입할 원소 item을 저장하면 최대 히프의 재구성 작업입
    // 완성되므로 삽입 연산을 종료한다.
}

//히프의 루트를 삭제하여 반환하는 연산
int deleteHeap(heapType *h){
    int parent, child;
    int item, temp;
    item = h -> heap[1];                    //루트노드 heap[1]을 변수 item에 저장한다.
    temp = h -> heap[h -> heap_size];       //마지막 노드의 원소heap[n]을 변수 temp에 임시로 저장한다.
    h -> heap_size = h -> heap_size -1;     //마지막 노드를 삭제하였으므로 히프 배열의 원소 개수를 하나 감소한다.
    parent = 1;     //마지막 노드의 원소였던 temp의 임시 저장 위치 i는 루트 노드의 자리인 1번이 된다.
    child = 2;
    while(child <= h -> heap_size){
        if((child < h -> heap_size) && (h -> heap[child]) < h -> heap[child + 1])
            child++;
    //현재 저장 위치에서 왼쪽 자식 노드 heap[j]와 오른쪽 자식 노드 heap[j + 1]이 있을 때,
    //키값이 큰 자식 노드의 키값과 temp를 비교하여 temp가 크거나 같으면 현재의 임시 저장
    //위치를 temp자리로 확정하고 heap[i] <<<- temp
        if(temp >= h -> heap[child]) break;
        else{
            h -> heap[parent] = h -> heap[child];
            parent = child;
            child = child + 2;
    //temp가 자식 노드 heap[j] 보다 작으면 자식 노드와 자리를 바꾸고 while문을 반복하여
    //temp의 자리를 찾는다.
        }
    }
    h -> heap[parent] = temp;   // 찾은 위치에 temp를 저장하여 최대 히프의 재구성 작업을 완성한다.
    return item;    //처음에 삭제된 루트 노드를 저장한 변수 item을 반환하고 삭제 연산을 종료한다.
}