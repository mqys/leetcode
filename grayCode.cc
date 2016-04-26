class Solution {
public:

    vector<int> grayCode(int n) {
        // === time out ===
        // vector<int> res(pow(2, n), 0);
        // vector<bool> vis(pow(2, n), false);
        
        // dfs(res, 1, vis);
        // return res;
        
        
        // add one bit each loop
        vector<int> res(1, 0);
        // add n bits
        for (int i = 0; i < n; ++i) {
            int inc = 1 << i;
            // use pre-gen num, in reverse order
            for (int j = res.size()-1; j >= 0; --j) {
                res.push_back(res[j] + inc);
            }
        }
        return res;
    }
    
    
    
    // === time out ===
    // bool dfs(vector<int> &arr, int index, vector<bool> &vis) {
    //     if (index == arr.size()) {
    //         return true;    
    //     }
    //     for (int i = 1; i < vis.size(); ++i) {
    //         if (vis[i])
    //             continue;
    //         // not vis, try
    //         arr[index] = i;
    //         vis[i] = true;
    //         if (isGrey(arr[index], arr[index-1]) && dfs(arr, index+1, vis))
    //             return true;
    //         vis[i] = false;    
    //     }
    //     return false;
        
    // }
    
    // bool isGrey(int a, int b) {
    //     int tmp = a ^ b;
    //     if (tmp && !(tmp & (tmp - 1)))
    //         return true;
    //     return false;
    // }
};