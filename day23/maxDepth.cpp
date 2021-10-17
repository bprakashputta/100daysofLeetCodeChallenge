#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};


int maxDepth(TreeNode* root) {
    if(root == NULL){
        return 0;
    }else if(root!=NULL && root->left==NULL && root->right==NULL){
        return 1;
    }
    
    int l = 1+maxDepth(root->left);
    int r = 1+maxDepth(root->right);
    if(l>r){
        return l;
    }else{
        return r;
    }
return -1;
}

int maxDepth(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }

    int left = 1+maxDepth(root->left);
    int right = 1+maxDepth(root->right);
return max(left,right);
}