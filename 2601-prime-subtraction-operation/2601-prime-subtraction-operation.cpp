class Solution {
public:
    bool isprime[1000];
    void sieve(){
        fill(isprime,isprime+1000,true);
        isprime[0]=false;
        isprime[1]=false;
        for(int i=2;i*i<1000;i++){
            if(isprime[i]==true){
                for(int j=i*i;j<1000;j+=i){
                    isprime[j]=false;
                }
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        sieve();
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                continue;
            }
            //check prime numbers less than nums[i]
            for(int p=2;p<nums[i];p++){
                if(!isprime[p]){
                    continue;
                }
                if(nums[i]-p<nums[i+1]){
                    nums[i]-=p;
                    break;
                }
            }
          if(nums[i]>=nums[i+1]){
                return false;  
        }
        }
        return true;
    }
};