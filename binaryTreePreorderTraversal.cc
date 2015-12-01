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
    vector<int> preorderTraversal(TreeNode* root) {

        // ----- O(n) space, use stack-----     
        // vector<int> re;
        // stack<TreeNode*> s;
        // TreeNode* temp;
        
        // if (root == NULL)
        //     return re;
        // s.push(root);
        
        // avoid pushing NULL into stack --- 4 ms ---
        // while (!s.empty()) {
        //     temp = s.top();
        //     s.pop();
        //     re.push_back(temp->val);
        //     if (temp->right)
        //         s.push(temp->right);
        //     if (temp->left)
        //         s.push(temp->left);
        // }
        
        // include NULL into stack --- 0 ms --- 
        // while (!s.empty()) {
        //     temp = s.top();
        //     s.pop();
        //     if (temp == NULL)
        //         continue;
        //     re.push_back(temp->val);
        //     s.push(temp->right);
        //     s.push(temp->left);
        // }
        
        // ----- no stack -----
        // morris travrsal, O(1) space --- 0 ms ---
        // change the right child of predecessor to cur and change it back when get to it second time
        // rules:
        //      1. if the cur->left is NULL, cur = cur->right;
        //      2. if cur->left != NULL, find the predecessor(rightest of left subtree) 
        //          1) if predecessor->right == NULL, pre->right = cur, cur = cur->left
        //          2) if pre->right == cur, pre->right = NULL, cur = cur->right
        //      3. goto 1.
        vector<int> re;
        TreeNode *cur = root, *pre = NULL;
        while (cur) {
            if (cur->left) {
                pre = cur->left;
                while (pre->right != NULL && pre->right != cur) 
                    pre = pre->right;
                
                if (pre->right == NULL) {
                    pre->right = cur;
                    re.push_back(cur->val);
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    cur = cur->right;
                }
            } else {
                re.push_back(cur->val);
                cur = cur->right;
            }
        }
        return re;
    }
};