#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* searchBST(TreeNode* root, int val){
    if(root==NULL){
        return root;
    }
    TreeNode* ptr = root;
    while(ptr !=NULL){
        if(ptr->val == val){
            return ptr;
        }else if(ptr->val > val){
            ptr = ptr->left;
        }else{
            ptr = ptr->right;
        }
    }
return NULL;
}