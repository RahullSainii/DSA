class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
       long long int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0, low = nums.size() - 1, high = nums.size() - 1; i < nums.size(); i++){
            while((low > i) && ((nums[i] + nums[low]) >= lower)) low--;
            while((high > i) && ((nums[i] + nums[high]) > upper)) high--;
            if(high <= i) break;
            res += high - max(low, i);
        }
        return res;
    }
};