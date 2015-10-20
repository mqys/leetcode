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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 如果节点都在根的一侧，说明还没有到达最低，在两侧或是相等的时候到达
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};