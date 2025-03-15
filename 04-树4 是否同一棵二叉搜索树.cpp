#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 20

// ����������ڵ�ṹ��
typedef struct Node {
    int num;
    struct Node* left;
    struct Node* right;
} node;

// �ͷŶ������ڴ�ĺ���
void freeTree(node* root) {
    if (root == NULL) return;
    freeTree(root->left);   
    freeTree(root->right);  
    free(root);             
}

// �Ƚ��������Ƿ�ͬ�������ǽڵ�ֵ
int cmpTree(node* root1, node* root2) {
    // ����������Ϊ�գ���Ϊͬ��
    if (root1 == NULL && root2 == NULL) {
        return 1;
    }
    // ������һ����Ϊ�գ���һ�ò�Ϊ�գ���ͬ��
    if (root1 == NULL || root2 == NULL) {
        return 0;
    }
    // �����ڵ�ֵ��ͬ����ͬ��
    if (root1->num != root2->num) {
        return 0;
    }
    // �ݹ�Ƚ���������������
    return (cmpTree(root1->left, root2->left) && cmpTree(root1->right, root2->right));
}

// ��������в���ڵ�ĺ���
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
        // ������һ����
        node* root1 = NULL;
        for (int i = 0; i < N; i++) {
            scanf("%d", &temp);
            root1 = insertNode(root1, temp);
        }

        // ����ÿ���������
        for (int i = 0; i < L; i++) {
            node* root2 = NULL;
            for (int j = 0; j < N; j++) {
                scanf("%d", &temp);
                root2 = insertNode(root2, temp);
            }

            // �ж��Ƿ�ͬ����������
            int ans = cmpTree(root1, root2);
            printf(ans ? "Yes\n" : "No\n");

            // �ͷŵڶ��������ڴ�
            freeTree(root2);
        }

        // �ͷŵ�һ�������ڴ�
        freeTree(root1);
    }

    return 0;
}    
