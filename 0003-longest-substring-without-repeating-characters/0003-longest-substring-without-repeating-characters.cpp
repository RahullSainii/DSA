class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int maxLen = 0;

        map<char, int> m;

        while (r < n) {
            // Character already exists in current window
            if (m.find(s[r]) != m.end()) {
                l = max(l, m[s[r]] + 1);
            }

            // Store/update the latest index
            m[s[r]] = r;

            // Calculate current window length
            maxLen = max(maxLen, r - l + 1);

            r++;
        }

        return maxLen;
    }
};