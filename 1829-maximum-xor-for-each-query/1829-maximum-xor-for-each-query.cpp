class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int>result(n);
        //find total xor
        int XOR=0;
        for(int i=0;i<n;i++){
            XOR^=nums[i];
        }
        //to find flipmfirst find mask having all bits set to 1
        int mask((1<<maximumBit)-1);
        for(int i=0;i<n;i++){
            int k=XOR^mask;//this will give flipped value of xor 
            result[i]=k;
            XOR=(XOR^nums[n-1-i]);//rightmost values ka XOR niklega only jonse index pai honge
        }
        return result;
    }
};