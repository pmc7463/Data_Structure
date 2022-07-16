#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct treeNode{        //연결 자료구조로 구성하기 위해 트리의 노드 정의
    char data;
    struct treeNode *left;      // 왼쪽 서브 트리에 대한 링크 필드
    struct treeNode *right;     // 오른쪽 서브 트리에 대한 링크 필드
} treeNode;

//data를 루트 노드로 하여 왼쪽 서브 트리와 오른쪽 서브 트리를 연결하는 연산
treeNode *makeRootNode(char data, treeNode *leftNode, treeNode *rightNode){
    treeNode *root = (treeNode *)malloc(sizeof(treeNode));
    root -> data = data;
    root -> left = leftNode;
    root -> right - rightNode;
    return root;
}

