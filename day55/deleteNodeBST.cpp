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

TreeNode* minValNode(TreeNode* node){
    TreeNode* curr = node;
    while(curr && curr->left!=NULL){
        curr = curr->left;
    }
return curr;
}

TreeNode* deleteNode(TreeNode* root, int x){
    if(root == NULL){
        return NULL;
    }
    if(root->data == x){
        if(root->left==NULL && root->right==NULL){
            return NULL;
        }else if(root->left==NULL && root->right!=NULL){
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }else if(root->left!=NULL && root->right==NULL){
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }else{
            TreeNode* temp = minValNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    else if(root->data > x){
        root->left = deleteNode(root->left, x);
    }
    else if(root->data < x){
        root->right = deleteNode(root->right, x);
    }
return root;
}

int main(){
    // vector<int> arr(10);
    struct TreeNode* root = NULL;
    for(int i=0; i<10; i++){
        int x = 1+rand()%50;
        // cout<<x<<endl;
        if(i==0){
            cout<<"Head: "<<x<<endl;
            root = insertintoBST(root, x);
        }
        insertintoBST(root, x);
        // cout<<"Hi"<<endl;
    }
    inorder(root);
    cout<<endl;
    root = deleteNode(root, 18);
    inorder(root);
return 0;
}