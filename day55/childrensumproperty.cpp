#include<iostream>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x){
        this->data = x;
        left = NULL;
        right = NULL; 
    }
};

void childSumProperty(TreeNode* root){
    if(root==NULL){
        return;
    }

    int child = 0;
    if(root->left){
        child += root->left->data;
    }
    if(root->right){
        child += root->right->data;
    }

    if(child>=root->data){
        root->data = child;
    }else{
        if(root->left){
            root->left->data = root->data;
        }
        if(root->right){
            root->right->data = root->data;
        }
    }

    childSumProperty(root->left);
    childSumProperty(root->right);

    int total = 0;
    if(root->left){
        total += root->left->data;
    }
    if(root->right){
        total += root->right->data;
    }
    if(root->left || root->right)
    {
        root->data = total;
    }
}

