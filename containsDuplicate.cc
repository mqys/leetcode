class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numsSet;
        for (int i = 0; i < nums.size(); ++i) {
            if (numsSet.find(nums[i]) != numsSet.end())
                return true;
            numsSet.insert(nums[i]);
        }
        return false;
    }
};