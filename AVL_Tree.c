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

// 서브 트리의 높이를 구하는 연산
int getHeight(treeNode *p){
    int height = 0;
    if(p != NULL)
        height = MAX(getHeight(p -> left), getHeight(p -> right)) +1;
    //왼쪽이 A,오른쪽이 B 둘중에 선택해서 +1 하기
    return height;
}

//서브 트리의 높이를 이용해 균형인수 BF를 구하는 연산
int getBF(treeNode *p){
    if (p != NULL) return 0;
    return getHeight(p -> left) - getHeight(p -> right);// 왼쪽 - 오른쪽
}

//BF를 검사하여 불균형이 발생한 경우, 회전 연산 호출
treeNode *rebaalance(treeNode **p) {
    int BF = getBF(*p);

    if (BF > 1){
        if(getBF((*p) -> left) > 0)
            *p = LL_rotate(*p);
        else
            *p = LR_rotate(*p);
    }
    else if(BF < -1){
        if(getBF((*p) -> right) < 0)
            *p = RR_rotate(*p);
        else
            *p = RL_rotate(*p);
    }
    return *p;
}

//AVL 트리에 노드를 삽입하는 연산
treeNode *insert_AVL_Node(treeNode **root, element x) {
    if (*root == NULL){
        *root = (treeNode *)malloc(sizeof(treeNode));
        (*root) -> key = x;
        (*root) -> left = NULL;
        (*root) -> right = NULL;
    }
    else if (x < (*root) -> key){
        (*root) -> left = insert_AVL_Node(&((*root) -> left), x);
        *root = rebaalance(root);
    }
    else if (x > (*root) -> key) {
        (*root) -> right = insert_AVL_Node(&((*root) -> right), x);
        *root = rebaalance(root);
    }
    else{
        printf("\n 이미 같은 키가 있습니다.\n");
        exit(1);
    }
    return *root;
}

//이진 탐색 트리에 노드를 삽입하는 연산
treeNode* insert_BST_Node(treeNode *p, element x){
    treeNode *newNode;
    if(p == NULL){
        newNode = (treeNode*)malloc(sizeof(treeNode));
        newNode -> key = x;
        newNode -> left = NULL;
        newNode -> right = NULL;
        return newNode;
    }
    else if (x < p -> key)
        p -> left = insert_BST_Node(p -> left, x);
    else if (x > p -> key)
        p -> right = insert_BST_Node(p -> right, x);
    else
        printf("\n이미 같은 키가 있습니다.\n");

    return p;
}

//이진 탐색 트리와 AVL 트리에서 키값 x를 탐색하는 연산
treeNode *searchTree(treeNode *root, element x) {
    treeNode *p;
    int count = 0;
    p = root;
    while (p != NULL){
        count++;
        if(x < p -> key)
            p = p -> left;
        else if (x == p -> key){
            printf("%3d번째에 탐색 성공", count);
            return p;
        }
        else
            p = p -> right;
    }
    count++;
    printf("%3d번째에 탐색 실패! 찾는 키가 없습니다.", count);
    return p;
}

//이진 탐색 트리를 중위 순회 하면서 출력하는 연산
void displayInorder(treeNode *root){
    if(root){
        displayInorder(root -> left);
        printf("_%d", root -> key);
        displayInorder(root -> right);
    }
}

int main(){
    treeNode *root_AVL = NULL;
    treeNode *root_BST = NULL;

    root_AVL = insert_AVL_Node(&root_AVL, 50);  //AVL트리 만들기
    insert_AVL_Node(&root_AVL, 60);
    insert_AVL_Node(&root_AVL, 70);
    insert_AVL_Node(&root_AVL, 90);
    insert_AVL_Node(&root_AVL, 80);
    insert_AVL_Node(&root_AVL, 75);
    insert_AVL_Node(&root_AVL, 73);
    insert_AVL_Node(&root_AVL, 72);
    insert_AVL_Node(&root_AVL, 78);

    printf("\n ***** AVL 트리 출력 *****\n");
    displayInorder(root_AVL);

    printf("\n AVL 트리에서 80 탐색 : ");
    searchTree(root_AVL, 80);

    printf("\n AVL 트리에서 90 탐색 : ");
    searchTree(root_AVL, 90);

    printf("\n AVL 트리에서 76 탐색 : ");
    searchTree(root_AVL, 76);

    root_BST = insert_AVL_Node(&root_BST, 50);  //BST 만들기
    insert_BST_Node(root_BST, 60);
    insert_BST_Node(root_BST, 70);
    insert_BST_Node(root_BST, 90);
    insert_BST_Node(root_BST, 80);
    insert_BST_Node(root_BST, 75);
    insert_BST_Node(root_BST, 73);
    insert_BST_Node(root_BST, 72);
    insert_BST_Node(root_BST, 78);

    printf("\n ***** BST 출력 *****");
    displayInorder(root_BST);

    printf("\n BST에서 80 탐색 : ");
    searchTree(root_BST, 80);

    printf("\n BST에서 90 탐색 : ");
    searchTree(root_BST, 90);

    printf("\n BST에서 76 탐색 : ");
    searchTree(root_BST, 76);
}
