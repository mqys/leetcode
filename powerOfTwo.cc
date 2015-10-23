class Solution {
public:
    bool isPowerOfTwo(int n) {
        // if (n <= 0) return false;
        // while (n > 1) {
        //     if (n & 1)
        //         return false;
        //     n = n >> 1;
        // }   
        // return true;
        
        // power fo 2 means: only 1 bit of num is 1
        return n > 0 && !(n & (n - 1));
    }
};