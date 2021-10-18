#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


void solve(TreeNode* root, vector<int> &arr){
    if(root == NULL){
        return;
    }
    solve(root->left, arr);
    solve(root->right, arr);
    arr.push_back(root->val);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> arr;
    solve(root, arr);
return arr;
}