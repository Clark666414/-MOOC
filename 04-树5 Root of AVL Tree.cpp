#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int num;
	int height;
	struct node* left;
	struct node* right;
}node; 

int getHeight(node* root)
{
	if(root == NULL){
		return 0;
	}
	return root->height;
}

int getAVL(node* root)
{
	if(root == NULL){
		return 0;
	}
	return getHeight(root->left) - getHeight(root->right);
}

node* rootRight(node* root)
{
	node* newroot = root->left;
	root->left = newroot->right;
	newroot->right = root;
	
	root->height = 1 + (getHeight(root->left) > getHeight(root->right)? getHeight(root->left) : getHeight(root->right));
    newroot->height = 1 + (getHeight(newroot->left) > getHeight(newroot->right)? getHeight(newroot->left) : getHeight(newroot->right));
	return newroot;
}

node* rootLeft(node* root) {
    node* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    root->height = 1 + (getHeight(root->left) > getHeight(root->right)? getHeight(root->left) : getHeight(root->right));
    newRoot->height = 1 + (getHeight(newRoot->left) > getHeight(newRoot->right)? getHeight(newRoot->left) : getHeight(newRoot->right));

    return newRoot;
}

node* insert(node* root, int data) {
    if (root == NULL) {
        root = (node*)malloc(sizeof(node));
        root->num = data;
        root->left = root->right = NULL;
        root->height = 1;
    } else if (data < root->num) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    root->height = 1 + (getHeight(root->left) > getHeight(root->right)? getHeight(root->left) : getHeight(root->right));

    int balanceFactor = getAVL(root);

    // Left Left Case
    if (balanceFactor > 1 && data < root->left->num) {
        return rootRight(root);
    }
    // Right Right Case
    if (balanceFactor < -1 && data > root->right->num) {
        return rootLeft(root);
    }
    // Left Right Case
    if (balanceFactor > 1 && data > root->left->num) {
        root->left = rootLeft(root->left);
        return rootRight(root);
    }
    // Right Left Case
    if (balanceFactor < -1 && data < root->right->num) {
        root->right = rootRight(root->right);
        return rootLeft(root);
    }

    return root;
}

int main() {
    int n, data;
    scanf("%d", &n);

    node* root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("%d\n", root->num);

    return 0;
}
