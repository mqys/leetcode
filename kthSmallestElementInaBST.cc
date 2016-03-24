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
    int kthSmallest(TreeNode* root, int k) {
        
        // -- 20 ms --
        int *array = new int[k];
        int res = findKth(root, k, array);
        delete[] array;
        return res;
    }
    // return kth number
    int findKth(TreeNode* root, int k, int* arr) {
        int num = dfs(root, k, arr);
        if (num == k) 
            return num;
        else if (num > k)            
            return arr[k-1];
        return findKth(root->right, k - num, arr + num);    
    }
    // return node count of subtree
    int dfs(TreeNode* root, int k, int* arr) {
        if (root == NULL)
            return 0;
        int count = dfs(root->left, k, arr);
        if (count < k)
            arr[count] = root->val;
        return count + 1 + dfs(root->right, k - count - 1, arr + count + 1);
    }
    
    
};