class Solution {
public:
    int climbStairs(int n) {
        // 动态规划思想： 分析当前状态与前两状态之间的联系

        // 此种递归中两个函数重叠递归，交叉重复计算，效率很低
        // if (n < 2) return 1;
        // if (n == 2) return 2;
        // return climbStairs(n-1) + climbStairs(n-2);
        
        if (n < 2) return 1;
        if (n == 2) return 2;
        int ppre = 1, pre = 2, r, temp;
        while (n > 2) {
            r = ppre + pre;
            ppre = pre;
            pre = r;
            --n;
        }
        return r;
    }
};