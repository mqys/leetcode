class Solution {
public:
    string intToRoman(int num) {
        // way 1: --- 40 ms ---
        // I	V	X	L	C	D	M
        // 1    5   10  50  100 500 1000
        // in the oj, 49 -> XLIX , not IL
        // so the number can be interpret figure by figure
        // range: 1 - 3999
        string ans;
        if (num < 1 || num > 3999)
            return ans;
        // int figure, rest = num;
        // int base = 1000;
        // while (rest > 0) {
        //     figure = rest / base;
        //     rest -= figure * base;
        //     ans += interpret(figure, base);
        //     base /= 10;
        // }
        // return ans;
        
        // way 2: --- 32 ms ---
        // use table when a lot of cases need to be classified
        int len = 13;
        int value [] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string re [] = {"M", "CM", "D", "CD","C", "XC","L","XL","X","IX","V","IV","I"};
        for (int i = 0; i < len; ++i) {
            while (num >= value[i]) {
                num -= value[i];
                ans += re[i];
            }
        }
        return ans;
        
    }
    // interpret each figure
    string interpret(int figure, int base) {
        string re;
        // 1000
        if (base == 1000) {
            while (figure--) 
                re += "M";
            return re;
        } // 100
        if (base == 100) {
            if (figure == 4 || figure == 9)
                return figure == 4 ? "CD" : "CM";
            if (figure >= 5) {
                re = "D";
                figure -= 5;
                while (figure--)
                    re += "C";
                return re;
            }
            while (figure--) 
                re += "C";
            return re;            
        }// 10
        if (base == 10) {
            if (figure == 4 || figure == 9)
                return figure == 4 ? "XL" : "XC";
            if (figure >= 5) {
                re = "L";
                figure -= 5;
                while (figure--) 
                    re += "X";
                return re;
            }
            while (figure--)
                re += "X";
            return re;
        }
        // 1
        if (figure == 4 || figure == 9)
            return figure == 4 ? "IV" : "IX";
        if (figure >= 5) {
            re = "V";
            figure -= 5;
            while (figure--) 
                re += "I";
            return re;
        }
        while (figure--) 
            re += "I";
        return re;
            
        
    }
};