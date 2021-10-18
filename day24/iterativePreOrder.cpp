#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
    }
};

vector<int> iterativePreOrder(TreeNode* root){
    vector<int> ans;
    if(!root)return ans;
    stack<TreeNode*>stk;
    stk.push(root);
    while(!stk.empty()){
        root = stk.top();
        stk.pop();
        ans.push_back(root->val);
        if(root->right!=NULL){
            stk.push(root->right);
        }
        if(root->left!=NULL){
            stk.push(root->left);
        }
    }
return ans;
}

