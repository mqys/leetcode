class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        res[1] = 1;
        int pre = 1;
        int cur = 2;
        int nex = 4;
        for (int i = 2; i <= num; ++i) {
            if (i == nex) {
                pre = cur;
                cur = nex;
                nex = nex << 1;
            }
            if (i - cur + pre < cur) //pre-half
                res[i] = res[pre + i - cur];
            else // post-half
                res[i] = res[pre + i - cur - pre] + 1;
        }
        return res;
    }
};