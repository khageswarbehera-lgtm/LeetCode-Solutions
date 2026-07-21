class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> zeroGroups;

        int ones = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                ones++;
            } else {
                if (i == 0 || s[i - 1] == '1')
                    zeroGroups.push_back(1);
                else
                    zeroGroups.back()++;
            }
        }

        int best = 0;

        for (int i = 0; i + 1 < zeroGroups.size(); i++) {
            best = max(best, zeroGroups[i] + zeroGroups[i + 1]);
        }

        return ones + best;
    }
};