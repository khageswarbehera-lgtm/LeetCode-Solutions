class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            long long cost = costs[i - 1];

            dp[i] = min(dp[i], dp[i - 1] + cost + 1);

            if (i >= 2)
                dp[i] = min(dp[i], dp[i - 2] + cost + 4);

            if (i >= 3)
                dp[i] = min(dp[i], dp[i - 3] + cost + 9);
        }

        return (int)dp[n];
    }
};