#include<iostream>
#include<queue>
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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root){
        return ans;
    }
    queue<pair<TreeNode*, int>> q;
    q.push({root, 1});
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0; i<size; i++){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int height = it.second;
            level.push_back(node->val);
            if(node->left){
                q.push({node->left,height+1});
            }
            if(node->right){
                q.push({node->right, height+1});
            }
        }
        ans.push_back(level);
    }
    reverse(ans.begin(), ans.end());
return ans;
}