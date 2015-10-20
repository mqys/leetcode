class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
            use hash map
        */
/*        int n = nums.size() / 2;
        unordered_map<int, int> numMap;
        //faster then the interation below
        for (int i : nums) {
            ++numMap[i];
        }
        for (auto j = numMap.begin(); j != numMap.end(); ++j) {
            if (j->second > n)
                return j->first;
        }*/
        // for (int i : nums) {
        //     ++numMap[i];
        //     if (numMap[i] > n) return i;
        // }
        
        /*
            Moore voting algorithm
        */
        int count = 1, current = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == current) ++count;
            else {
                --count;
                if (count < 1) {
                    current = nums[i];
                    count = 1;
                }    
            }
        }
        return current;
    }
};