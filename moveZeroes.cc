class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 1, temp;
        while (j < nums.size()) {
            if (nums[i]) {
                ++i;
                ++j;
            }
            else {
                if (nums[j]) {
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    ++i;++j;
                }
                else {
                    ++j;
                }
            }
        }
    }
};