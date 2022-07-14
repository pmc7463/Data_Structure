#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;        // 스택 원소 element의 자료형을 int로 정의

typedef struct stackNode {      // 스택의 노드를 구조체로 정의
    element data;
    struct stackNode *link;
} stackNode;

stackNode *top;     // 스택의 top노드를 지정하기 위해 포인터 top선언

//스택이 공백 상태인지 확인하는 연산
int isEmpty(){
    if (top == NULL) return 1;
    else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
    stackNode *temp = (stackNode *)malloc(sizeof(stackNode));
    temp -> data = item;
    temp -> link = top;     //삽입 노드를 top의 위에 연결
    top = temp;             //top 위치를 삽입 노드로 이동
}

//스택의 top에서 원소를 삭제하는 연산
element pop(){
    element item;
    stackNode *temp = top;

    if(top == NULL) {       //스택이 공백 리스트인 경우
        printf("\n Stack is Empty!\n");
        return 0;
    }
    else{                   // 스택이 공백 리스트가 아닌 경우
        item = temp -> data;
        temp -> link = top;     // 삽입 노드를 top의 위에 연결
        free(temp);             // 삭제된 노드의 메모리 반환
        return item;            // 삭제된 원소 반환
    }
}


