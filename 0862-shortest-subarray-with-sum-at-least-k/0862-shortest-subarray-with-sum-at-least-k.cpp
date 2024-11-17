class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>deq;//stores index in monotonic increasing order 
        vector<long long>cumulativesum(n,0);
        int result=INT_MAX;
        int j=0;
        while(j<n){
            if(j==0){
                cumulativesum[j]=nums[j];
            }
            else{
                cumulativesum[j]=cumulativesum[j-1]+nums[j];
            }
            if(cumulativesum[j]>=k){
                result=min(result,j+1);
            }
            //need to shrink window or not
            while(!deq.empty() && cumulativesum[j]-cumulativesum[deq.front()]>=k){
                result=min(result,j-deq.front());
                deq.pop_front();
            }
            while(!deq.empty() && cumulativesum[j]<=cumulativesum[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(j);
            j++;
        }
        return result==INT_MAX? -1:result;
    }
};