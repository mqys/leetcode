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
    bool isSymmetric(TreeNode* root) {
        // 4ms 4ms 8ms
        
        // --recursive way 1
        // use stacks to store the val then compare
        // if (root == NULL) return true;
        // // dfs
        // leftFirst(root->left);
        // rightFirst(root->right);
        // // compare
        // int l, r;
        // while (!left.empty() && !right.empty()) {
        //     l = left.top();left.pop();
        //     r = right.top();right.pop();
        //     if (l == r) 
        //         continue;
        //     return false;
        // }
        // if (!left.empty() || !right.empty())
        //     return false;
        // return true;
        
        // --recursive way 2
        // without store the val
        // if (root == NULL) return true;
        // return isSym(root->left, root->right);
        
        // --iterative way (use queue)
        if (root == NULL) return true;
        queue<TreeNode*> left;
        queue<TreeNode*> right;
        left.push(root->left);
        right.push(root->right);
        TreeNode *tl, *tr;
        while (!left.empty() && !right.empty()) {
            tl = left.front();
            left.pop();
            tr = right.front();
            right.pop();
            
            if (tl == NULL && tr == NULL) //return true;
                continue;
            if (tl == NULL || tr == NULL) return false;
            if (tl->val != tr->val) return false;
            
            left.push(tl->left);
            left.push(tl->right);
            right.push(tr->right);
            right.push(tr->left);
        }
        return true;        
        
        
    }
    
    bool isSym(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL) return true;
        if (left == NULL || right == NULL) return false;
        if (left->val == right->val) {
            return isSym(left->left, right->right) 
                    && isSym(left->right, right->left);
        }
        return false;
    }
    
    // func for store val way
    void leftFirst(TreeNode* root) {
        // if (root == NULL) return;
        if (root == NULL) {
            left.push(0);
            return;
        }
        leftFirst(root->left);
        leftFirst(root->right);
        left.push(root->val);
    }
    void rightFirst(TreeNode* root) {
        // if (root == NULL) return;
        if (root == NULL) {
            right.push(0);
            return;
        }
        rightFirst(root->right);
        rightFirst(root->left);
        right.push(root->val);
    }
private:
    stack<int> left;
    stack<int> right;
 };