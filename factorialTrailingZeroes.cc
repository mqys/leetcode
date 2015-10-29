class Solution {
public:
    int trailingZeroes(int n) {
        // 后缀0的个数
        // 5X 25X 125X ...
        // int sum = 0;
        // for (int i = 1; n >= pow(5,i); ++i) {
        //     sum += n / pow(5,i);
        // }   
        // return sum;
        
        int sum = 0;
        while (n) {
            sum += n / 5;
            n = n / 5;
        }
        return sum;
    }
};