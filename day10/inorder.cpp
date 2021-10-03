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
    arr.push_back(root->val);
    solve(root->right, arr);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> arr;
    solve(root, arr);
return arr;
}