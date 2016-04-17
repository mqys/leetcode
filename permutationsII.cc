class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // --- 36 ms ---
        vector<vector<int>> res;
        permuteUnique(nums, 0, res);    
        return res;
    }
    void permuteUnique(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == (nums.size() - 1)) {
            res.push_back(nums);
            return;
        }
        
        // unordered_set<int> s;
        unordered_map<int, int> s;
        for (int i = start; i < nums.size(); ++i) {
            if (s.find(nums[i]) != s.end())
                continue;
            swap(nums[start], nums[i]);
            permuteUnique(nums, start + 1, res);
            swap(nums[start], nums[i]);
            // s.insert(nums[i]);
            s[nums[i]] = 1;
        }
    }
};