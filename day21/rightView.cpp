#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
    }
};

vector<int> rightView(TreeNode* root){
    vector<int> ans;
    if(!root){
        return ans;
    }
    map<int, int>mp;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
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

            if(node->right){
                q.push({node->right, height+1});
            }
            if(node->left){
                q.push({node->left, height+1});
            }
        }
    }
    for(auto it:mp){
        ans.push_back(it.second);
    }
return ans;
}