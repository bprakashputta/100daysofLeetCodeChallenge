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
    int Height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        int leftH = 1+Height(root->left);
        int rightH = 1+Height(root->right);
        return max(leftH, rightH);
    }
    
    // This takes O(n2) Time complexity 
    // int diameter(TreeNode* root,int maxi){
    //     if(root==NULL){
    //         return 0;
    //     }
        
    //     int lh = Height(root->left);
    //     int rh = Height(root->right);
        
    //     maxi = max(maxi, lh+rh);
    //     maxi = max(maxi,diameter(root->left, maxi));
    //     maxi = max(maxi,diameter(root->right, maxi));
    // return maxi;
    // }
    
    int diameter(TreeNode* root,int maxi){
        if(root==NULL){
            return 0;
        }
        
        // int lh = Height(root->left);
        // int rh = Height(root->right);
        int lh = diameter(root->left, maxi);
        int rh = diameter(root->right, maxi);   
        maxi = max(maxi, lh+rh);
        // maxi = max(maxi,diameter(root->left, maxi));
        // maxi = max(maxi,diameter(root->right, maxi));
    return 1+ max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        return diameter(root,0);
    }
};