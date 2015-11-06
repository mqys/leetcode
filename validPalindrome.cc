class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        int start = 0, end = size - 1;
        while (start < end) {
            while (start < size - 1 && !isValid(s[start])) ++start;
            while (end >= 0 && !isValid(s[end])) --end;
            if (s[start] == s[end] || abs(s[start] - s[end]) == 'a' - 'A') {
                ++start; --end;
                continue;
            }
            if (start == size || end == -1)
                break;
            return false;
        }
        return true;
    }
    // could use std::isalnum to determine whether is alphanumeric char
    bool isValid(char c) {
        if (c >= '0' && c <= '9')
            return true;
        if (c >= 'A' && c <= 'Z')
            return true;
        if (c >= 'a' && c <= 'z')
            return true;
        return false;
    }
};