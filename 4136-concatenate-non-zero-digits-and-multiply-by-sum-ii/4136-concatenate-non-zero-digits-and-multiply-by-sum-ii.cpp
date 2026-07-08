class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> pref(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        vector<int> sum(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        long long cur = 0;

        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            sum[i + 1] = sum[i];
            pref[i + 1] = pref[i];

            int d = s[i] - '0';

            if (d != 0) {
                cnt[i + 1]++;
                sum[i + 1] += d;

                cur = (cur * 10 + d) % MOD;
                pref[i + 1] = cur;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int digitCnt = cnt[r + 1] - cnt[l];
            int digitSum = sum[r + 1] - sum[l];

            long long x = (pref[r + 1] -pref[l] * pow10[digitCnt] % MOD + MOD) % MOD;

            ans.push_back((x * digitSum) % MOD);
        }

        return ans;
    }
};