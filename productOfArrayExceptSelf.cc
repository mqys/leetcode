class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // the result of nums[i] consists of two parts
        // the product of before and the product of after nums
        // use one variable can calculate the product of one direction in one pass
        
        int n = nums.size();
        vector<int> re(n, 1);
        int bep = 1, afp = 1;
        for (int i = 0; i < n; ++i) {
            re[i] *= bep;
            bep *= nums[i];
            re[n-1-i] *= afp;
            afp *= nums[n-1-i];
        }
        
        return re;
    }
};