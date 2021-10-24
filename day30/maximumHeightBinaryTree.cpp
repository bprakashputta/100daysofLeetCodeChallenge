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

int minimumHeight(TreeNode* root){
    int maxH = INT16_MIN;
    if(!root){
        return 0;
    }
    queue<pair<TreeNode*,int>>q;
    q.push({root,1});
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int height = it.second;
            if(node->left==NULL && node->right==NULL){
                if(maxH >= height){
                    maxH = height;
                }
            }
            if(node->left){
                q.push({node->left, height+1});
            }
            if(node->right){
                q.push({node->right, height+1});
            }
        }
    }
return maxH;
}