class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // --- 12 ms ---
        vector<vector<int>> res;
        permute(nums, 0, res);
        return res;
    }
    
    void permute(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == (nums.size() - 1)) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);
            permute(nums, start + 1, res);
            swap(nums[start], nums[i]);
        }
    }
};