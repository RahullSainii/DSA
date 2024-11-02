class Solution {
public:
vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};//pair found
                }
            }
        }
    return{};//return an empty vector if no integer is there
    }
};