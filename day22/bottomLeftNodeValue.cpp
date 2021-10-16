#include<iostream>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
    }
};

// The logic for the solution is that, we traverse the Tree 
// starting with right node, and then left
// in this method we will reach the bottom left node
int bottomLeftNodeValue(TreeNode* root){
    if(!root){
        return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* node;
    while(!q.empty()){
        node = q.front();
        q.pop();
        if(node->right!=NULL){
            q.push(node->right);
        }
        if(node->left!=NULL){
            q.push(node->left);
        }
    }
return node->val;
}