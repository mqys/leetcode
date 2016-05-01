class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> once(k);
        helper(once, 0, 1, n, res);
        return res;
    }
    
    void helper(vector<int> &once, int index, int start, int left, vector<vector<int>> &res) {
        // last one
        if (index == once.size() - 1 && left < 10 && left >= start) {
            once[index] = left;
            res.push_back(once);
            return;
        }
        // if (index == once.size() - 1)
        //     return;
        
        // 0 - (n - 2)           
        for (int i = start; i < 10 && i < left; ++i) {
            if ((once.size() - index) * 9 < left)
                continue;
            once[index] = i;
            helper(once, index + 1, i + 1, left - i, res);
        }
    }

};