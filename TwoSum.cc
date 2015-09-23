class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        using vector find cost too much time to iterate
        while  using hash can directly get the target without checking one by one!!!
        cost space to save time
        */
        // OUT OF TIME!
        // auto e = nums.end();
        // vector<int> result;
        // int re = 0;
        // for(auto it = nums.begin(); it != e; ++it){
        //     re = target - *it;
        //     auto k = find(it+1,e,re);
        //     if(k!= e){
        //         result.push_back(it - nums.begin() + 1);
        //         result.push_back(k - nums.begin() + 1);
        //         return result;
        //     }
        // }
        unordered_map<int ,int> ht; //<num , index>
        vector<int> result;
        int rest;
        for(int i = 0; i<nums.size(); ++i)
        {
            rest = target - nums[i];
            auto f = ht.find(rest);
            if(f != ht.end())
            {
                //result.push_back(i + 1);
                result.push_back(ht[rest] + 1);
                result.push_back(i + 1);   // ht store the left nums while i on the right
                return result;
            }
            ht[nums[i]] = i;
        }
        
        
    }
};