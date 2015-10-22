class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) return false;
        if (num < 7) return true;
        if (num % 2 == 0) return isUgly(num / 2); // if no recursive, then num /= n;
        if (num % 3 == 0) return isUgly(num / 3);
        if (num % 5 == 0) return isUgly(num / 5);
        return false;
    }
};