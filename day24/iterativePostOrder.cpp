#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;  
    }
};


// Here the second stack doesn't make any difference
// if you can use vector reverse function to reverse 
// the vector, you can directly do with single stack
vector<int> twoStacks(TreeNode* root){
    vector<int> ans;
    if(root==NULL)return ans;
    stack<TreeNode*> stk1, stk2;
    while(!stk1.empty()){
        root = stk1.top();
        stk1.pop();
        stk2.push(root);
        if(root->left!=NULL){
            stk1.push(root->left);
        }
        if(root->right!=NULL){
            stk1.push(root->right);
        }
    }

    if(!stk2.empty()){
        ans.push_back(stk2.top());
        stk2.pop();
    }
return ans;
}

// Here the second stack doesn't make any difference
// if you can use vector reverse function to reverse 
// the vector, you can directly do with single stack
vector<int> twoStacks(TreeNode* root){
    vector<int> ans;
    if(root==NULL)return ans;
    stack<TreeNode*> stk1, stk2;
    while(!stk1.empty()){
        root = stk1.top();
        stk1.pop();
        // stk2.push(root);
        ans.push_back(root->val);
        if(root->left!=NULL){
            stk1.push(root->left);
        }
        if(root->right!=NULL){
            stk1.push(root->right);
        }
    }

    // if(!stk2.empty()){
    //     ans.push_back(stk2.top());
    //     stk2.pop();
    // }
    reverse(ans.begin(), ans.end());
return ans;
}


vector<int> singleStack(TreeNode* root){
    vector<int> ans;
    if(root == NULL)return ans;
    stack<TreeNode*> stk;
    TreeNode* curr = root;
    stk.push(curr);
    while(curr!=NULL || stk.empty()!=true){
        if(curr != NULL){
            stk.push(curr);
            curr = curr->left;
        }else{
            TreeNode* temp = stk.top()->right;
            if(temp == NULL){
                temp = stk.top();
                stk.pop();
                ans.push_back(temp->val);
                while(stk.empty()!=true && temp==stk.top()->right){
                    temp = stk.top();
                    stk.pop();
                    ans.push_back(temp->val);
                }
            }else{
                curr = temp;
            }
        }
    }
return ans;
}




// The code is resulting in duplicate of 
// each element in the resulting 
// postorder vector
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL)return ans;
    stack<TreeNode*> stk;
    TreeNode* curr = root;
    stk.push(curr);
    while(curr!=NULL || stk.empty()!=true){
        if(curr != NULL){
            stk.push(curr);
            curr = curr->left;
        }else{
            TreeNode* temp = stk.top()->right;
            if(temp == NULL){
                temp = stk.top();
                stk.pop();
                ans.push_back(temp->val);
                while(stk.empty()!=true && temp==stk.top()->right){
                    temp = stk.top();
                    stk.pop();
                    ans.push_back(temp->val);
                }
            }else{
                curr = temp;
            }
        }
    }
return ans;
}
