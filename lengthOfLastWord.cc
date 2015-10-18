class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1, n = 0;
        while (i >= 0 && s[i] == ' ') --i; // remove the right whitespace
        while (i >= 0 && s[i] != ' ') {
            --i;
            ++n;
        }
        return n;
    }
};