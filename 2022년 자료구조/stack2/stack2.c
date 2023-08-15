#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;    // 스택 원소 (element)의 자료형을 int로 정의

typedef struct stackNode {  // 스택의 노드를 구조체로 정의
    element data;
    struct stackNode *link;
} stackNode;

stackNode *top;     // 스택의 top노드를 지정하기 위해 포인터 top 선언

//스택이 공백 상태인지 확인하는 연산
int isEmpty(){
    if(top == NULL) return 1;
    else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item) {
    stackNode *temp = (stackNode *)malloc(sizeof(stackNode));
    temp -> data = item;    // temp가 item의 data를 가르킴
    temp -> link = top;     // 삽입 노드를 top의 위에 연결, temp가 가르키는 node 의 link에는 top의 값을 지정
    top = temp;             // top 위치를 삽입 노드로 이동, temp가 위로 올라가게 top에 temp값 저장
}

//스택의 top에서 원소를 삭제하는 연산
element pop(){
    element item;
    stackNode *temp = top;

    if(top == NULL) {   // 스택이 공백 리스트인 경우
        printf("\n\n Stack is empty! \n");
        return 0;
    }
    else {      // 스택이 공백 리스트가 아닌 경우
        item = temp -> data;    //스택의 마지막 노드의 데이터 필드값을 변수 item에 저장한다.
        top = temp -> link;     //top위치를 삭제 노드 아래로 이동, temp가 가르키는 노드의 link에 있는 값을 top에 저장
        free(temp);             //삭제된 노드의 메모리 반환
        return item;
    }
}

//스택의 top 원소를 검색하는 연산
element peek(){
    if(top == NULL) {       // 스택이 공백 리스트인 경우
        printf("\n\n Stack is empty! \n");
        return 0;
    }
    else{       // 스택이 공백 리스트가 아닌 경우
        return (top -> data);   // 현재 top의 원소 반환
    }
}

//스택의 원소를 top에서 bottom 순서로 출력하는 연산
void printStack(){
    stackNode *p = top;
    printf("\n STACK [ ");
    while(p){
        printf("%d ", p ->data);
        p = p -> link;
    }
    printf("] ");
}

void main(void){
    element item;
    top = NULL;
    printf("\n**연결 스택 연산**\n");
    printStack();
    push(1);
    printStack();
    push(2);
    printStack();
    push(3);
    printStack();

    item = peek();
    printStack();   //현재 top의 원소 출력
    printf("peek => %d",item);

    item = pop();
    printStack();   //삭제
    printf("\t pop => %d", item);

    item = pop();
    printStack();   //삭제
    printf("\t pop => %d", item);
    
    item = pop();
    printStack();   //삭제
    printf("\t pop => %d", item);
    
    getchar();
}