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
    int rob(TreeNode* root) {
        
        // -- time limit --
        // return max(maxIncludeRoot(root), maxExcludeRoot(root));
        
        // just change the way of passing value!!!
        // -- 12ms --
        int in, out;
        maxRob(root, in, out);
        return max(in, out);
    }
    
    void maxRob(TreeNode *root, int& in, int& ex) {
        if (root == NULL) {
            in = 0;
            ex = 0;
            return;
        }
        
        int lin, lex;
        maxRob(root->left, lin, lex);
        int rin, rex;
        maxRob(root->right, rin, rex);
        
        in = root->val + lex + rex;
        ex = max(lin, lex) + max(rin, rex);
        
    }
    // int maxIncludeRoot(TreeNode* root) {
    //     if (root == NULL) 
    //         return 0;
    //     return  root->val + maxExcludeRoot(root->left) + maxExcludeRoot(root->right);
    // }
    // int maxExcludeRoot(TreeNode* root) {
    //     if (root == NULL)
    //         return 0;
    //     int maxLeft = max(maxIncludeRoot(root->left), maxExcludeRoot(root->left));
    //     int maxRight = max(maxIncludeRoot(root->right), maxExcludeRoot(root->right));
    //     return maxLeft + maxRight;
    // }
};