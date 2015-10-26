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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // add NULL to the end of queue
        // when iterate to NULL, level up, add another NULL to queue
        vector<vector<int>> result;
        queue<TreeNode*> q;
        int level = 0;
        if (root == NULL) return result;
        result.push_back(vector<int>());
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TreeNode * temp = q.front();
            q.pop();
            if (temp == NULL) {
                if (q.empty()) break; // need this line to determine the end, otherwise dead loop
                result.push_back(vector<int>());
                ++level;
                q.push(NULL);
                continue;
            }
            result[level].push_back(temp->val);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};