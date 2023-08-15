#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treeNode{    //스레드 이진 트리의 노드 정의
    char data;
    struct treeNode *left;  //왼쪽 서브 트리에 대한 링크 필드
    struct treeNode *right; //오른쪽 서브 트리에 대한 링크 필드
    int isThreadRight;      //후속자에 대한 스레드 태그 필드
} treeNode;

//data를 루트 노드로 하여 왼쪽 서브 트리와 오른쪽 서브 트리를 연결하는 연산
treeNode *makeRootNode(char data, treeNode *leftNode, treeNode *rightNode, int isThreadRight){
    treeNode *root = (treeNode*)malloc(sizeof(treeNode));
    root -> data = data;
    root -> left = leftNode;
    root -> right = rightNode;
    root -> isThreadRight = isThreadRight;
    return root;
}

//후속자 노드를 반환하는 연산
treeNode *findThreadSuccessor(treeNode *p){
    treeNode *q = p -> right;
    if(q == NULL) return q;     // 스레드가 null이므로 후속자가 없다는 뜻, null반환? 맞나?
    if(p -> isThreadRight == 1) return q;   //현재 노드 p의 isThreadRight가 참이면 오른쪽 링크 필드값이 후속자 스레드가 된다. 이런경우에는 후속자 스레드인 q를 반환한다.
    while(q -> left != NULL) q = q -> left; //현재노드의 오른쪽 자식이 있는경우 >> 오른쪽으로 가서 왼쪽 끝까지가서 q 반환
    return q;       
}

//스레드 이진 트리의 중위 순회
void threadIndorder(treeNode *root){
    treeNode *q;
    q = root;
    while (q -> left) q = q -> left;    // 중위 순회를 시작하기 위해 왼쪽 끝까지 가는거임
    do{
        printf("%3c", q -> data);
        q = findThreadSuccessor(q);
    } while(q); //q가 있는 동안 중위순회 반복
}

void main(){
    treeNode *n7 = makeRootNode('D', NULL, NULL, 0);
    treeNode *n6 = makeRootNode('C', NULL, NULL, 1);
    treeNode *n5 = makeRootNode('B', NULL, NULL, 1);
    treeNode *n4 = makeRootNode('A', NULL, NULL, 1);
    treeNode *n3 = makeRootNode('/', n6, n7, 0);
    treeNode *n2 = makeRootNode('*', n4, n5, 0);
    treeNode *n1 = makeRootNode('-', n2, n3, 0);

    n4 -> right = n2;
    n5 -> right = n1;
    n6 -> right = n3;

    printf("\n 스레드 이진 트리의 중위 순회 : ");
    threadIndorder(n1);

}