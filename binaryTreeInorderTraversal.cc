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
    vector<int> inorderTraversal(TreeNode* root) {
        
        // use stack, O(n) space with help func pushAllLeft() --- 0 ms ---
        // stack<TreeNode*> s;
        // vector<int> re;
        // if (root == NULL)
        //     return re;
        // pushAllLeft(root, s);    
        // TreeNode* temp;
        // while (!s.empty()) {
        //     temp = s.top();
        //     s.pop();
        //     re.push_back(temp->val);
        //     if (temp->right)
        //         pushAllLeft(temp->right,s);
        // }
        // return re;
        
        // no stack, O(1) morris traversal --- 0 ms ---
        // rules turn to "Tree Preorder Traversal.cc"
        TreeNode *cur = root, *pre = NULL;
        vector<int> re;
        while (cur) {
            if (cur->left) {
                // find repdecessor
                pre = cur->left;
                while (pre->right && pre->right!=cur)
                    pre = pre->right;
                
                // judge the first time or second
                if (pre->right) { //second time
                    re.push_back(cur->val);
                    cur = cur->right;
                    pre->right = NULL;
                } else { // first time
                    pre->right = cur;
                    cur = cur->left;
                }
            } else {
                re.push_back(cur->val);
                cur = cur->right;                
            }
        }
        return re;
    }
    
    void pushAllLeft(TreeNode* root, stack<TreeNode*> &s) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
};