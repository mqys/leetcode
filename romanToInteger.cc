class Solution {
public:
    int getNum(char c) {
        switch(c) {
            case 'I': return 1;break;
            case 'X': return 10;break;
            case 'C': return 100;break;
            case 'M': return 1000;break;
            case 'V': return 5;break;
            case 'L': return 50;break;
            case 'D': return 500;break;
        }
    }
    int romanToInt(string s) {
        int sum = 0, cur, nex, i;
        for (i = 0; i < s.size() - 1; ++i) {
            cur = getNum(s[i]);
            nex = getNum(s[i+1]);
            if (cur < nex) 
                sum -= cur;
            else
                sum += cur;
        }
        sum += getNum(s[i]);
        return sum;
        
    }
};