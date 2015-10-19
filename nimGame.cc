class Solution {
public:
    bool canWinNim(int n) {
        // after first pick to make the remain be 4*X, if cannot then will lose
        if (n % 4 == 0)
            return false;
        return true;
    }
};