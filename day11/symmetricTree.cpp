#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool check(TreeNode* root1, TreeNode* root2){
    if(!root1 && !root2){
        return true;
    }
    if(root1==NULL && root2!=NULL){
        return false;
    }else if(root1!=NULL && root2==NULL){
        return false;
    }
    if(root1->val != root2->val){
        return false;
    }
    
    bool b1 = check(root1->left, root2->right);
    if(!b1){
        return false;
    }
    bool b2 = check(root1->right, root2->left);
    if(b1&&b2){
        return true;
    }
return false;
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL){
        return true;
    }else if(root!=NULL && root->left==NULL && root->right==NULL){
        return true;
    }
    
    return check(root->left, root->right);   
}
