class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // attention: sorted array
        int n = nums.size();
        int i = 0, j = i + 1;
        for (; i < n - 1;) {
            if (nums[i] == nums[j]) {
                nums.erase(nums.begin() + j);
                --n;
                // ++j; //the num of vector has been cut and j move to the next element already, no need to ++
            }
            else {
                ++i;
                ++j;
            }
        }
        return n;
    }
};