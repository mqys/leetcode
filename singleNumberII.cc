class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // think about every bit, the times it appears should be counted, could use two bits to record that
        // [highbit : lowbit] to record the times, 00->3/0, 01->1, 10->2
        // another think: if lowbit==1 then this bit appears once, if highbit==1 then this bit appears twice
        // process: write down the bit change conditions, then form the bit movement
        
        int lowbit = 0, highbit = 0;
        for (int n : nums) {
            // careful with the order of next two lines
            // hard to figure it out
            lowbit = (lowbit ^ n) & ~highbit;
            highbit = (highbit ^ n) & ~lowbit;
            
            // cout << "n: " << bitset<sizeof(int)*8>(n) << endl;
            // cout << "   " << bitset<sizeof(int)*8>(highbit) << endl;
            // cout << "   " << bitset<sizeof(int)*8>(lowbit) << endl;
            // cout << "----------------------------------" << endl;
        }
        return lowbit;
    }
};