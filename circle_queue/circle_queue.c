#include <stdio.h>
#include <stdlib.h>
#define cQ_SIZE 4

typedef char element;   // 큐 원소 element의 자료형을 char로 정의
typedef struct {
    element queue[cQ_SIZE]; // 1차원 배열 큐 선언
    int front, rear;
} QueueType;

QueueType *createQueue(){
    QueueType *cQ;
    cQ = (QueueType*)malloc(sizeof(QueueType));
    cQ -> front = 0;    //front 초깃값 설정
    cQ -> rear = 0;     //rear 초깃값 설정
    return cQ;
}

//원형 큐가 공백 상태인지 검사하는 연산
int isEmpty(QueueType *cQ){
    if(cQ -> front == cQ -> rear){
        printf("Circular Queue is empty!");
        return 1;
    }
    else return 0;
}

// 원형 큐가 포화 상태인지 검사하는 연산
int isFull(QueueType *cQ){
    if(((cQ -> rear + 1) % cQ_SIZE) == cQ -> front) {
        printf("Circular Queue is full !");
        return 1;
    }
    else return 0;
}

// 원형 큐의 rear에 원소를 삽입하는 연산
void enQueue(QueueType *cQ, element item){
    if(isFull(cQ)) return;
    else{
        cQ -> rear = (cQ -> rear + 1) % cQ_SIZE;
        cQ -> queue[cQ -> rear] = item;
    }
}

//원형 큐의 front에서 원소를 삭제하고 반환하는 연산
element deQueue(QueueType *cQ){
    if(isEmpty(cQ)) exit(1);
    else {
        cQ -> front = (cQ -> front + 1) % cQ_SIZE;
        return cQ -> queue[cQ -> front];
    }    
}

//원형 큐의 가장 앞에 있는 원소를 검색하는 연산
element peek(QueueType *cQ){
    if(isEmpty(cQ)) exit(1);
    else return cQ -> queue[(cQ -> front + 1) % cQ_SIZE];
}

//원형 큐의 원소를 출력하는 연산
void printQ(QueueType *cQ){
    int i, first, last;
    first = (cQ -> front + 1) % cQ_SIZE;
    last = (cQ -> rear + 1) % cQ_SIZE;
    printf("Circular Queue : [");
    i = first;
    while(i != last){
        printf("%3c", cQ -> queue[i]);
        i = (i + 1) % cQ_SIZE;
    }
    printf(" ]");
}

void main(void){
    QueueType *cQ = createQueue();  // 큐 생성
    element data;

    printf("\n *** 원형 큐 연산 ***\n");
    printf("\n 삽입 A >>"); enQueue(cQ, 'A'); printQ(cQ);
    printf("\n 삽입 B >>"); enQueue(cQ, 'B'); printQ(cQ);
    printf("\n 삽입 C >>"); enQueue(cQ, 'C'); printQ(cQ);
    data = peek(cQ);    printf("peek item : %c \n", data);

    printf("\n 삭제 >>");   data = deQueue(cQ); printQ(cQ);
    printf("\t 삭제데이터 : %c", data);

    printf("\n 삭제 >>");   data = deQueue(cQ); printQ(cQ);
    printf("\t 삭제데이터 : %c", data);
    
    printf("\n 삭제 >>");   data = deQueue(cQ); printQ(cQ);
    printf("\t 삭제데이터 : %c", data);
    
    printf("\n 삽입 D >>"); enQueue(cQ, 'D'); printQ(cQ);
    printf("\n 삽입 E >>"); enQueue(cQ, 'E'); printQ(cQ);
}