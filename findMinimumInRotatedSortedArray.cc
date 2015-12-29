class Solution {
public:
    int findMin(vector<int>& nums) {
        // --- 4 ms ---
        int left = 0, right = nums.size()-1;
        while (nums[left] > nums[right]) {
            int mid = (left + right) / 2;
            if (nums[left] <= nums[mid])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};