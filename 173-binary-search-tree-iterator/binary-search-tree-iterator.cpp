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
class BSTIterator {
public:
    stack<TreeNode*> st;
    void helper(stack<TreeNode*>& st,TreeNode* root){
        TreeNode* temp=root;
        while(temp->left!=nullptr){
            st.push(temp);
            temp=temp->left;
        }
        st.push(temp);
    }
    BSTIterator(TreeNode* root) {
        helper(st,root);
    }
    
    int next() {
        TreeNode* node=st.top();
        st.pop();
        if(node->right!=nullptr){
            helper(st,node->right);
        }
        return node->val;
    }
    
    bool hasNext() {
        if(st.empty()){
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */