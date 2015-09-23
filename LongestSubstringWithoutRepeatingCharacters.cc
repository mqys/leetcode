class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //out of time
        // unordered_set<int> se;
        // int maxlen = 0;
        // for(int i=0; i < s.size(); ++i){
        //     for(int j = i; j < s.size(); ++j){
        //         auto r = se.insert(s[j]);
        //         if(r.second == 0){ //get repeated one
        //             maxlen = se.size()>maxlen ? se.size():maxlen;
        //             se.clear();
        //             break;
        //         }
        //     }
        //     maxlen = se.size()>maxlen ? se.size():maxlen;
        // }
        // return se.size()>maxlen? se.size():maxlen;
        
        unordered_map<char, int> hm; // char index
        int maxlen = 0, len = 0;
        int i = 0, j = 0;
        for(;j<s.size();++j){
            auto r = hm.find(s[j]);
            //old char in hm, notice the working part of hm!!! valid range!!!
            if(( r != hm.end())&&(r->second >= i)){ 
                len = j - i;
                maxlen = maxlen > len? maxlen:len; //fresh maxlen
                i = hm[s[j]] + 1;
                hm[s[j]] = j; //fresh index
                len = j - i + 1;
                // cout << "in "<<i<<"  "<<j<<" "<<len<<endl;
            }
            else{ // new char
                hm[s[j]] = j; //add 
                ++len;
                // cout << "out "<<i<<" "<<j<<" "<<len<<endl;
            }
        }
        return maxlen > len? maxlen:len;
    }
};