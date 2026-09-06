class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> mp;

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            // Add current character
            mp[s[right]]++;

            // Maximum frequency in the window
            maxFreq = max(maxFreq, mp[s[right]]);

            // Window size
            int windowSize = right - left + 1;

            // Too many replacements needed
            while (windowSize - maxFreq > k) {

                mp[s[left]]--;
                left++;

                windowSize = right - left + 1;
            }

            // Valid window
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};