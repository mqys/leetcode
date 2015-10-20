class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        // while (n) {
        //     if (n&1) ++count;
        //     n = n >> 1;  // attention need = operation to change the value of n !
        // }

        while (n) {
            n &= n - 1;
            ++count;
        }
        
        return count;
    }
};