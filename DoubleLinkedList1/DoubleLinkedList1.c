#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 이중 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
    struct ListNode *llink; //왼쪽(선행) 노드에 대한 링크
    char data[4];
    struct ListNode *rlink; // 오른쪽(선행) 노드에 대한 링크
} listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
    listNode *head;
} linkedList_h;

// 공백 이중 연결 리스트를 생성하는 연산
linkedList_h *createLinkedList_h(void){
    linkedList_h *DL;
    DL = (linkedList_h*)malloc(sizeof(linkedList_h));   //헤드 노드 할당
    DL -> head = NULL;  // 공백 리스트이므로 NULL로 설정
    return DL;
}

//이중 연결 리스트를 순서대로 출력하는 연사
void printList(linkedList_h *DL){
    listNode *p;
    printf(" DL = (");
    p = DL ->head;
    while ( p != NULL){
        printf("%s", p -> data);
        p = p ->rlink;
        if ( p != NULL) printf(", ");
    }
    printf(") \n");
}

// pre 뒤에 노드를 삽입하는 연산
void insertNode(linkedList_h *DL, listNode *pre, char *x){
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode ->data, x);
    if (DL -> head == NULL){    //DL의 해드가 NULL이면 newNode의 좌우도 NULL이다.
        newNode -> rlink = NULL;
        newNode -> llink = NULL;
        DL -> head = newNode;   //DL의 head가 newNode를 가르킨다.
    }
    else {
        newNode -> rlink = pre -> rlink;    // pre의 오른쪽에 있던 주소를 newNode의 오른쪽에 대입
        pre -> rlink = newNode;     // pre의 오른쪽은 newNode의 주소를 가진다.
        newNode -> llink = pre;     // newNode의 왼쪽에는 pre의 주소를 가진다.
        if (newNode -> rlink != NULL)   // 삽입 자리에 다음 노드가 있는 경우
            newNode -> rlink -> llink = newNode;    // newNode의 오른쪽이 가르키는 노드의 왼쪽 주소는 newNode를 가르킴
    }
}

// 이중 연결 리스트에서 old 노드를 삭제하는 연산
void deleteNode(linkedList_h *DL, listNode *old){
    if (DL -> head == NULL) return; //공백 리스트인 경우 삭제 연산 중단
    else if (old == NULL) return;   //삭제할 노드가 없는 경우 삭제 연산 중단
    else{
        old -> llink -> rlink = old -> rlink;   // old의 왼쪽이 가르키는 Node의 오른쪽이 old의 오른쪽이 가르키는 node를 가르켜라
        old -> rlink -> llink = old -> llink;   // old의 오른쪽이 가르키는 Node의 왼쪽이 old의 왼쪽이 가르키는 node를 가르켜라   
        free(old);  //삭제 노드의 메모리 해제
    }
}

// 리스트에서 x 노드를 탐색하는 연산
listNode *searchNode(linkedList_h *DL, char *x) {
    listNode *temp;
    temp = DL -> head;  // DL이 가르키는 head를 temp에 저장
    while (temp != NULL){
        if (strcmp(temp -> data, x) == 0) return temp;  // strcmp는 문자 비교 명령어, 맞으면 temp 리턴
        else temp = temp -> rlink;  // 맞지 않으면 temp의 오른쪽이 가르키는 노드를 temp에 저장
    }
    return temp;    // 탐색을 끝까지 해도 값이 없으면 마지막에 값은 NULL이니까 temp는 NULL값 반환
}

int main(){
    linkedList_h *DL;
    listNode *p;
    DL = createLinkedList_h();  //공백 리스트 생성
    printf("(1) 이중 연결 리스트 생성하기!! \n");
    printList(DL);
    getchar();

    printf("(2) 이중 연결 리스트에 [월] 노드 삽입하기!! \n");
    insertNode(DL, NULL, "월");
    printList(DL);
    getchar();

    printf("(3) 이중 연결 리스트에 [월] 노드 뒤에 [수]노드 삽입하기!! \n");
    p = searchNode(DL, "월"); 
    insertNode(DL, p, "수");
    printList(DL);
    getchar();

    printf("(4) 이중 연결 리스트에 [수] 노드 뒤에 [금]노드 삽입하기!! \n");
    p = searchNode(DL, "수"); 
    insertNode(DL, p, "금");
    printList(DL);
    getchar();

    printf("(5) 이중 연결 리스트에 [수] 노드 삭제하기!! \n");
    p = searchNode(DL, "수"); 
    deleteNode(DL, p);
    printList(DL);
    getchar();

    return 0;
}