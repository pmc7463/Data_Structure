#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 100

typedef int element;    //스텍 원소(element)의 자료형을 int로 정의

element stack[STACK_SIZE];  // 1차원 배열 스택 선언
int top = -1;

//스택이 공백 상태인지 확인하는 연산
int isEmpty(){
    if(top == -1) return 1;
    else return 0;
}

//스택이 포화 상태인지 확인하는 연산
int isFull(){
    if (top == STACK_SIZE - 1) return 1;
    else return 0;
}

// 스택의 top에 원소를 삽입하는 연산
void push(element item){
    if(isFull()){   // 스택이 포화 상태인 경우
        printf("\n\n Stack is Full! \n");
        return;
    }
    else stack[++top] = item;   // top을 증가시킨 후 현재 top에 원소 삽입
}

// 스택의 top에서 원소를 삭제하는 연산
element pop() {
    if(isEmpty()){      // 스택이 공백 상태인 경우
        printf("\n\n Stack is Empty!!\n");
        return 0;
    }
    else return stack[top--];   //현재 top의 원소를 삭제한 후 top감소
}

// 스택의 top 원소를 검색하는 연산
element peek(){
    if(isEmpty()){      // 스택이 공백 상태인 경우
        printf("\n\n Stack is Empty !\n");
        exit(1);
    }
    else return stack[top]; //현재 top의 원소 확인
}

// 스택의 원소를 출력하는 연산
void printStack(){
    int i;
    printf("\n STACK [");
    for(i = 0; i <= top; i++)
        printf(" %d", stack[i]);
    printf("] ");
}

void main(void){
    element item;
    printf("\n **순차 스택 연산**\n");
    printStack();
    push(41); printStack();
    push(225); printStack();
    push(365); printStack();

    item = peek();
    printStack();   // 현재 top의 원소 출력
    printf("peek => %d", item);

    item = pop();
    printStack();   // 삭제
    printf("\t pop => %d", item);

    item = pop();
    printStack();   // 삭제
    printf("\t pop => %d", item);

    item = pop();
    printStack();   // 삭제
    printf("\t pop => %d", item);

    getchar();
}