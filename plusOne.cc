class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // vector store each digits of the number: 98 - [9,8]
        // cannot get the number out and add back -- cause overflow
        
        int i = digits.size() - 1;
        int carry = 1,tmp;
        while (i >= 0 && carry) {
            tmp = carry + digits[i];
            digits[i--] = tmp % 10 ; 
            carry = tmp / 10;
        }
        if (carry) 
            digits.insert(digits.begin(), carry);
        return digits;
        
    }
};