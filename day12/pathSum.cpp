#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool hasPathSum(TreeNode* root, int targetSum) {
    if(root == NULL){
        return 0;
    }
    
    bool ans = 0;
    int sub = targetSum - root->val;
    if(sub==0 && root->left==NULL && root->right==0){
        return 1;
    }
    
    if(root->left != NULL){
        ans = ans || hasPathSum(root->left, sub);
    }
    
    if(root->right != NULL){
        ans = ans || hasPathSum(root->right, sub);
    }
return ans;
}
