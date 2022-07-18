#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX(a, b) ((a > b) ? a:b)   //(a > b) ��/���� �Ǻ� ?, ���̸� a, �����̸� b : ���׿�����

typedef int element;

typedef struct treeNode {
    element key;
    struct treeNode *left;
    struct treeNode *right;
}treeNode;

treeNode *LL_rotate(treeNode *parent){
    treeNode *child = parent -> left;   //�θ����� ���ʿ� ����� �ּҷ� ���� child ��带 ����?
    parent -> left = child -> right;    //�ڽ� ����� ������ �ּҸ� �θ� ����� ���ʿ� ����
    child -> right = parent;            //�θ��带 �ڽ��� ������ ���� �ű��,����
    //�׸������� ������ �ڽ� ��尡 0 �θ��尡 1, �θ� �ڽ� ������ ���ɷ� ����
    return child;
}

treeNode *RR_rotate(treeNode *parent){
    treeNode *child = parent -> right;  //�θ����� �����ʿ� ����� �ּҷ� ���� child ��带 ����
    parent -> right = child -> left;    //�ڽ��� �����ּҸ� �θ����� �����ʿ� ����
    child -> left = parent;             //�θ��带 �ڽĳ���� ���ʿ� �ű�
    return child;
}

treeNode *LR_rotate(treeNode *parent){
    treeNode *child = parent -> left;  //�θ����� ���ʿ� ����� �ּҷ� ���� child ��带 ����
    parent -> left = RR_rotate(child); //rrȸ���� �����Ͽ� ��ȯ�� ��带 �θ����� ���ʿ� ���� 
    return LL_rotate(child);           //���������� llȸ�� �Ѵ�. 
}

treeNode *RL_rotate(treeNode *parent){
    treeNode *child = parent -> right;  //�θ����� �����쿡 ����� �ּҷ� ���� child ��带 ����
    parent -> right = LL_rotate(child); //llȸ���� �����Ͽ� ��ȯ�� ��带 �θ����� ���ʿ� ����
    return RR_rotate(child);    
}

// ���� Ʈ���� ���̸� ���ϴ� ����
int getHeight(treeNode *p){
    int height = 0;
    if(p != NULL)
        height = MAX(getHeight(p -> left), getHeight(p -> right)) +1;
    //������ A,�������� B ���߿� �����ؼ� +1 �ϱ�
    return height;
}

//���� Ʈ���� ���̸� �̿��� �����μ� BF�� ���ϴ� ����
int getBF(treeNode *p){
    if (p == NULL) return 0;
    return getHeight(p -> left) - getHeight(p -> right);// ���� - ������
}

//BF�� �˻��Ͽ� �ұ����� �߻��� ���, ȸ�� ���� ȣ��
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

//AVL Ʈ���� ��带 �����ϴ� ����
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
        printf("\n �̹� ���� Ű�� �ֽ��ϴ�.\n");
        exit(1);
    }
    return *root;
}

//���� Ž�� Ʈ���� ��带 �����ϴ� ����
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
        printf("\n�̹� ���� Ű�� �ֽ��ϴ�.\n");

    return p;
}

//���� Ž�� Ʈ���� AVL Ʈ������ Ű�� x�� Ž���ϴ� ����
treeNode *searchTree(treeNode *root, element x) {
    treeNode *p;
    int count = 0;
    p = root;
    while (p != NULL){
        count++;
        if(x < p -> key)
            p = p -> left;
        else if (x == p -> key){
            printf("%3d��°�� Ž�� ����", count);
            return p;
        }
        else
            p = p -> right;
    }
    count++;
    printf("%3d��°�� Ž�� ����! ã�� Ű�� �����ϴ�.", count);
    return p;
}

//���� Ž�� Ʈ���� ���� ��ȸ �ϸ鼭 ����ϴ� ����
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

    root_AVL = insert_AVL_Node(&root_AVL, 50);  //AVLƮ�� �����
    insert_AVL_Node(&root_AVL, 60);
    insert_AVL_Node(&root_AVL, 70);
    insert_AVL_Node(&root_AVL, 90);
    insert_AVL_Node(&root_AVL, 80);
    insert_AVL_Node(&root_AVL, 75);
    insert_AVL_Node(&root_AVL, 73);
    insert_AVL_Node(&root_AVL, 72);
    insert_AVL_Node(&root_AVL, 78);

    printf("\n ***** AVL Ʈ�� ��� *****\n");
    displayInorder(root_AVL);

    printf("\n AVL Ʈ������ 80 Ž�� : ");
    searchTree(root_AVL, 80);

    printf("\n AVL Ʈ������ 90 Ž�� : ");
    searchTree(root_AVL, 90);

    printf("\n AVL Ʈ������ 76 Ž�� : ");
    searchTree(root_AVL, 76);

    root_BST = insert_AVL_Node(&root_BST, 50);  //BST �����
    insert_BST_Node(root_BST, 60);
    insert_BST_Node(root_BST, 70);
    insert_BST_Node(root_BST, 90);
    insert_BST_Node(root_BST, 80);
    insert_BST_Node(root_BST, 75);
    insert_BST_Node(root_BST, 73);
    insert_BST_Node(root_BST, 72);
    insert_BST_Node(root_BST, 78);

    printf("\n ***** BST ��� *****\n");
    displayInorder(root_BST);

    printf("\n BST���� 80 Ž�� : ");
    searchTree(root_BST, 80);

    printf("\n BST���� 90 Ž�� : ");
    searchTree(root_BST, 90);

    printf("\n BST���� 76 Ž�� : ");
    searchTree(root_BST, 76);
}
