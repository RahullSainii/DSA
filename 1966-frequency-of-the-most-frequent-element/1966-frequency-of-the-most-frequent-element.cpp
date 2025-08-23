class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
        long long total = 0;  // use long long to avoid overflow
        int l = 0, res = 1;

        for (int r = 0; r < nums.size(); r++) {
            total += nums[r];

            // while cost exceeds k, shrink the window
            while ((long long)(r - l + 1) * nums[r] - total > k) {
                total -= nums[l];
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};