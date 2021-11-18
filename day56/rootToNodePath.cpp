#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool rootToNodePath(TreeNode* root, int x, vector<int> &path){
    if(root==NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data == x){
        return true;
    }
    if(rootToNodePath(root->left, x, path) || rootToNodePath(root->right, x, path)){
        return true;
    }
    path.pop_back();
    
return false;
}

int main(){
    for(int i=0; i<)
}