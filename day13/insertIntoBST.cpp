#include<iostream>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insertIntoBST(TreeNode* root, int val){
    if(root == NULL){
        return new TreeNode(val);
    }

    if(root->data > val){
        root->left = insertIntoBST(root->left, val);
    }else{
        root->right = insertIntoBST(root->right, val);
    }
return root;
}