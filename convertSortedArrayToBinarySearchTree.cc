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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // --- 20 ms ---
        TreeNode* root = constructBST(nums, 0, nums.size()-1);
        return root;
    }
    // recursive function
    TreeNode* constructBST(vector<int>& nums, int start, int end) {
        if (start > end)
            return nullptr;
        // if (start == end)
        //     return new TreeNode(nums[start]);
            
        // int mid = start + (end - start) / 2;
        int mid = (end + start) / 2;
        TreeNode * temp = new TreeNode(nums[mid]);
        temp->left = constructBST(nums, start, mid-1);
        temp->right = constructBST(nums, mid+1, end);
        return temp;
    }
};