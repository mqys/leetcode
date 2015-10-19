class Solution {
public:
    int addDigits(int num) {
        // 9*X
        if (num && num % 9 == 0) return 9;
        else return num % 9;
    }
};