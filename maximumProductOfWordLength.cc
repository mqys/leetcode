class Solution {
public:
    int maxProduct(vector<string>& words) {
        // --- 148 ms---
        // use bit AND to check whether same char
        int maxNum = 0;
        // <pattern, lenght>
        unordered_map<int, int> m;
      
        for (string s: words) {
            int pattern = 0;
            for (char c: s) {
                pattern |= 1 << c - 'a';
            }
            // in case of same char context
            m[pattern] = max(m[pattern], (int)s.size());
            
            for (auto p: m) {
                if (p.first & pattern) {
                    continue;
                }
                maxNum = max(maxNum, p.second * m[pattern]);
            }
        }
        return maxNum;
    }
};