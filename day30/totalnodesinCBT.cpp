#include<iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int leftH(TreeNode* root){
        int height =0;
        while(root){
            height++;
            root = root->left;
        }
    return height;
    }
    
    int rightH(TreeNode* root){
        int height =0;
        while(root){
            height++;
            root = root->right;
        }
    return height;
    }
    
    int countNodes(TreeNode* root) {
        // We will apply the height property of complete binary tree
        if(root==NULL){
            return 0;
        }
        
        int lh = 1+leftH(root->left);
        int rh = 1+rightH(root->right);
        
        if(lh==rh){
            // left shift of 1 yields 2powerh
            return (1<<lh) -1; 
        }
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};