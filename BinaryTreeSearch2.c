#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#define MAX_WORD_LENGTH 20  //영어 사전에 들어갈 단어 길이를 20으로 정의
#define MAX_MEAN_LENGTH 200 //영어 사전에 들어갈 단어 뜻의 길이를 200으로 정의

//영어 사전 항목의 구조 정의
typedef struct {
    char word[MAX_WORD_LENGTH];
    char mean[MAX_MEAN_LENGTH];
} element;

// 영어 사전 이진 트리의 노드 구조 정의
typedef struct treeNode {
    element key;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

// 포인터 p가 가리키는 노드와 비교하여 항목 key를 삽입하는 연산
treeNode *insertKey(treeNode *p, element key) {
    treeNode *newNode;
    int compare;

    //삽입할 자리에 새 노드를 구성하여 연결
    if (p == NULL) {
        newNode = (treeNode *)malloc(sizeof(treeNode));
        newNode -> key = key;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    }

    //이진 트리에서 삽입할 자리 탐색
    else {
        compare = strcmp(key.word, p -> key.word);
        if (compare < 0) { 
            p -> left = insertKey(p -> left, key);
        }
        else if(compare > 0)    p -> right = insertKey(p -> right, key);
        else printf("\n 이미 같은 단어가 있습니다! \n");

        return p;   //삽입한 자리 반환
    }
}

void insert(treeNode **root, element key) {
    *root = insertKey(*root, key);
}

// root 노드부터 탐색하여 key와 같은 노드를 찾아 삭제하는 연산
void deleteNode(treeNode *root, element key) {
    treeNode *parent, *p, *succ, *succ_parent;
    treeNode *child;

    parent = NULL;
    p = root;
    
    while((p != NULL) && (p -> right == NULL)) {
        parent = p;
        if (strcmp(key.word, p -> key.word) < 0) p = p -> left;
        else p = p -> right;
    }

    // 삭제할 노드가 없는 경우
    if (p == NULL) {
        printf("\n 삭제할 단어가 사전에 없습니다!!");
        return;
    }

    // 삭제할 노드가 단말 노드인 경우
    if ((p -> left == NULL) && (p -> right == NULL)) {
        if (parent != NULL) {
            if (parent -> left == p) parent -> left = NULL;
            else parent -> right = NULL;
        }
        else root = NULL;
    }

    //삭제할 노드가 자식 노드를 한 개 가진 경우
    else if ((p -> left == NULL) || (p -> right == NULL)) {
        if (p -> left != NULL) child = p -> left;
        else child = p -> right;

        if (parent != NULL) {
            if (parent -> left == p) parent -> left = child;
            else parent -> right = child;
        }
        else root = child;
    }

    //삭제할 노드가 자식 노드를 두 개 가진 경우
    else {
        succ_parent = p;
        succ = p -> right;
        while (succ -> left != NULL) {
            succ_parent = succ;
            succ = succ -> left;
        }
        if (succ_parent -> left == succ)
            succ_parent -> left = succ -> right;
        else succ_parent -> right = succ -> right;
        p -> key = succ -> key;
        p = succ;
    }
    free(p);
}

//이진 탐색 트리에서 키값이 key인 노드 위치를 탐색하는 연산
treeNode *searchBST(treeNode *root, element key) {
    treeNode *p;
    int compare;
    p = root;

    while (p != NULL) {
        compare = strcmp(key.word, p -> key.word);
        if (compare < 0)    p = p -> left;
        else if(compare > 0)    p = p -> right;
        else {
            printf("\n 찾은 단어 : %s", p -> key.word);
            return p; 
       }
    }
    return p;
}

// 이진 탐색 트리를 중위 순회하면서 출력하는 연산
void displayInorder(treeNode *root) {
    if (root) {
        displayInorder(root -> left);
        printf("\n%s : %s", root -> key.word, root -> key.mean);
        displayInorder(root -> right);
    }
}

//영어 사전 메뉴
void menu() {
    printf("\n----------");
    printf("\n\t1 : 출력");
    printf("\n\t2 : 입력");
    printf("\n\t3 : 삭제");
    printf("\n\t4 : 검색");
    printf("\n\t5 : 종료");
    printf("\n----------");
}

void main() {
    char choice;
    element e;
    treeNode *root = NULL, *temp = NULL;

    // [5 : 종료] 메뉴를 선택할 때까지 메뉴에 대한 영어 사전 동작 반복
    do{
        menu();
        choice = getchar(); getchar();

        switch (choice - '0') {
        case 1:
            printf("\t[사전 출력]");
            displayInorder(root); printf("\n\t[사전 끝]\n");
            break;

        case 2:
            printf("\n[단어 입력] 단어를 입력하시오 : "); gets(e.word);
            printf("\n[단어 입력] 단어의 뜻을 입력하시오 : "); gets(e.mean);
            insert(&root, e);
            break;

        case 3:
            printf("\n[단어 삭제] 삭제할 단어 : "); gets(e.word);
            deleteNode(root, e);
            break;
        
        case 4:
            printf("\n[단어 검색] 검색할 단어 : "); gets(e.word);
            temp = searchBST(root, e);
            if (temp != NULL) 
                printf("\n단어 뜻 : %s", temp -> key.mean);
            else printf("\n 사전에 없는 단어 입니다.");
            break;
        }
    } while ((choice - '0') != 5);

    //getchar();
}
