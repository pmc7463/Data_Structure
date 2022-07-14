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

element evalPostfix(char *exp){
    int opr1, opr2, value, i = 0;
    // char 형 포인터 매개변수로 받은 수식 exp의 길이를 계산하여 length 변수에 저장
    int length = strlen(exp);
    char symbol;
    top = NULL;

    for(i = 0; i < length; i++){
        symbol = exp[i];
        if(symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/'){
            value = symbol - '0';
            push(value);
        }
        else{
            opr2 = pop();
            opr1 = pop();
            //변수 opr1 과 opr2에 대한 symbol에 저장된 연산자를 연산
            switch(symbol){
                case '+': push(opr1 + opr2); break;
                case '-': push(opr1 - opr2); break;
                case '*': push(opr1 * opr2); break;
                case '/': push(opr1 / opr2); break;
            }
        }
    }
    //수식 exp에 대한 처리를 마친 후 스택에 남아 있는 결과값을 pop하여 반환
    return pop();
}

void main(void){
    int result;
    char *express = "35*62/-";
    printf("후위 표기식 : %s",express);

    result = evalPostfix(express);
    printf("\n 연산결과 => %d", result);

    getchar();
}
