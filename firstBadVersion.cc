// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // int s = 0, e = n, mid = s + (e -s) / 2;
        // while ( e - s > 1 && mid > 0) {
        //     mid = s + (e - s) / 2;
        //     if (isBadVersion(mid)) 
        //         e = mid;
        //     else
        //         s = mid;
        // }
        // return e;
        
        int s = 1, e = n, mid;
        while (s < e) {
            mid = s + (e - s) / 2;
            if (isBadVersion(mid))
                e = mid;
            else
                s = mid + 1;
        }
        return s;
    }
};