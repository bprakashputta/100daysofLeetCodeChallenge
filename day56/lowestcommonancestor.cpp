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

TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q){
    if(root==NULL || root == p || root == q){
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left==NULL){
        return right;
    }else if(right == NULL){
        return left;
    }else{
        return root;
    }
return root;
}
