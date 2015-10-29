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
    int minDepth(TreeNode* root) {
        // way 1
        // if (root == NULL) return 0;
        // if (root->left == NULL && root->right == NULL) return 1; // leaf
        // if (root->left == NULL || root->right == NULL) 
        //     return 1 + max(minDepth(root->left), minDepth(root->right)); // node with one child
        // return 1 + min(minDepth(root->left), minDepth(root->right));
        
        // way 2
        queue<TreeNode*> q;
        if (root == NULL) return 0;
        q.push(root);
        int depth = 1;
        while (!q.empty()) {
            int numInLevel = q.size();
            for (int i = 0; i < numInLevel; ++i) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left == NULL && temp->right == NULL)
                    return depth;
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            ++depth;
        }
    }
};