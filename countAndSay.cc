class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) { // control the Nth
            string temp;
            for (int j = 0, len = 0; j < s.size() - len;) { // read the char
                while (s[j] == s[j+len]) {
                    ++len;
                }
                temp.push_back('0'+len);
                temp.push_back(s[j]);
                j += len;
                len = 0;
            }
            s = temp;
        }
        return s;
    }
};