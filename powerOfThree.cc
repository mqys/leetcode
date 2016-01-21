class Solution {
public:
    bool isPowerOfThree(int n) {
        // ---140 ms---
        int maxPowerOfThree = pow(3, (int)(log10(INT_MAX) / log10(3)));
        // cout << maxPowerOfThree;
        return n > 0 && maxPowerOfThree % n == 0;
    }
};