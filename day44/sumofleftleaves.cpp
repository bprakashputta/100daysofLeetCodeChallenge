#include<iostream>
#include<queue>
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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});
        while(q.size()){
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            bool turn = it.second;
            if(!node->left && !node->right && turn == true){
                sum += node->val;
            }
            if(node->right!=NULL){
                q.push({node->right, false});
            }
            if(node->left!=NULL){
                q.push({node->left, true});
            }
        }
        return sum;
    }
};