class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // pass 1: get the XOR of n1,n2
        // the XOR means: n1n2 differ in some bits
        // choose one bit to distinguish n1n2
        // pass 2: according to diff bit: divide the nums into two groups
        // get n1, n2
        
        // a easy way to get XOR of nums
        // int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        int diff = 0;
        for (int n : nums)
            diff ^= n;
        // choose one bit to differ
        // -x: ~x + 1 (补码)
        diff &= -diff;
        
        vector<int> re = {0,0};
        for (int n : nums) {
            if (diff & n)
                re[0] ^= n;
            else 
                re[1] ^= n;
        }
        return re;
    }
};