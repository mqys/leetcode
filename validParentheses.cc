class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == ')') {
                if (!st.empty() && st.top() == '(') {st.pop();continue;}
                else return false;
            }
            if (c == ']') {
                if (!st.empty() && st.top() == '[') {st.pop();continue;}
                else return false;
            }
            if (c == '}') {
                if (!st.empty() && st.top() == '{') {st.pop();continue;}
                else return false;
            }
            st.push(c);
        }
        return st.empty() ? true : false; // return st.empty(); will do!
        
        //can be simplify by using case
    }
};