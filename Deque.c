#include <stdio.h>
#include <malloc.h>

typedef char element;
typedef struct DQNode {     // 이중 연결 리스트 데크의 노드 구조를 구조체로 정의
    element data;
    struct DQNode *llink;
    struct DQNode *rlink;
} DQNode;

typedef struct{     //데크에서 사용하는 포인터 front와 rear를 구조체로 정의
    DQNode *front, *rear;
} DQueType;

//공백 데크를 생성하는 연산
DQueType *createDQue(){
    DQueType *DQ;
    DQ = (DQueType *)malloc(sizeof(DQueType));
    DQ -> front = NULL;
    DQ -> rear = NULL;
    return DQ;
}

//데크가 공백 상태인지 검사하는 연산
int isEmpty(DQueType *DQ){
    if(DQ -> front == NULL){
        printf("\n Linked Queue is empty ! \n");
        return 1;
    }
    else return 0;
}

//데크의 front 앞으로 원소를 삽입하는 연산
void insertFront(DQueType *DQ, element item){
    DQNode *newNode = (DQNode *)malloc(sizeof(DQNode));
    newNode -> data = item;
    if (DQ -> front == NULL){   //데크가 공백 상태인 경우
        DQ -> front = newNode;
        DQ -> rear = newNode;
        newNode -> rlink = NULL;
        newNode -> llink = NULL;
    }
    else{
        DQ -> front -> llink = newNode;
        newNode -> rlink = DQ -> front;
        newNode -> llink = NULL;
        DQ -> front = newNode;
    }
}

// 데크의 rear 뒤로 원소를 삽입하는 연산
void insertRear(DQueType *DQ, element item){
    DQNode *newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode -> data = item;
    if(DQ -> rear == NULL){
        DQ -> front = newNode;
        DQ -> rear = newNode;
        newNode -> rlink = NULL;
        newNode -> llink = NULL;
    }
    else{
        DQ -> rear -> rlink = newNode;
        newNode -> rlink = NULL;
        newNode -> llink = DQ -> rear;
        DQ -> rear = newNode;
    }
}

//데크의 front 노드를 삭제하고 반환하는 연산
element deleteFront(DQueType *DQ){
    DQNode *old = DQ -> front;
    element item;
    if (isEmpty(DQ)) return 0;
    else {
        item = old -> data;
        if (DQ -> front -> rlink == NULL){
            DQ -> front = NULL;
            DQ -> rear = NULL;
        }
        else {
            DQ -> front = DQ -> front -> rlink;
            DQ -> front -> llink = NULL;
        }
        free(old);
        return item;
    }
}

//데크의 rear 노드를 삭제하고 반환하는 연산
element deleteRear(DQueType *DQ){
    DQNode *old = DQ -> rear;
    element item;
    if(isEmpty(DQ)) return 0;
    else{
        item = old -> data;
        if(DQ -> rear -> llink == NULL){
            DQ -> front = NULL;
            DQ -> rear = NULL;
        }
        else{
            DQ -> rear = DQ -> rear -> llink;
            DQ -> rear -> rlink = NULL;
        }
        free(old);
        return item;
    }
}

//데크의 front 노드의 데이터 필드를 반환하는 연산
element peekFront(DQueType *DQ){
    element item;
    if (isEmpty(DQ)) return 0;
    else {
        item = DQ -> front -> data;
        return item;
    }
}

// 데크의 rear 노드의 데이터 필드를 반환하는 연산
element peekRear(DQueType *DQ){
    element item;
    if(isEmpty(DQ)) return 0;
    else{
        item = DQ -> rear -> data;
        return item;
    }
}

//데크의 front 노드부터 rear 노드까지 출력하는 연산
void printDQ(DQueType *DQ){
    DQNode *temp = DQ -> front;
    printf("DeQue : [");
    while (temp){
        printf("%3c", temp -> data);
        temp = temp -> rlink;
    }
    printf("] ");
}

void main(void){
    DQueType *DQ1 = createDQue();  // 큐 생성
    element data;

    printf("\n *** 데크 연산 ***\n");
    printf("\n front 삽입 A >>"); insertFront(DQ1, 'A'); printDQ(DQ1);
    printf("\n front 삽입 B >>"); insertFront(DQ1, 'B'); printDQ(DQ1);
    printf("\n rear 삽입 C >>"); insertRear(DQ1, 'C'); printDQ(DQ1);

    printf("\n front 삭제 >>");   data = deleteFront(DQ1); printDQ(DQ1);
    printf("\t 삭제데이터 : %c", data);

    printf("\n rear 삭제 >>");   data = deleteRear(DQ1); printDQ(DQ1);
    printf("\t 삭제데이터 : %c", data);
    
    printf("\n rear 삽입 D >>"); insertRear(DQ1, 'D'); printDQ(DQ1);
    printf("\n front 삽입 E >>"); insertFront(DQ1, 'E'); printDQ(DQ1);
    printf("\n front 삽입 F >>"); insertFront(DQ1, 'F'); printDQ(DQ1);

    data = peekFront(DQ1); printf("\n peek Front item : %c \n", data);
    data = peekRear(DQ1); printf("\n peek Rear item : %c \n", data);
}