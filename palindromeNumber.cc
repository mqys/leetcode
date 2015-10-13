class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        //left and right
        int len = 1;
        for ( ; x/len >= 10; len *= 10);
        while (x != 0) {
            int left = x / len;
            int right = x % 10; 
            if (left != right) return false;
            x = (x - left * len) / 10;
            len /= 100; 
        }
        return true;
        
/*        //reverse half to avoid overflow (slower than the upper way)
        if (x < 0) return false;
        if (x >= 10 && x % 10 == 0) return false; // attention to cases end with 0!
        int sum = 0;
        while (x > sum) {
            sum = sum * 10 + x % 10;
            x = x / 10;
        }
        return x ==sum || x == sum / 10 ? true : false;*/
    }
};