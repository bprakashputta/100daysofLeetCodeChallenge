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

vector<int> iterativeInOrder(TreeNode* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    TreeNode* node = root;
    stack<TreeNode*>stk;
    stk.push(node);
    while(true){
        // while node is not null
        // go left
        if(node!=NULL){
            stk.push(node);
            node = node->left;
        }else{
        // else go right
        // assign top to node
        // pop top of stack
            if(stk.empty()==true)break;
            node = stk.top();
            stk.pop();
            ans.push_back(node->val);
            node = node->right;
        }
    }
return ans;
}