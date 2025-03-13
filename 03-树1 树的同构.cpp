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
    // 消耗掉 scanf 遗留的换行符
    getchar(); 

    if (n == 0) {
        // 处理树为空的情况
        *root = NULL; 
        return;
    }

    char s[MAXSIZE];
    Node* member[MAXSIZE];
    int isChild[MAXSIZE] = {0}; // 用于标记节点是否为子节点

    for (int i = 0; i < n; i++) {
        char temp1, temp2, temp3;
        fgets(s, MAXSIZE, stdin);
        s[strcspn(s, "\n")] = '\0';
        // 修正 sscanf 的参数为变量地址
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

    // 找出根节点
    for (int i = 0; i < n; i++) {
        if (!isChild[i]) {
            *root = member[i];
            break;
        }
    }
}

// 判断两个二叉树是否同构
int isIsomorphic(Node* root1, Node* root2) {
    // 如果两棵树都为空，同构
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    // 如果其中一棵树为空，另一棵不为空，不同构
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }
    // 如果根节点值不同，不同构
    if (root1->name != root2->name) {
        return 0;
    }
    // 递归判断两种情况
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
