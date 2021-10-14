#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
    Tree(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

vector<int> topView(struct Node* root){
    vector<int> ans;
    // Checking if root is NULL
    if(root==NULL){
        return ans;
    }
    // Map to store the top view as
    //  key-value pair of node and line
    map<int, int> mp;
    // queue to push the tree contents into 
    queue<pair<struct Node*, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        struct Node* node = it.first;
        int line = it.second;
        if(mp.find(line)==mp.end()){
            mp[line] = node->val;
        } 

        if(node->left!=NULL){
            q.push({node->left, line-1});
        }
        if(node->right!=NULL){
            q.push({node->right, line+1});
        }
    }

    for(auto it : mp){
        ans.push_back(it.second);
    }   

return ans;
}