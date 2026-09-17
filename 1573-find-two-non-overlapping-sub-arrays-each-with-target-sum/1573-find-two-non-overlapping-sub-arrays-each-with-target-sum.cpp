class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1e9;

        // dp[i] = minimum length of a valid subarray
        // completely inside arr[0 ... i-1]
        vector<int> dp(n + 1, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            dp[right + 1] = dp[right];

            if (sum == target) {
                int len = right - left + 1;

                // Previous subarray must end before left
                if (dp[left] != INF) {
                    ans = min(ans, len + dp[left]);
                }

                dp[right + 1] = min(dp[right + 1], len);
            }
        }

        return ans == INF ? -1 : ans;
    }
};