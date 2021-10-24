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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }else if((p==NULL && q!=NULL)||(p!=NULL && q==NULL)){
            return false;
        }else if(p!=NULL && q!=NULL && p->val != q->val){
            return false;
        }
            
        bool left = isSameTree(p->left, q->left);
        if(left==false){
            return false;
        }
        bool right = isSameTree(p->right, q->right);    
        
        if(left==false || right == false){
            return false;
        }
    return true;
    }
};