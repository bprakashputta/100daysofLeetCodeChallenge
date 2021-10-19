#include<iostream>
#include<vector>
using namespace std;

// /**
//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//  */
class Solution {
public:
    void solve(TreeNode* root, vector<int>& inorder){
        if(root==NULL){
            return;
        }
        solve(root->left, inorder);
        inorder.push_back(root->val);
        solve(root->right, inorder);
    }
    
    bool findTarget(TreeNode* root, int target) {
        if(root==NULL)return false;
        vector<int> inorder;
        solve(root, inorder);
        int l=0, r=inorder.size()-1;
        while(l<r){
            if(inorder[l] + inorder[r] == target){
                return true;
            }else if(inorder[l] + inorder[r] > target){
                r--;
            }else{
                l++;
            }
        }
    return false;
    }
};