class Solution {
public:
    int custombinarysearch(vector<vector<int>>&items,int queryprice){
        int l=0;
        int r=items.size()-1;
        int mid;
        int maxbeauty=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(items[mid][0]>queryprice){
                r=mid-1;
            }
            else{
                maxbeauty=max(maxbeauty,items[mid][1]);
                l=mid+1;
            }
        }
        return maxbeauty;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=items.size();
        int m=queries.size();
        vector<int>result(m);
        sort(begin(items),end(items));
        int maxbeautyseen=items[0][1];
        for(int i=1;i<n;i++){
            maxbeautyseen=max(maxbeautyseen,items[i][1]);
            items[i][1]=maxbeautyseen;
        }
        for(int i=0;i<m;i++){
            int queryprice=queries[i];
            result[i]=custombinarysearch(items,queryprice);
        }
        return result;
    }
};