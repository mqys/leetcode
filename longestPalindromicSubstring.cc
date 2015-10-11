class Solution {
public:
    string longestPalindrome(string s) {
/*        //dp[i][j]表示i-j范围的字串是否是回文串
        //init dp
        //vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),0)); //--memory limit-- 
        bool dp[s.size()][s.size()]; //only in this can be accepted
        int maxlen = 1, startpos = 0;
        for (int i = 0; i < s.size(); ++i) { //处理中间为单或双，初始状态
            dp[i][i] = 1;
            if (i && s[i-1] == s[i]) {
                dp[i-1][i] = 1;
                maxlen = 2;
                startpos = i - 1;
            }
            else if (i && s[i-1] != s[i])
                dp[i-1][i] = 0;
        }
        //注意迭代计算方式，由于状态方程使用缩减两端后的状态，故迭代从短串开始
        for (int len = 3; len <= s.size(); ++len) {
            for (int i = 0; i + len - 1 < s.size(); ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i+1][j-1] == 1) {
                    if (len > maxlen) {
                        maxlen = len;
                        startpos = i;
                    }
                    dp[i][j] = 1;
                }
                else
                    dp[i][j] = 0;
            }
        }
        return s.substr(startpos, maxlen);*/
        
        //manacher way
        /*
        len[i]-1 : the length of result
        */
        string tmp = "$";
        int len[s.size() * 2 + 3];
        //form the str $#1#2#@  , str start from index 1
        for (int i = 0; i < s.size(); ++i) {
            tmp.push_back('#');
            tmp.push_back(s[i]);
        }
        tmp.push_back('#');
        tmp.push_back('@');
        //cal len
        int maxcenter = 0, maxright = 0;
        for (int i = 1; i < tmp.size() - 1; ++i) {
            int i_mirror = 2 * maxcenter - i;
            len[i] = maxright > i ? min(len[i_mirror], maxright - i) : 0;
            //expand
            while (tmp[i+1+len[i]] == tmp[i-1-len[i]])
                ++len[i];
            //fresh
            if (i+len[i] > maxright) {
                maxcenter = i;
                maxright = i + len[i];
            }
        }
        //iterate to get the max
        int start = 0, maxlen = 0;
        for (int i = 1; i < tmp.size() - 1; ++i) {
            if (len[i] > maxlen){
                start = (2 * i - i - len[i] + 1) / 2 - 1; //index in s
                maxlen = len[i];
            }
        }
        cout << start ;
        return s.substr(start, maxlen);
    }
};