class Solution {
public:
    string reverseVowels(string s) {
        if (s.size() < 2)
            return s;
        int l = 0;
        int r = s.size() - 1;
        const string vowels("aeiouAEIOU");
        
        while (l < r) {
            while (l < r && vowels.find(s[l]) == string::npos)
                ++l;
            while (r > l && vowels.find(s[r]) == string::npos)
                --r;
            swap(s[l++], s[r--]);                
        }
        return s;
    }
};