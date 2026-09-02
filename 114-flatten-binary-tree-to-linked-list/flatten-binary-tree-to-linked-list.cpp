/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> preorder(TreeNode* root){
        vector<TreeNode*> ans;
        if(root==nullptr){
            return ans;
        }
        ans.push_back(root);
        vector<TreeNode*> left=preorder(root->left);
        ans.insert(ans.end(),left.begin(),left.end());
        vector<TreeNode*> right=preorder(root->right);
        ans.insert(ans.end(),right.begin(),right.end());
        return ans;
    }
    void flatten(TreeNode* root) {
        if(root==nullptr){
            return;
        }
        vector<TreeNode*> curr=preorder(root);
        for(int i=0;i<curr.size()-1;i++){
            curr[i]->left=nullptr;
            curr[i]->right=curr[i+1];
        }
        curr[curr.size()-1]->left=nullptr;
        curr[curr.size()-1]->right=nullptr;
    }
};