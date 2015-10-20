class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0, temp;
        for (char c : s) {
            temp = c - 'A' + 1;
            sum = sum * 26 + temp;
        }
        return sum;
    }
};