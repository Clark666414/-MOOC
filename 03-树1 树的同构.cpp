#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXSIZE 15

typedef struct doubleTree {
    char name;
    struct doubleTree* lchild;
    int lnumber;
    struct doubleTree* rchild;
    int rnumber;
} Node;

Node* iniNode(char c, char a, char b) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->name = c;
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    if (isdigit(a)) {
        newNode->lnumber = a - '0';
    } else {
        newNode->lnumber = -1;
    }
    if (isdigit(b)) {
        newNode->rnumber = b - '0';
    } else {
        newNode->rnumber = -1;
    }
    return newNode;
}

void creatTree(Node** root) {
    int n;
    scanf("%d", &n);
    // ���ĵ� scanf �����Ļ��з�
    getchar(); 

    if (n == 0) {
        // ������Ϊ�յ����
        *root = NULL; 
        return;
    }

    char s[MAXSIZE];
    Node* member[MAXSIZE];
    int isChild[MAXSIZE] = {0}; // ���ڱ�ǽڵ��Ƿ�Ϊ�ӽڵ�

    for (int i = 0; i < n; i++) {
        char temp1, temp2, temp3;
        fgets(s, MAXSIZE, stdin);
        s[strcspn(s, "\n")] = '\0';
        // ���� sscanf �Ĳ���Ϊ������ַ
        sscanf(s, "%c %c %c", &temp1, &temp2, &temp3); 
        member[i] = iniNode(temp1, temp2, temp3);
    }

    for (int i = 0; i < n; i++) {
        if (member[i]->lnumber >= 0) {
            member[i]->lchild = member[member[i]->lnumber];
            isChild[member[i]->lnumber] = 1;
        }
        if (member[i]->rnumber >= 0) {
            member[i]->rchild = member[member[i]->rnumber];
            isChild[member[i]->rnumber] = 1;
        }
    }

    // �ҳ����ڵ�
    for (int i = 0; i < n; i++) {
        if (!isChild[i]) {
            *root = member[i];
            break;
        }
    }
}

// �ж������������Ƿ�ͬ��
int isIsomorphic(Node* root1, Node* root2) {
    // �����������Ϊ�գ�ͬ��
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    // �������һ����Ϊ�գ���һ�ò�Ϊ�գ���ͬ��
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }
    // ������ڵ�ֵ��ͬ����ͬ��
    if (root1->name != root2->name) {
        return 0;
    }
    // �ݹ��ж��������
    return (isIsomorphic(root1->lchild, root2->lchild) && isIsomorphic(root1->rchild, root2->rchild)) ||
           (isIsomorphic(root1->lchild, root2->rchild) && isIsomorphic(root1->rchild, root2->lchild));
}

int main() {
    Node* root1;
    Node* root2;
    creatTree(&root1);
    creatTree(&root2);
    int ans = isIsomorphic(root1, root2);
    if (ans) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
