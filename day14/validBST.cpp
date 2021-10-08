#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void solve(TreeNode* root, vector<int> &arr){
    if(root==NULL){
        return;
    }
    solve(root->left, arr);
    arr.push_back(root->val);
    solve(root->right, arr);
}

bool validBST(TreeNode* root, int val){
    vector<int> arr;
    solve(root, arr);

    for(int i=0; i<arr.size(); i++){
        if(arr[i] >= arr[i+1]){
            return false;
        }
    }
return true;
}