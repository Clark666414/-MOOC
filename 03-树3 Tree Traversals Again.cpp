#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 30

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 后序遍历，将结果存入数组
void postorderTraversal(TreeNode* root, int *arr, int *index) {
    if (root == NULL) return;
    postorderTraversal(root->left, arr, index);
    postorderTraversal(root->right, arr, index);
    arr[(*index)++] = root->data;
}

void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();  // 消耗掉 scanf 后的换行符

    TreeNode* stack[MAX_N];
    int top = -1;
    TreeNode* root = NULL;
    TreeNode* prev = NULL;

    for (int i = 0; i < 2 * n; i++) {
        char op[20];
        fgets(op, sizeof(op), stdin);
        op[strcspn(op, "\n")] = '\0';  // 去除换行符

        if (strstr(op, "Push") != NULL) {
            int data;
            sscanf(op, "Push %d", &data);
            TreeNode* newNode = createNode(data);
            if (root == NULL) {
                root = newNode;
            } else if (prev != NULL && prev->left == NULL) {
                prev->left = newNode;
            } else if (prev != NULL && prev->right == NULL) {
                prev->right = newNode;
            }
            stack[++top] = newNode;
            prev = newNode;
        } else {
            prev = stack[top--];
        }
    }

    int postorder[MAX_N];
    int idx = 0;
    postorderTraversal(root, postorder, &idx);

    // 输出后序遍历结果
    for (int i = 0; i < idx; i++) {
        if (i != 0) printf(" ");
        printf("%d", postorder[i]);
    }
    printf("\n");

    freeTree(root);

    return 0;
}
