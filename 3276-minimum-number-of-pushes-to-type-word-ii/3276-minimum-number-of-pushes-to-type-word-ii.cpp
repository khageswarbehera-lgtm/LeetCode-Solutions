#include "../common/strings.hpp"

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq = lc::lowercaseFrequency(word);

        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < lc::kAlphabet; i++) {
            if (freq[i] == 0) break;
            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};