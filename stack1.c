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
