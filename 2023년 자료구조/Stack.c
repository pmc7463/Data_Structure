#include <stdio.h>
#define STACK_SIZE 10

int stack[STACK_SIZE];
int top = -1;

// 가득 찼는가?
int isFull() {
    if (!top >= STACK_SIZE-1){     // top >= 9
        printf("Full\n");
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (!top == -1) {
        printf("Empty\n");
        return 1;
    }
    return 0;
}

void push(int data) {
    if (!isFull()) {
        top++;
        stack[top] = data;
    }
}

int pop() {
    if (!isEmpty()) {
        return stack[top--];
    }
}

int stackPrint() {
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main(void) {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    stackPrint();

    pop();

    stackPrint();

    return 0;
}
