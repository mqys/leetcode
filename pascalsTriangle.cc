class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> cur;
        if (numRows < 1) return result;
        result.push_back(vector<int>(1,1));
        for (int i = 1; i < numRows; ++i) {
            auto pre = result.back();
            for (int j = 0; j < pre.size(); ++j) {
                if (j == 0) 
                    cur.push_back(1);
                else
                    cur.push_back(pre[j]+pre[j-1]);
            }
            cur.push_back(1);
            result.push_back(cur);
            cur.resize(0);
        }
        return result;
    }
};