#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treeNode{    //������ ���� Ʈ���� ��� ����
    char data;
    struct treeNode *left;  //���� ���� Ʈ���� ���� ��ũ �ʵ�
    struct treeNode *right; //������ ���� Ʈ���� ���� ��ũ �ʵ�
    int isThreadRight;      //�ļ��ڿ� ���� ������ �±� �ʵ�
} treeNode;

//data�� ��Ʈ ���� �Ͽ� ���� ���� Ʈ���� ������ ���� Ʈ���� �����ϴ� ����
treeNode *makeRootNode(char data, treeNode *leftNode, treeNode *rightNode, int isThreadRight){
    treeNode *root = (treeNode*)malloc(sizeof(treeNode));
    root -> data = data;
    root -> left = leftNode;
    root -> right = rightNode;
    root -> isThreadRight = isThreadRight;
    return root;
}

//�ļ��� ��带 ��ȯ�ϴ� ����
treeNode *findThreadSuccessor(treeNode *p){
    treeNode *q = p -> right;
    if(q == NULL) return q;     // �����尡 null�̹Ƿ� �ļ��ڰ� ���ٴ� ��, null��ȯ? �³�?
    if(p -> isThreadRight == 1) return q;   //���� ��� p�� isThreadRight�� ���̸� ������ ��ũ �ʵ尪�� �ļ��� �����尡 �ȴ�. �̷���쿡�� �ļ��� �������� q�� ��ȯ�Ѵ�.
    while(q -> left != NULL) q = q -> left; //�������� ������ �ڽ��� �ִ°�� >> ���������� ���� ���� ���������� q ��ȯ
    return q;       
}

//������ ���� Ʈ���� ���� ��ȸ
void threadIndorder(treeNode *root){
    treeNode *q;
    q = root;
    while (q -> left) q = q -> left;    // ���� ��ȸ�� �����ϱ� ���� ���� ������ ���°���
    do{
        printf("%3c", q -> data);
        q = findThreadSuccessor(q);
    } while(q); //q�� �ִ� ���� ������ȸ �ݺ�
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

    printf("\n ������ ���� Ʈ���� ���� ��ȸ : ");
    threadIndorder(n1);

}