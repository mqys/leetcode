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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        // ---from bottom to top 
        // if (!isBalanced(root->left) || !isBalanced(root->right)) return false;
        // int ld = getDepth(root->left), rd = getDepth(root->right);
        // if (abs(ld - rd) > 1)
        //     return false;
        // return true;
        
        // ---from top to bottom (diff in calling getDepth)
        int ld = getDepth(root->left), rd = getDepth(root->right);
        if (abs(ld - rd) > 1) 
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
    int getDepth(TreeNode* node) {
        if (node == NULL) return 0;
        else return 1 + max(getDepth(node->left),getDepth(node->right));
    }
};