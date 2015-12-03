/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // --- 28 ms --- recurisive way
        // connect root->left to root->right 
        // then next level root->left->right to root->right->left
        // then next level ...
        // if (root == NULL) return;
        // TreeLinkNode* left = root->left;
        // TreeLinkNode* right = root->right;
        // while (left) {
        //     left->next = right;
        //     left = left->right;
        //     if (right->left) right = right->left;
        // }
        // connect(root->left);
        // connect(root->right);
        // return;
        
        // --- 24 ms ---
        // tree level traversal
        queue<TreeLinkNode*> q;
        if (root == NULL) return;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            if (temp == NULL) { // this level fin
                if (q.empty()) return; // end case
                q.push(NULL);
                continue;
            }
            // not fin
            temp->next = q.front();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        return;
    }
};