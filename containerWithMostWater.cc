class Solution {
public:
    int maxArea(vector<int>& height) {
        //---TLE---
        // int b, h, s, max = 0;
        // for (int i = 0; i < height.size() - 1; ++i) {
        //     for (int j = i + 1; j <height.size(); ++j) {
        //         s = (j - i) * min(height[i], height[j]);
        //         max = s > max ? s : max;
        //     }
        // }
        // return max;
        
        /*
            two pointers: left right
            move pointers to the center
            move the lower side and skip when next wall is lower than current
        */
        int left = 0, right = height.size() - 1;
        int max = 0, size = 0;
        while (left < right) {
            size = (right - left) * (height[left] > height[right] ? height[right]:height[left]);
            max = max > size ? max : size;
            if (height[left] > height[right]) {
                //move right
                do {
                    --right;
                } while (height[right] < height[right + 1]);
            }
            else {
                //move left
                do {
                    ++left;
                } while (height[left] < height[left - 1]);
            }
        }
        return max;
    }
};