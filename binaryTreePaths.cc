/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        // if (root == NULL)
        //     return r;
        // if (root->left == NULL && root->right == NULL) {
        //     r.push_back(to_string(root->val));
        //     return r;
        // }
        // if (root->left) helper(to_string(root->val), root->left);
        // if (root->right) helper(to_string(root->val), root->right);
        // return r;
        
        // add the child val before into the child
        vector<string> v;
        if (root == NULL)
            return v;
        dfs(v, to_string(root->val), root);
        return v;
    }
    void dfs(vector<string> &v, string s, TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            v.push_back(s);
            return;
        }
        if (root->left)
            dfs(v, s + "->" + to_string(root->left->val), root->left);
        if (root->right)
            dfs(v, s + "->" + to_string(root->right->val), root->right);
        return;
    }
    // void helper(string s, TreeNode* root) {
    //     if (root->left == NULL && root->right == NULL) {
    //         r.push_back(s + "->" + to_string(root->val));
    //         return;            
    //     }
    //     if (root->left) helper(s + "->" + to_string(root->val), root->left);
    //     if (root->right) helper(s + "->" + to_string(root->val), root->right);
    //     return;
    // }
private:
    // vector<string> r;
};