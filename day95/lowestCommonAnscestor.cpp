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

bool findRootToNodePath(BinaryTreeNode<int>* root, int n, vector<int>& path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data == n){
        return true;
    }
    if(findRootToNodePath(root->left, n, path) || findRootToNodePath(root->right, n, path) ){
		return true;
    }
    path.pop_back();
return false;
}

BinaryTreeNode<int>* findRootNodeOfN(BinaryTreeNode<int>* root, int n){
    if(root==NULL || root->data == n){
        return root;
    }
    
    BinaryTreeNode<int>* left = findRootNodeOfN(root->left, n);
    BinaryTreeNode<int>* right = findRootNodeOfN(root->right, n);

    if(left==NULL){
        return right;
    }else if(right==NULL){
        return left;
    }
    return root;
}

BinaryTreeNode<int>* solve(BinaryTreeNode<int>* root, int n1, int n2, int n3){
    if(root==NULL || root->data==n1 || root->data==n2 || root->data==n3){
        return root;
    }
    
    vector<int> n1Path;
    findRootToNodePath(root, n1, n1Path);
    vector<int> n2Path;
    findRootToNodePath(root, n2, n2Path);
    vector<int> n3Path;
    findRootToNodePath(root, n3, n3Path);
	
    int i=0;
    int n=0;
	while(i<n1Path.size() && i<n2Path.size() && n3Path.size()){
        if(n1Path[i]==n2Path[i] && n2Path[i]==n3Path[i]){
            n = n1Path[i];
        	i++;
        }else {
            break;
        }
    }

return findRootNodeOfN(root, n);
}


BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
    // Write your code here.
    if(root==NULL){
        return root;
    }
    // The idea is to use recursion and traverse the tree
    return solve(root, node1, node2, node3);
}
