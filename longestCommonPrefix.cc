class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        bool flag = true;
        int i;
        for (i = 0; i < strs[0].size(); ++i) {
            char a = strs[0][i];
            for (string s : strs) {
                if (s.size() < i+1) {
                    flag = false;
                    break;
                }
                if (s[i] != a) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        int len =  flag?i+1:i;
        return strs[0].substr(0,len);
    }
};