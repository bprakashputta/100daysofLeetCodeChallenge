#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

TreeNode* invertTree(TreeNode* root){
    if(root==NULL){
        return root;
    }else if(root!=NULL && root->left!=NULL && root->right!=NULL){
        return root;
    }

    invertTree(root->left);
    invertTree(root->right);
    TreeNode* temp = root;
    TreeNode* alpha = temp->left;
    temp->left = temp->right;
    temp->right = alpha;
return root;
}