class Solution {
public:
    int numTrees(int n) {
        // --- 0 ms ---
        // dynamic programming
        // nums[]: the ith element means the result of a tree of i nodes
        // idea: calculate from 1 to n
        //      each time add one node to the tree
        //      3 add methods: leaf, root, connector
        //          leaf and root: has only one way in the former structure
        //          connector: to be the right child and has only left child
        //                      calculate the different num these two sets may have, add up
        // vector<int> nums(n+1, 0);
        // nums[1] = 1;
        // nums[2] = 2;
        // int temp;
        // for (int i = 3; i <= n; ++i) {
        //     // new node to be leaf or root
        //     temp = 2 * nums[i-1];
        //     // new node to be the connector
        //     for (int j = 1; j < i - 1; ++j) {
        //         temp += nums[j] * nums[i-j-1];
        //     }
        //     nums[i] = temp;
        // }
        // return nums[n];
        
        
        // similar code while different idea
        
        // --- 0 ms ---
        // F(i, n): 1 <= i <= n, means the num of tree when i be the root
        // G(n): num of tree of n nodes
        //      F(i, n) = G(i-1) * G(n-i);
        // So: G(n) = G(0)*G(n-1) + G(1)*G(n-2) +...+ G(n-1)*G(0);
        vector<int> nums(n+1, 0);
        nums[0] = 1;
        nums[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j){
                nums[i] += nums[j] * nums[i-j-1];
            }
        }
        return nums[n];
    }
};