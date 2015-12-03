class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // --- 36 ms ---
        // double xor means nothing
        // to avoid overflow, do not add them up
        int n = nums.size(), sum = n;
        for (int i = 0; i < n; ++i) {
            sum ^= i;
            sum ^= nums[i];
        }
        return sum;
    }
};