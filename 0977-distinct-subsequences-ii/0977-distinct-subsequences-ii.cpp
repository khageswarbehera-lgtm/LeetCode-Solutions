class Solution {
public:
    int distinctSubseqII(string s) {

        const long long MOD = 1e9 + 7;

        int n = s.length();

        vector<long long> dp(n + 1, 0);

        // dp[0] = 1
        // empty subsequence
        dp[0] = 1;

        // last[c] = position of previous occurrence
        vector<int> last(26, -1);

        for (int i = 1; i <= n; i++) {

            int index = s[i - 1] - 'a';

            // Take or don't take current character
            dp[i] = (2 * dp[i - 1]) % MOD;

            // If character appeared before
            if (last[index] != -1) {

                dp[i] -= dp[last[index]];

                dp[i] = (dp[i] + MOD) % MOD;
            }

            last[index] = i - 1;
        }

        // Remove empty subsequence
        return (dp[n] - 1 + MOD) % MOD;
    }
};