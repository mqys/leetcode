class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, n = nums.size(), j = n - 1;
        while (1) {
            while (i < n && nums[i] != val) { // move left to nums[i] == val
                ++i;
            }
            while (j >= 0 && nums[j] == val) { // move right to nums[j] != val
                --j;
                --n;
            }
            if (i < j) {
              nums[i] = nums[j];
                --n;--j;  
            }
            else 
                break;
        }
        return n;
    }
};