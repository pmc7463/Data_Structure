#include <stdio.h>
#include <stdlib.h>

//다항식 리스트의 노드 구조를 구조체로 정의
float coef;
typedef struct ListNode {
    float coef;     // 계수 x앞에 숫자
    int expo;       // 지수 제곱 같은거
    struct ListNode *link;
} ListNode;

//다항식 리스트의 head 노드를 구조체로 정의
typedef struct ListHead{
    ListNode *head;
} ListHead;

//공백 다항식 리스트를 생성하는 연산
ListHead *createLinkedList(void){
    ListHead *L;
    L = (ListHead*)malloc(sizeof(ListHead));
    L -> head = NULL;
    return L;
}