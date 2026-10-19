class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         // Append nums2 to the available positions
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        // Sort the entire array
        sort(nums1.begin(), nums1.end());
    }
};