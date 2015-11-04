class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // ---two map 44ms
        // unordered_map<char, char> st, ts;
        // for (int i = 0; i < s.size(); ++i) {
        //     // check s -> t
        //     auto search = st.find(s[i]);
        //     if (search != st.end() && search->second != t[i])
        //         return false;
        //     // check s <- t
        //     auto check = ts.find(t[i]);
        //     if (check != ts.end() && check->second != s[i])
        //         return false;
        //     // add 
        //     st[s[i]] = t[i];
        //     ts[t[i]] = s[i];
        // }
        // return true;
        
        // --- ascII : 128 array 8ms
        int m1[128] = { 0 }, m2[128] = { 0 };
        for (int i = 0; i < s.size(); ++i) {
            if (m1[s[i]] != m2[t[i]])
                return false;
            m1[s[i]] = i + 1; // can not be 0, so plus one
            m2[t[i]] = i + 1;
        }
        return true;
    }
};