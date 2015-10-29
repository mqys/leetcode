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
    bool hasPathSum(TreeNode* root, int sum) {
        // way 1
        // return hasSum(root, sum, 0);
         
        // way 2
        // reduce sum and recur
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum)
                return true;
            return false;
        }
        return hasPathSum(root->left, sum - root->val) 
                || hasPathSum(root->right, sum - root->val);
    }
    
    // helper of way 1
    bool hasSum(TreeNode* root, int sum, int curSum) {
        if (root == NULL)   return false;
        if (root->left == NULL && root->right == NULL) { // is leaf
            if (root->val + curSum == sum) return true;
            return false;
        }
        return hasSum(root->left, sum, curSum + root->val) 
                || hasSum(root->right, sum, curSum + root->val);
    }
};