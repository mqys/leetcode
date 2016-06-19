class Solution {
public:
    bool canJump(vector<int>& nums) {
        // TLE -- backtrack
        // int last = nums.size() - 1;
        // return jump(nums, 0);
        
        // detect the reachable range
        int reach = 0, i = 0;
        for (; i < nums.size() && i <= reach; ++i) {
            reach = max(i+nums[i], reach);
        }
        return i == nums.size();
    }
    

    // bool jump(vector<int>& nums, int index) {
    //     if (index == nums.size() - 1) {
    //         return true;
    //     }
    //     if (index > nums.size() - 1) {
    //         return false;
    //     }
    //     int max = nums[index];
    //     for (int i = 1; i <= max; ++i) {
    //         if (jump(nums, index+i))
    //             return true;
    //     }
    //     return false;
    // }
};