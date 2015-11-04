class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        // --- dirty code 
        // vector<string> result;
        // string range;
        // int i = 1;
        // if (nums.empty())
        //     return result;
        // range += getString(nums[0]);        
        // for (; i < nums.size(); ++i) {
        //     if (i > 0 && nums[i] == nums[i-1] + 1) 
        //         continue;
        //     if (nums[i-1] == stoi(range)) { // only one
        //         result.push_back(range);
        //         range.clear();
        //         range += getString(nums[i]);        
        //         continue;
        //     } 
        //     range += "->" + getString(nums[i-1]);        
        //     result.push_back(range);
        //     range.clear();
        //     range += getString(nums[i]);        
        // }
        // // deal with last one
        // if (nums[i-1] == stoi(range)) {
        //     result.push_back(range);
        //     return result;
        // }
        // range += "->" + getString(nums[i-1]);        
        // result.push_back(range);
        // return result;
        
        //
        vector<string> re;
        for (int i = 0; i < nums.size();) {
            int end = i;
            while (end < nums.size() - 1 && nums[end] == nums[end+1] - 1)   ++end;
            if (end > i)
                re.push_back(to_string(nums[i]) + "->" + to_string(nums[end]));
            else
                re.push_back(to_string(nums[i]));
            i = end + 1;
        }
        return re;
    }
    
    // no need this func, use to_string() can do;
    // string getString(int i) {
    //     stringstream ss;
    //     ss << i;
    //     string s = ss.str();
    //     return s;
    // }
};