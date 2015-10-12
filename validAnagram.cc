class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> words;
        for (char c : s) {
            ++words[c];
        }
        for (char c : t) {
            --words[c];
        }
        for (auto a = words.begin(); a != words.end(); ++a) {
            if (a->second != 0)
                return false;
        }
        return true;
    }
};