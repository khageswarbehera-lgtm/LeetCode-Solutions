class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = how many characters of word2
        // cannot be matched using word1[i...n-1]
        vector<int> suf(n + 1, m);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j])
                j--;

            suf[i] = j + 1;
        }

        vector<int> ans;

        j = 0;
        bool usedMismatch = false;

        for (int i = 0; i < n && j < m; i++) {

            // Exact match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Use our one allowed mismatch
            else if (!usedMismatch) {

                // Check whether the remaining part can
                // still complete word2.
                int matchedFromSuffix = m - suf[i + 1];

                if (j + 1 + matchedFromSuffix >= m) {
                    ans.push_back(i);
                    j++;
                    usedMismatch = true;
                }
            }
        }

        if (ans.size() != m)
            return {};

        return ans;
    }
};