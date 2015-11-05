class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // --- reverse O(1) space -- 24ms
        // int size = nums.size();
        // int m = size - k % size; // calcu the num 
        // if (m == 0 || m == size) return;
        // reverse(nums, 0, m - 1);
        // reverse(nums, m, size - 1);
        // reverse(nums, 0, size - 1);
        
        // --- copy and rotate -- 24ms
        vector<int> tmp;
        int size = nums.size();
        for (int i: nums)
            tmp.push_back(i);
        for (int i = 0; i < size; ++i) 
            nums[(i+k) % size] = tmp[i];
        
        
        
    }
    void reverse(vector<int>& nums, int start, int end) {
        int temp;
        while (start < end) {
            temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }
};