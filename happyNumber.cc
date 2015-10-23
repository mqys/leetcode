class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> numSet;
        int sum = 0, digit;
        while (n != 1) {
            while (n != 0) {
                digit = n % 10;
                sum += (digit * digit);
                n = n / 10;
            }
            n = sum;
            sum = 0;
            if (numSet.find(n) != numSet.end()) // find cycle
                return false;
            numSet.insert(n); 
        }
        return true;
    }
};