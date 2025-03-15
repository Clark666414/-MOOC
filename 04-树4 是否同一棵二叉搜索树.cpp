#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 20

// 定义二叉树节点结构体
typedef struct Node {
    int num;
    struct Node* left;
    struct Node* right;
} node;

// 释放二叉树内存的函数
void freeTree(node* root) {
    if (root == NULL) return;
    freeTree(root->left);   
    freeTree(root->right);  
    free(root);             
}

// 比较两棵树是否同构，考虑节点值
int cmpTree(node* root1, node* root2) {
    // 若两棵树都为空，认为同构
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    // 若其中一棵树为空，另一棵不为空，不同构
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }
    // 若根节点值不同，不同构
    if (root1->num != root2->num) {
        return 0;
    }
    // 递归比较左子树和右子树
    return (cmpTree(root1->left, root2->left) && cmpTree(root1->right, root2->right));
}

// 向二叉树中插入节点的函数
node* insertNode(node* p, int item) {
    if (p == NULL) {
        p = (node*)malloc(sizeof(node));
        p->num = item;
        p->left = p->right = NULL;
    } else if (item < p->num) {
        p->left = insertNode(p->left, item);
    } else {
        p->right = insertNode(p->right, item);
    }
    return p;
}

int main() {
    int N, L;
    int temp;
    while (scanf("%d",&N) != EOF) {
    	if(N == 0){
    		break;
		}
		scanf("%d",&L);
        // 创建第一棵树
        node* root1 = NULL;
        for (int i = 0; i < N; i++) {
            scanf("%d", &temp);
            root1 = insertNode(root1, temp);
        }

        // 处理每组测试用例
        for (int i = 0; i < L; i++) {
            node* root2 = NULL;
            for (int j = 0; j < N; j++) {
                scanf("%d", &temp);
                root2 = insertNode(root2, temp);
            }

            // 判断是否同构并输出结果
            int ans = cmpTree(root1, root2);
            printf(ans ? "Yes\n" : "No\n");

            // 释放第二棵树的内存
            freeTree(root2);
        }

        // 释放第一棵树的内存
        freeTree(root1);
    }

    return 0;
}    
