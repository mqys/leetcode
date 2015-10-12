class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int sign = 1;
        //ignore whitespace
        for (; i < str.size() && str[i] == ' '; ++i);
        if (i == str.size()) return 0; // all whitespace
        //judge sign
        if (str[i] == '+') {
            ++i;
        }
        else if (str[i] == '-') {
            sign  = -1;
            ++i;
        }
        //interpret
        int sum = 0, currentnum = 0;
        for (; str[i] >= '0' && str[i] <= '9' && i < str.size(); ++i) {
            currentnum = str[i] - '0';
            if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && currentnum > 7)) return INT_MAX;
            if (sum < INT_MIN / 10 || (sum == INT_MIN / 10 && currentnum > 8)) return INT_MIN;
            sum = sum * 10 + sign * currentnum;
        }
        return sum;
    }
};