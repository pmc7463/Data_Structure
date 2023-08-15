#include <stdio.h>
#include <stdlib.h>

typedef char element;   // ���� Ž�� Ʈ�� element�� �ڷ����� char�� ����
typedef struct treeNode {
    char key;   // ������ �ʵ�
    struct treeNode *left;  // ���� ���� Ʈ�� ��ũ �ʵ�
    struct treeNode *right; // ������ ���� Ʈ�� ��ũ �ʵ�
} treeNode;

// ���� Ž�� Ʈ������ Ű���� x�� ����� ��ġ�� Ž���ϴ� ����
treeNode *searchBST(treeNode *root, char x){
    treeNode *p;
    p = root;
    while (p != NULL){
        if (x < p -> key) p = p -> left;    // p -> key�� ��Ʈ�� ��, x�� ���� ã�����ϴ� ��
        else if( x == p -> key) return p;
        else p = p -> right;
    }
    printf("\n ã�� Ű�� �����ϴ�! ");
    return p;
}

// ������ p�� ����Ű�� ���� ���Ͽ� ��� x�� �����ϴ� ����
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
    else printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n");

    return p;
}

//��Ʈ ������ Ž���Ͽ� Ű���� ���� ��带 ã�� �����ϴ� ����
void deleteNode(treeNode *root, element key){
    treeNode *parent, *p, *succ, *succ_parent;
    treeNode *child;
    parent = NULL;
    p = root;
    while ((p != NULL) && (p -> key != key)){   //������ ����� ��ġ Ž��
        parent = p;
        if (key < p -> key) p = p -> left;
        else p = p -> right;
    }

    // ������ ��尡 ���� ���
    if( p == NULL){
        printf("\nã�� Ű�� ���� Ʈ���� �����ϴ�!!");
        return;
    }

    // ������ ��尡 �ܸ� ����� ���
    if((p -> left == NULL) && (p -> right == NULL)) {
        if(parent != NULL){
            if(parent -> left == p) parent -> left = NULL;
            else parent -> right = NULL;
        }
        else root = NULL;
    }

    // ������ ��尡 �ڽ� ��带 �� �� ���� ���
    else if ((p -> left == NULL) || (p -> right == NULL)) {
        if (p -> left != NULL) child = p -> left;
        else child = p -> right;
    
        if(parent != NULL){
            if (parent -> left == p) parent -> left = child;
            else parent -> right = child;
        }
        else root = child;
    }

    // ������ ��尡 �ڽ� ��带 �� �� ���� ���
    else {
        succ_parent = p;
        succ = p -> left;
        while (succ -> right != NULL){      //���� ���� Ʈ������ �İ��� ã��
            succ_parent = succ; //���������� �������� ���� �ö� �ּ� ���ܳ��� ����
            succ = succ -> right;   // ���������� ã���� ��������
        }
        if(succ_parent -> left == succ) succ_parent -> left = succ -> left;
        // ���� ���� �Դٴ°� ������ ������ �������ٴ� ��
        else succ_parent -> right = succ -> left;
        // succ�θ����� �������� ������ ���(ex��Ʈ ���) �� �ڸ��� succ�� ������ ���� 
        p -> key = succ -> key;
        p = succ;
    }
    free(p);
}

//���� Ž�� Ʈ���� ���� ��ȸ �ϸ鼭 ����ϴ� ����
void displayInorder(treeNode *root){
    if (root){
        displayInorder(root -> left);
        printf("%c",root -> key);
        displayInorder(root -> right);
    }
}

void menu(){
    printf("\n------------------");
    printf("\n\t1 : Ʈ�� ���");
    printf("\n\t2 : ���� ����");
    printf("\n\t3 : ���� ����");
    printf("\n\t4 : ���� �˻�");
    printf("\n\t5 : ����");
    printf("\n------------------");
    printf("\n�޴� �Է� >>");
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
            case 1: printf("/t[���� Ʈ�� ���");
                displayInorder(root);
                printf("\n");
                break;

            case 2: printf("������ ���ڸ� �Է��ϼ��� : ");
                scanf(" %c", &key);
                insertNode(root, key);
                break;
            
            case 3: printf("������ ���ڸ� �Է��ϼ��� : ");
                scanf(" %c", &key);
                deleteNode(root, key);
                break;

            case 4: printf("ã�� ���ڸ� �Է��ϼ��� : ");
                scanf(" %c", &key);
                foundedNode = searchBST(root, key);
                if (foundedNode != NULL)
                    printf("\n %c�� ã�ҽ��ϴ�! \n", foundedNode -> key);
                else
                    printf("\n ���ڸ� ã�� ���߽��ϴ�.\n");
                break;

            case 5: return 0;

            default: printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���! \n");
                break;
        }
    }
}

