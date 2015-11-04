class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n) {
            // result.insert(result.begin(), (n - 1) % 26 + 'A');
            // n = n % 26 == 0 ? n / 26 - 1: n /26;
            --n;
            result.insert(result.begin(), n % 26 + 'A');
            n /= 26;
        }
        return result;
    }
};