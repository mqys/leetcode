class NumArray {
public:
    NumArray(vector<int> &nums) {
        //  sums = vector<int>(nums.size(), 0);
         numbers = &nums;
         int sum = 0;
         for (int i = 0; i < nums.size(); ++i) {
             sum += nums[i];
            //  sums[i] = sum;
            sums.push_back(sum);
         }
    }

    int sumRange(int i, int j) {
        return sums[j] - sums[i] + (*numbers)[i];
    }
private:
    vector<int> * numbers;
    vector<int> sums;
    // int sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);