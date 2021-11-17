#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* insertintoBST(TreeNode* root, int x){
    if(root==NULL){
        return new TreeNode(x);
    }

    if(root->data < x){
        root->right = insertintoBST(root->right, x);
    }
    if(root->data > x){
        root->left = insertintoBST(root->left, x);
    }
return root;
}

void inorder(TreeNode* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<< ", ";
    inorder(root->right);
}

int main(){
    // vector<int> arr(10);
    struct TreeNode* root = NULL;
    for(int i=0; i<10; i++){
        int x = 1+rand()%50;
        // cout<<x<<endl;
        if(i==0){
            root = insertintoBST(root, x);
        }
        insertintoBST(root, x);
        // cout<<"Hi"<<endl;
    }
    inorder(root);
return 0;
}