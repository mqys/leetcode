class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        sorted words to be the key
        */
        unordered_map<string, multiset<string>> wordsMap;
        for (string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            wordsMap[tmp].insert(s);
        }
        //form the result
        vector<vector<string>> result;
        for (auto p = wordsMap.begin(); p != wordsMap.end(); ++p) {
            multiset<string> wordset = p->second;
            vector<string> temp;
            for (auto s = wordset.begin(); s != wordset.end(); ++s) 
                temp.push_back(*s);
            result.push_back(temp);
        }
        return result;
    }
};