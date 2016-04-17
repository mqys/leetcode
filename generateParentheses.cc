class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // --- 4 ms ---
        // from left to right, every time has two options, but with constrains
        vector<string> res;
        add(res, "", n, 0);
        return res;
    }
    // l -> '(' left,  r -> ')' need to add
    void add(vector<string>& vs, string s, int l, int r) {
        if (l == 0 && r == 0) {
            vs.push_back(s);
            return;
        }
        
        if (r > 0)
            add(vs, s+")", l, r - 1);
        if (l > 0)
            add(vs, s+"(", l - 1, r + 1);
        
    }
};