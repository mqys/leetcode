class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hm; // <num, index>
        for (int i = 0; i < nums.size(); ++i) {
            auto search = hm.find(nums[i]);
            if (search != hm.end() && search->second >= i - k)
                return true;
            hm[nums[i]] = i;
        }
        return false;
    }
};