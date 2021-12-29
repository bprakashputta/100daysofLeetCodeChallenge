#include<iostream>
#include<vector>
using namespace std;

template <typename T>
class BinaryTreeNode {
public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};


int solve(BinaryTreeNode<int>* root, int& mx_len){
    if(root==NULL){
        return 0;
    }
    int l1=0,l2=0, mxl=0, mxr=0;
    if(root->left!=NULL){
        l1 = solve(root->left, mx_len);
    }else{
        l1=0;
    }

    if(root->right!=NULL){
        l2 = solve(root->right, mx_len);
    }else{
        l2=0;
    }

    if(root->left!=NULL && root->data==root->left->data){
        mxl= l1+1;
    }else{
        mxl=0;
    }

    if(root->right!=NULL && root->data==root->right->data){
        mxr= l2+1;
    }else{
        mxr=0;
    }

    mx_len = max({mxl+mxr, mx_len});
    return max({ mxl, mxr});
}

int longestUnivaluePath(BinaryTreeNode<int> *root) {
    // Write yout code here
    // return maximum Longest Path Value
    if(root==NULL){
        return 0;
    }
    int mx_len=0;
    solve(root, mx_len);
    return mx_len;    
}