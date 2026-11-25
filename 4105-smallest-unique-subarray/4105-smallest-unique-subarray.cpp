class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        const long long MOD = 1000000007LL;
        const long long BASE = 911382323LL;

        vector<long long> power(n + 1, 1);
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            power[i + 1] = (power[i] * BASE) % MOD;
            pref[i + 1] = (pref[i] * BASE + nums[i]) % MOD;
        }

        auto getHash = [&](int l, int r) {
            long long h =
                (pref[r + 1] - pref[l] * power[r - l + 1]) % MOD;
            if (h < 0) h += MOD;
            return h;
        };

        auto check = [&](int len) {
            unordered_map<long long, int> freq;

            for (int i = 0; i + len - 1 < n; i++) {
                freq[getHash(i, i + len - 1)]++;
            }

            for (auto &p : freq) {
                if (p.second == 1) return true;
            }
            return false;
        };

        int ans = n;
        int lo = 1, hi = n;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (check(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }
};