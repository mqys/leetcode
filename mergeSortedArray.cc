class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // --- lazy way 4ms
        // nums1.insert(nums1.begin() + m, nums2.begin(), nums2.begin() + n);
        // sort(nums1.begin(), nums1.begin() + m + n);
        // nums1.resize(m + n); // delete extra element
        
        // hand way 12ms
        // from back to front
        int i = m - 1,
            j = n - 1,
            k = m + n -1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};