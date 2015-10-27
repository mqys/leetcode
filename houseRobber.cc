class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> maxSum(nums.size(),0);
        // bool flag = false;
        
        if (nums.empty())    return 0;
        if (nums.size() < 2) return nums[0];
        
        // -- need a flag ???
        // maxSum[0] = nums[0];
        // if (nums[0] > nums[1]) {
        //     maxSum[1] = nums[0];
        //     flag = true;
        // }
        // else
        //     maxSum[1] = nums[1];
        // for (int i = 2; i < nums.size(); ++i) {
        //     if(flag) {
        //         maxSum[i] = maxSum[i-1] + nums[i];
        //         flag = false;
        //     }
        //     else {
        //         if (maxSum[i-1] > (maxSum[i-2] + nums[i])) {
        //             maxSum[i] = maxSum[i-1];
        //             flag = true;
        //         }
        //         else {
        //             maxSum[i] = maxSum[i-2] + nums[i];
        //         }
        //     }
        // }
        
        //-- accepted --->> no need to keep a record of flag
        maxSum[0] = nums[0];
        maxSum[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            maxSum[i] = max(maxSum[i-1],maxSum[i-2] + nums[i]);
        }
        return maxSum[nums.size() - 1];
    }
};