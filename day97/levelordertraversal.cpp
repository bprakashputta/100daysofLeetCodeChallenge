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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> result;
        queue<pair<TreeNode*,int>>nodes;
        nodes.push({root, 0});
        while(!nodes.empty()){
            int size = nodes.size();
            vector<int> currLevel;
            for(int i=0; i<size; i++){
                auto it = nodes.front();
                nodes.pop();
                TreeNode* node = it.first;
                int level = it.second;
                currLevel.push_back(node->val);
                if(node->left!=NULL){
                    nodes.push({node->left, level+1});
                }
                if(node->right!=NULL){
                    nodes.push({node->right, level+1});
                }
            }
            result.push_back(currLevel);
        }
    return result;
    }
};