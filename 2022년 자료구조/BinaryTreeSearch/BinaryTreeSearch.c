#include <stdio.h>
#include <stdlib.h>

typedef char element;   // 이진 탐색 트리 element의 자료형을 char로 정의
typedef struct treeNode {
    char key;   // 데이터 필드
    struct treeNode *left;  // 왼쪽 서브 트리 링크 필드
    struct treeNode *right; // 오른쪽 서브 트리 링크 필드
} treeNode;

// 이진 탐색 트리에서 키값이 x인 노드의 위치를 탐색하는 연산
treeNode *searchBST(treeNode *root, char x){
    treeNode *p;
    p = root;
    while (p != NULL){
        if (x < p -> key) p = p -> left;    // p -> key는 루트의 값, x는 내가 찾고자하는 값
        else if( x == p -> key) return p;
        else p = p -> right;
    }
    printf("\n 찾는 키가 없습니다! ");
    return p;
}

// 포인터 p가 가르키는 노드와 비교하여 노드 x를 삽입하는 연산
treeNode *insertNode(treeNode *p, char x){
    treeNode *newNode;
    if(p == NULL){
        newNode = (treeNode *)malloc(sizeof(treeNode));
        newNode -> key = x;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    }
    else if (x < p -> key) p -> left = insertNode(p -> left, x);
    else if (x > p -> key) p -> right = insertNode(p -> right, x);
    else printf("\n 이미 같은 키가 있습니다! \n");

    return p;
}

//루트 노드부터 탐색하여 키값과 같은 노드를 찾아 삭제하는 연산
void deleteNode(treeNode *root, element key){
    treeNode *parent, *p, *succ, *succ_parent;
    treeNode *child;
    parent = NULL;
    p = root;
    while ((p != NULL) && (p -> key != key)){   //삭제할 노드의 위치 탐색
        parent = p;
        if (key < p -> key) p = p -> left;
        else p = p -> right;
    }

    // 삭제할 노드가 없는 경우
    if( p == NULL){
        printf("\n찾는 키가 이진 트리에 없습니다!!");
        return;
    }

    // 삭제할 노드가 단말 노드인 경우
    if((p -> left == NULL) && (p -> right == NULL)) {
        if(parent != NULL){
            if(parent -> left == p) parent -> left = NULL;
            else parent -> right = NULL;
        }
        else root = NULL;
    }

    // 삭제할 노드가 자식 노드를 한 개 가진 경우
    else if ((p -> left == NULL) || (p -> right == NULL)) {
        if (p -> left != NULL) child = p -> left;
        else child = p -> right;
    
        if(parent != NULL){
            if (parent -> left == p) parent -> left = child;
            else parent -> right = child;
        }
        else root = child;
    }

    // 삭제할 노드가 자식 노드를 두 개 가진 경우
    else {
        succ_parent = p;
        succ = p -> left;
        while (succ -> right != NULL){      //왼쪽 서브 트리에서 후계자 찾기
            succ_parent = succ; //오른쪽으로 내려가기 전에 올라갈 주소 남겨놓고 가기
            succ = succ -> right;   // 오른쪽으로 찾으로 내려가기
        }
        if(succ_parent -> left == succ) succ_parent -> left = succ -> left;
        // 여기 까지 왔다는건 오른쪽 끝까지 내려갔다는 뜻
        else succ_parent -> right = succ -> left;
        // succ부모노드의 오른쪽은 삭제한 노드(ex루트 노드) 그 자리에 succ의 왼쪽을 저장 
        p -> key = succ -> key;
        p = succ;
    }
    free(p);
}

//이진 탐색 트리를 중위 순회 하면서 출력하는 연산
void displayInorder(treeNode *root){
    if (root){
        displayInorder(root -> left);
        printf("%c",root -> key);
        displayInorder(root -> right);
    }
}

void menu(){
    printf("\n------------------");
    printf("\n\t1 : 트리 출력");
    printf("\n\t2 : 문자 삽입");
    printf("\n\t3 : 문자 삭제");
    printf("\n\t4 : 문자 검색");
    printf("\n\t5 : 종료");
    printf("\n------------------");
    printf("\n메뉴 입력 >>");
}

int main(){
    treeNode *root = NULL;
    treeNode *foundedNode = NULL;
    char choice, key;
    
    root = insertNode(root, 'G');
    insertNode(root, 'I');
    insertNode(root, 'H');
    insertNode(root, 'D');
    insertNode(root, 'B');
    insertNode(root, 'M');
    insertNode(root, 'N');
    insertNode(root, 'A');
    insertNode(root, 'J');
    insertNode(root, 'E');
    insertNode(root, 'Q');
    
    while (1){
        menu();
        scanf("%c", &choice);

        switch( choice - '0'){
            case 1: printf("/t[이진 트리 출력");
                displayInorder(root);
                printf("\n");
                break;

            case 2: printf("삽입할 문자를 입력하세요 : ");
                scanf(" %c", &key);
                insertNode(root, key);
                break;
            
            case 3: printf("삭제할 문자를 입력하세요 : ");
                scanf(" %c", &key);
                deleteNode(root, key);
                break;

            case 4: printf("찾을 문자를 입력하세요 : ");
                scanf(" %c", &key);
                foundedNode = searchBST(root, key);
                if (foundedNode != NULL)
                    printf("\n %c를 찾았습니다! \n", foundedNode -> key);
                else
                    printf("\n 문자를 찾지 못했습니다.\n");
                break;

            case 5: return 0;

            default: printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n");
                break;
        }
    }
}

