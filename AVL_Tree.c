#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX(a, b) ((a > b) ? a:b)   //(a > b) 참/거짓 판별 ?, 참이면 a, 거짓이면 b : 삼항연산자

typedef int element;

typedef struct treeNode {
    element key;
    struct treeNode *left;
    struct treeNode *right;
}treeNode;

treeNode *LL_rotate(treeNode *parent){
    treeNode *child = parent -> left;   //부모노드의 왼쪽에 저장된 주소로 가서 child 노드를 생성?
    parent -> left = child -> right;    //자식 노드의 오른쪽 주소를 부모 노드의 왼쪽에 저장
    child -> right = parent;            //부모노드를 자식의 오른쪽 노드로 옮긴다,저장
    //그림상으로 레벨은 자식 노드가 0 부모노드가 1, 부모가 자식 밑으로 들어간걸로 생각
    return child;
}

treeNode *RR_rotate(treeNode *parent){
    treeNode *child = parent -> right;  //부모노드의 오른쪽에 저장된 주소로 가서 child 노드를 생성
    parent -> right = child -> left;    //자식의 왼쪽주소를 부모노드의 오른쪽에 저장
    child -> left = parent;             //부모노드를 자식노드의 왼쪽에 옮김
    return child;
}

treeNode *LR_rotate(treeNode *parent){
    treeNode *child = parent -> left;  //부모노드의 왼쪽에 저장된 주소로 가서 child 노드를 생성
    parent -> left = RR_rotate(child); //rr회전을 먼저하여 반환된 노드를 부모노드의 왼쪽에 저장 
    return LL_rotate(child);           //마지막으로 ll회전 한다. 
}

treeNode *RL_rotate(treeNode *parent){
    treeNode *child = parent -> right;  //부모노드의 오르녹에 저장된 주소로 가서 child 노드를 생성
    parent -> right = LL_rotate(child); //ll회전을 먼저하여 반환된 노드를 부모노드의 왼쪽에 저장
    return RR_rotate(child);    
}