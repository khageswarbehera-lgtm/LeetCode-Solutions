class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // {start, end, weight, original index}
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by ending point
        sort(a.begin(), a.end(),
             [](const auto& x, const auto& y) {
                 if (x[1] != y[1])
                     return x[1] < y[1];

                 return x[0] < y[0];
             });

        // dp[i][k] = best answer using first i intervals
        // and selecting at most k intervals
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );

        // Find last interval whose end < current start
        auto findPrev = [&](int i) {

            int start = a[i][0];

            int lo = 0;
            int hi = i - 1;
            int ans = -1;

            while (lo <= hi) {

                int mid = lo + (hi - lo) / 2;

                if (a[mid][1] < start) {
                    ans = mid;
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }

            return ans;
        };

        for (int i = 1; i <= n; i++) {

            int idx = i - 1;

            for (int k = 1; k <= 4; k++) {

                // Option 1: Don't take current interval
                dp[i][k] = dp[i - 1][k];

                // Option 2: Take current interval
                int p = findPrev(idx);

                long long newWeight =
                    dp[p + 1][k - 1].first + a[idx][2];

                vector<int> newIndices =
                    dp[p + 1][k - 1].second;

                newIndices.push_back(a[idx][3]);

                sort(newIndices.begin(), newIndices.end());

                // Update if weight is better
                // or same weight but lexicographically smaller
                if (newWeight > dp[i][k].first ||
                    (newWeight == dp[i][k].first &&
                     newIndices < dp[i][k].second)) {

                    dp[i][k] = {
                        newWeight,
                        newIndices
                    };
                }
            }
        }

        return dp[n][4].second;
    }
};