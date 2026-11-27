class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        const int MAXF = 1500;

        vector<int> freq(MAXF + 1);

        for (auto &x : items)
            freq[x[0]]++;

        vector<int> cnt(MAXF + 1);

        for (int f = 1; f <= MAXF; f++) {
            for (int m = f; m <= MAXF; m += f) {
                cnt[f] += freq[m];
            }
        }

        vector<int> dp(budget + 1, 0);

        for (auto &x : items) {
            int factor = x[0];
            int price = x[1];

            int gain = cnt[factor];

            vector<int> ndp = dp;

            // buy first copy
            for (int b = 0; b + price <= budget; b++) {
                ndp[b + price] =
                    max(ndp[b + price], dp[b] + gain);
            }

            // extra copies (unbounded)
            for (int b = price; b <= budget; b++) {
                ndp[b] = max(ndp[b], ndp[b - price] + 1);
            }

            dp.swap(ndp);
        }

        return *max_element(dp.begin(), dp.end());
    }
};