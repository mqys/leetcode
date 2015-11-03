class Solution {
public:
    bool wordPattern(string pattern, string str) {
        // 双向映射！abbc -> dog cat cat haha 在右向映射可以通过
        unordered_map<char, string> hm;
        unordered_map<string, char> rf;
        int pos = -1;
        int i = 0;
        string temp;
        for (; i < pattern.size(); ++i) {
            // split str into words (could use istringstream to split words)
            for (temp = "", ++pos; pos < str.size() && str[pos] != ' '; ++pos)
                temp.push_back(str[pos]);
            
            // check left --> right    
            auto search = hm.find(pattern[i]);
            if (search != hm.end() && search->second != temp)
                    return false;
            hm[pattern[i]] = temp;
            
            // check right --> left
            auto check = rf.find(temp);
            if (check != rf.end() && check->second != pattern[i])
                return false;
            rf[temp] = pattern[i];    
        }
        // nums not match
        if (i != pattern.size() || pos != str.size())
            return false;
        return true;
    }
};