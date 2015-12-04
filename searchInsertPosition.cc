class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // --- 8 ms ---
        //  O(n) calcu lowerbound
        // int i;
        // for (i = 0; i < nums.size(); ++i) {
        //     if (nums[i] >= target)
        //         return i;
        // }
        // return i;   
        
        // --- 8 ms ---
        // O(log n) binary search
        int low  = 0, high = nums.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};