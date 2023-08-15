#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;   // 스택 원소 (element)의 자료형을 char로 정의

typedef struct stackNode{   //스택의 노드를 구조체로 정의
    element data;
    struct stackNode *link;
} stackNode;

stackNode *top;     // 스택의 top노드를 지정하기 위해 포인터 top 선언

//스택이 공백 상태인지 확인하는 연산
int isEmpty(){
    if(top == NULL) return 1;
    else return 0;
}

//스택의 top에 원소를 삽입하는 연산
void push(element item){
    stackNode *temp = (stackNode *)malloc(sizeof(stackNode));
    temp -> data = item;
    temp -> link = top; //삽입 노드를 top의 위에 연결
    top = temp;         // top 위치를 삽입 노드로 이동
}

//스택의 top에서 원소를 삭제하는 연산
element pop(){
    element item;
    stackNode *temp = top;

    if (top == NULL){
        printf("\n\n Stack is empty!\n");
        return 0;
    }
    else {
        item = temp -> data;
        top = temp -> link;     // top 위치를 삭제 노드 아래로 이동
        free(temp);
        return item;
    }
}

// 수식의 괄호를 검사하는 연산
int testPair(char *exp){
    char symbol, open_pair;
    // char형 포인터 매개변수로 받은 수식 exp의 길이를 계산하여 length 변수에 저장
    int i, length = strlen(exp);
    top = NULL;

    for (i = 0; i < length; i++){
        symbol = exp[i];
        switch (symbol){
            // 1. 왼쪽 괄호는 스택에 삽입
            case '(':
            case '[':
            case '{':
                push(symbol);
            break;

            // 2. 오른쪽 괄호를 읽으면
            case ')':
            case ']':
            case '}':
                if(top == NULL) return 0;
                else{
                    // 2-1. 스택에서 마지막으로 읽은 괄호를 꺼냄
                    open_pair = pop();
                    // 2-2 괄호 쌍이 맞는지 검사
                    if((open_pair == '(' && symbol != ')') ||
                       (open_pair == '[' && symbol != ']') ||
                       (open_pair == '{' && symbol != '}'))
                    // 2-3 괄호 쌍이 틀리면 수식 오류
                    return 0;
                    // 2-4 괄호 쌍이 맞으면 다음 symbol 검사를 계속함
                    else break;
                }
        }
    }
    if (top == NULL) return 1;  //수식 검사를 마친 후 스택이 공백이면 1을 반환
    else return 0;      // 공백이 아니면 0을 반환 (수식 괄호 틀림)
}

void main(void){
    char *express = "{(A + B) - 3 * 5 + [{cos(x + y) + 7} - 1] * 4";
    printf("%s", express);

    if (testPair(express)  == 1)
        printf("\n수식의 괄호가 맞게 사용되었습니다!");
    else
        printf("\n수식의 괄호가 틀렸습니다!");

    getchar();
}
