class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> mp;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            // Character already appeared
            if (mp.count(s[right])) {
                left = max(left, mp[s[right]] + 1);
            }

            // Store latest position
            mp[s[right]] = right;

            // Current window length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};