class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        vector<long long> cost = getCosts(nums, x);

        int m = cost.size();
        const long long INF = 4e18;

        vector<vector<long long>> dp(m + x + 5,
                                     vector<long long>(k + 1, INF));

        for (int i = 0; i < (int)dp.size(); i++)
            dp[i][0] = 0;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i + 1][j];

                long long take = cost[i];
                if (i + x < (int)dp.size())
                    take += dp[i + x][j - 1];

                dp[i][j] = min(dp[i][j], take);
            }
        }

        return dp[0][k];
    }

private:
    vector<long long> getCosts(vector<int>& nums, int x) {
        multiset<long long> L, R;
        long long sumL = 0, sumR = 0;

        auto balance = [&]() {
            while (L.size() < R.size()) {
                auto it = R.begin();
                long long v = *it;
                R.erase(it);
                sumR -= v;

                L.insert(v);
                sumL += v;
            }

            while (L.size() > R.size() + 1) {
                auto it = prev(L.end());
                long long v = *it;
                L.erase(it);
                sumL -= v;

                R.insert(v);
                sumR += v;
            }
        };

        vector<long long> res;

        for (int i = 0; i < nums.size(); i++) {
            long long v = nums[i];

            if (L.empty() || v <= *prev(L.end())) {
                L.insert(v);
                sumL += v;
            } else {
                R.insert(v);
                sumR += v;
            }

            balance();

            if (i >= x) {
                long long out = nums[i - x];

                auto it = L.find(out);
                if (it != L.end()) {
                    L.erase(it);
                    sumL -= out;
                } else {
                    it = R.find(out);
                    R.erase(it);
                    sumR -= out;
                }

                balance();
            }

            if (i >= x - 1) {
                long long med = *prev(L.end());

                long long cur =
                    med * (long long)L.size() - sumL +
                    sumR - med * (long long)R.size();

                res.push_back(cur);
            }
        }

        return res;
    }
};