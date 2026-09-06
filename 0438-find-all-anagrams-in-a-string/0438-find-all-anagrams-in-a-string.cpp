class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if (p.length() > s.length())
            return ans;

        vector<int> freqP(26, 0);
        vector<int> freqWindow(26, 0);

        // Frequency of p
        for (char ch : p) {
            freqP[ch - 'a']++;
        }

        int k = p.length();

        // First window
        for (int i = 0; i < k; i++) {
            freqWindow[s[i] - 'a']++;
        }

        if (freqWindow == freqP)
            ans.push_back(0);

        // Slide the window
        for (int i = k; i < s.length(); i++) {

            // Add new character
            freqWindow[s[i] - 'a']++;

            // Remove old character
            freqWindow[s[i - k] - 'a']--;

            // Check anagram
            if (freqWindow == freqP) {
                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};