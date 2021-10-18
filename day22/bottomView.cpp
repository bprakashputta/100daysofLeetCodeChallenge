#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
    }
}

vector <int> bottomView(Node *root) {
    // Your Code Here
    vector<int> ans;
    if(!root)return ans;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    map<int,int> mp;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            mp[line] = node->data;
            if(node->left != NULL){
                q.push({node->left, line-1});
            }
            if(node->right!=NULL){
                q.push({node->right, line+1});
            }
        }
    }
    for(auto it:mp){
        ans.push_back(it.second);
    }
return ans;
}