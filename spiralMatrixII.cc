class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        
        int i = 0, j = -1;
        int now = 1;
        while (now <= n * n) {
            while (j+1 < n && !res[i][j+1]) res[i][++j] = now++;
            while (i+1 < n && !res[i+1][j]) res[++i][j] = now++;
            while (j-1 >= 0 && !res[i][j-1]) res[i][--j] = now++;
            while (i-1 >= 0 && !res[i-1][j]) res[--i][j] = now++;
        }
        
        return res;
    }
};