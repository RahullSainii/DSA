class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        // Take first k cards from the left
        int lsum = 0;
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        int rsum = 0;
        int ans = lsum;

        // Gradually remove from left and take from right
        int r = n - 1;

        for (int i = k - 1; i >= 0; i--) {

            lsum -= cardPoints[i];

            rsum += cardPoints[r];

            r--;

            ans = max(ans, lsum + rsum);
        }

        return ans;
    }
};