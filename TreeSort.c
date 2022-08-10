#include <stdio.h>
#include <stdlib.h>

typedef int element;    // 이진 탐색 트리 elemenet의 자료형을 int로 정의
typedef struct treeNode {
    element key;        // 데이트 필드
    struct treeNode *left;  // 왼쪽 서브 트리 링크 필드
    struct treeNode *right; // 오른쪽 서브 트리 링크 필드
} treeNode;

// 노드 x를 삽입한는 연산
treeNode *insertNode(treeNode *p, element x) {
    treeNode *newNode;
    if(p == NULL) {
        newNode = (treeNode *)malloc(sizeof(treeNode));
        newNode -> key = x;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    }

    else if(x < p -> key) p -> left = insertNode(p -> left, x);
    else if(x > p -> key) p -> right = insertNode(p -> right, x);
    else printf("\n 이미 같은 키가 있습니다. \n");

    return p;
}

// 이진 탐색 트리를 중위 순회하면서 경로를 출력하는 연산
void displayInorder(treeNode *root) {
    if (root) {
        displayInorder(root -> left);
        printf("%d ", root -> key);
        displayInorder(root -> right);
    }
}

// 트리 정렬 연산
void treeSort(element a[], int n) {
    treeNode *root = NULL;      // 공백 이진 탐색 트리 생성
    root = insertNode(root, a[0]);  // a[0]을 공백 이진 탐색 트리의 루트로 삽입

    for (int i = 1; i < n; i++) // a[1] ~ a[n-1]의 원소들을
        insertNode(root, a[i]); // 삽입하면서 이진 탐색 트리 구성
    displayInorder(root);       // 이진 탐색 트리를 중위 순회한 경로 출력
}

int main() {
    element list[8] = {69,10,30,2,16,8,31,22};
    int size = 8;
    printf("\n <<< 트리 정렬 수행 >>>\n");
    treeSort(list, size);
}