class Solution {
public:
    bool isPowerOfFour(int num) {
        int mark = 0x55555555;
        if (num < 1)
            return false;
        if (num & (num - 1))
            return false;
        if (num & ~mark)
            return false;
        return true;
    }
};