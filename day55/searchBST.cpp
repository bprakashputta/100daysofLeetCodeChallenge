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

int searchBST(TreeNode* root, int x){
    if(root==NULL){
        return -1;
    }
    if(root->data == x){
        return x;
    } 
    int vl = 0;
    if(root->data > x){
        vl = searchBST(root->left, x);
    }
    if(root->data < x){
        vl = searchBST(root->right, x);
    }
return vl;
}

int main(){
    // vector<int> arr(10);
    struct TreeNode* root = NULL;
    int x;
    for(int i=0; i<10; i++){
        x = 1+rand()%50;
        // cout<<x<<endl;
        if(i==0){
            root = insertintoBST(root, x);
        }
        insertintoBST(root, x);
        // cout<<"Hi"<<endl;
    }
    inorder(root);
    cout<<x<<endl;
    cout<<searchBST(root, x)<<endl;
return 0;
}