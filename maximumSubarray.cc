class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // --- 8 ms / 12 ms(change order and del one judgement) ---
        // if one contiguous subsequence is positive, then this part need to be add
        // attention to all negative situation
        // int temp = 0, max = INT_MIN; // use INT_MIN here, not 0
        // for (int i : nums) {
        //     temp += i;
        //     // attention to the order of the following judgement
        //     // if (i > max)
        //     //     max = i;
        //     // if (temp < 0) {
        //     //     temp = 0;
        //     //     continue;
        //     // }    
        //     // if (temp > max)
        //     //     max = temp;
            
        //     if (temp > max)
        //         max = temp;
        //     if (temp < 0) 
        //         temp = 0;
          
        // }
        // return max;
        
        // --- 16 ms ---
        // try divide and conquer
        // get the mid, then come two cases: 1. the res contain the mid 2. the res in the left or right
        // recursive do the function
        return maxSubArray(nums, 0, nums.size()-1);
        
        
    }
    int maxSubArray(vector<int> &nums, int start, int end) {
        if (start == end)
            return nums[start];
        int mid = (start + end) / 2;
        int leftmax = maxSubArray(nums, start, mid);
        int rightmax = maxSubArray(nums, mid+1, end);
        // calcu the max contain  the mid
        int maxLeft = INT_MIN, temp = 0;
        for (int i = mid; i >= start; --i) {
            temp += nums[i];
            maxLeft = max(maxLeft, temp);
        }
        int maxRight = INT_MIN;
        temp = 0;
        for (int i = mid+1; i <= end; ++i) {
            temp += nums[i];
            maxRight = max(maxRight, temp);
        }
        return max(maxLeft+maxRight, max(leftmax, rightmax));
    }
};