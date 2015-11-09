class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // --- bit manipulation 20 ms ---
        int n = 0;
        for (int i : nums) 
            n ^= i;
        return n;
    }
};