class Solution {
public:
    string convert(string s, int numRows) {
        if ( numRows == 1)
            return s;
        vector<string> l(numRows,"");
        string result = "";
        int dir = 1, row = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (row == numRows - 1) 
                dir = -1;
            if (row == 0)
                dir = 1;
            l[row].push_back(s[i]);
            row += dir;
        }
        for (string s : l)
            result += s;
        return result;
    }
};