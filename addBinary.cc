class Solution {
public:
    string addBinary(string a, string b) {
/*        int carry = 0;
        string r;
        int i,j;
        for (i = a.size()-1, j = b.size()-1; i >= 0 && j >= 0; --i, --j) {
            if (carry) {
                if (a[i]=='0'&&b[j]=='0') {r.insert(r.begin(),'1'); carry=0;}
                else if (a[i]=='1'&&b[j]=='1') {r.insert(r.begin(),'1'); carry=1;}
                else {r.insert(r.begin(),'0'); carry=1;}
            }
            else {
                if (a[i]=='0'&&b[j]=='0') {r.insert(r.begin(),'0'); carry=0;}
                else if (a[i]=='1'&&b[j]=='1') {r.insert(r.begin(),'0'); carry=1;}
                else {r.insert(r.begin(),'1'); carry=0;}
            }
        }
        //
        while (i>=0) {
            if (carry) {
                if (a[i]=='1') {r.insert(r.begin(),'0'); carry=1;}
                else {r.insert(r.begin(),'1'); carry=0;}
            }
            else {
                r.insert(r.begin(),a[i]);
            }
            --i;
        } 
        while (j>=0) { 
            if (carry) {
                if (b[j]=='1') {r.insert(r.begin(),'0'); carry=1;}
                else {r.insert(r.begin(),'1'); carry=0;}
            }
            else {
                r.insert(r.begin(),b[j]);
            }
            --j;
        } 
        if (carry)
            r.insert(r.begin(),'1');
        return r;*/
        
        //可以统一运算，在ij遍历完成后用0填充，保证遍历方法的一致性
        //short way
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        string r;
        while (i >= 0 || j >= 0 || carry >0) {
            carry += i >= 0 ? a[i--] - '0' : 0;
            carry += j >= 0 ? b[j--] - '0' : 0;
            r = char (carry % 2 + '0') + r;
            carry /= 2;
        }
        return r;
    }
};