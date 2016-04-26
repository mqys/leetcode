class Solution {
public:
    string reverseString(string s) {
        if (s.size() < 2)
            return s;
        int r = s.size() - 1;
        int l = 0;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
        return s;
    }
};