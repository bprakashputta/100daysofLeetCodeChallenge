#include<iostream>
#include<queue>
#include<map>
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

vector<int> leftView(TreeNode* root){
    vector<int> ans;
    if(!root){
        return ans;
    }
    
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    map<int,int> mp;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int height = it.second;
            if(mp.find(height)==mp.end()){
                mp[height] = node->val;
            }

            if(node->left!=NULL){
                q.push({node->left,height+1});
            }
            if(node->right!=NULL){
                q.push({node->right, height+1});
            }
        }
    }
    for(auto it:mp){
        ans.push_back(it.second);
    }
return ans;
}