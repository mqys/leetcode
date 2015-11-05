class Solution {
public:
    string getHint(string secret, string guess) {
        // hash map secret and record the index -- 24ms
        // unordered_map<char, int> hm;// <char, num>
        // unordered_set<int> ns; // need to record the bulls index to avoid reuse in cows compare
        // int bulls = 0, cows = 0;
        // for (int i = 0; i < secret.size(); ++i) {
        //     if (secret[i] == guess[i]) {
        //         ++bulls;
        //         ns.insert(i);
        //     } else {
        //         ++hm[secret[i]];
        //     }
        // }
        // for (int j = 0; j < guess.size(); ++j) {
        //     if (ns.find(j) != ns.end())
        //         continue;
        //     auto search = hm.find(guess[j]);
        //     if (search != hm.end() && search->second > 0) {
        //         ++cows;
        //         --hm[guess[j]];
        //     }
        // }
        
        // try one pass -- 12ms 
        unordered_map<char, int> hm;
        int bulls = 0, cows = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i])
                ++bulls;
            else {
                if (hm[secret[i]]++ < 0) ++cows;  // if < 0, num show in guess before
                if (hm[guess[i]]-- > 0) ++cows;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};