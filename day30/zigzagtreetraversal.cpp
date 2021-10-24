#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x){
        val = x;
    }
};


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    queue<TreeNode*>q;
    q.push(root);
    // map<pair<TreeNode*, int>>mp;
    
    // 1,  zig push 
    // 3,2, zag 
    // 4,5,6,7, zig     
    // 15,14,13,12,11,10,9,8 zag
    // The logic is reverse the queue after each level
    // for zig push root->left, root->right
    // for zag push root->right, root->left 
    int flag = 0;
    while(!q.empty()){
        int size = q.size();
        vector<int> zigzag;
        for(int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();
            zigzag.push_back(node->val);
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
        // push the zigzag vector into ans vector 
        if(flag==0){
            ans.push_back(zigzag);
            flag = 1;
        }else{
            // Now reverse the queue inorder to print zig-zag pattern
            reverse(zigzag.begin(), zigzag.end());
            ans.push_back(zigzag);
            flag = 0;
        }          
        
    }
return ans;
}


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    queue<TreeNode*>q;
    q.push(root);
    // map<pair<TreeNode*, int>>mp;
    
    // 1,  zig push 
    // 3,2, zag 
    // 4,5,6,7, zig     
    // 15,14,13,12,11,10,9,8 zag
    // The logic is reverse the queue after each level
    // for zig push root->left, root->right
    // for zag push root->right, root->left 
    int flag = 0;
    while(!q.empty()){
        int size = q.size();
        vector<int> zigzag(size);
        for(int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();
            int index;
            if(flag == 0){
                index = i;
            }else{
                index = size-i-1;
            }
            zigzag[index] = node->val;
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
        // push the zigzag vector into ans vector 
        if(flag==0){
            // ans.push_back(zigzag);
            flag = 1;
        }else{
            // Now reverse the queue inorder to print zig-zag pattern
            // reverse(zigzag.begin(), zigzag.end());
            // ans.push_back(zigzag);
            flag = 0;
        }          
        ans.push_back(zigzag);
    }
return ans;
}
