#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int maxDepth(TreeNode* root){
    if(root == NULL){
        return 0;
    }else if(root!=NULL && root->left==NULL && root->right){
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