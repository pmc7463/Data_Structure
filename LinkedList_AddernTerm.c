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

//다항식 리스트에 마지막 노드를 추가하는 연산
void appendTerm(ListHead *L, float coef, int expo){
    ListNode *newNode;
    ListNode *p;
    newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode -> coef = coef;
    newNode -> expo = expo;
    newNode -> link = NULL;

    if(L ->head == NULL){   // 다항식 리스트가 공백인 경우  
        L ->head = newNode; // L의 head가 newNode를 가르킴
        return;
    }
    else{   // 다항식 리스트가 공백이 아닌 경우
        p = L ->head;
        while (p -> link != NULL){
            p = p -> link;  //리스트의 마지막 노드를 찾음
        }
        p ->link = newNode; //새 노드 연결
    }
}