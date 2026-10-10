
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<long long> diff(n);
        long long maxDiff = 0, total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            total += diff[i];
        }

        if (k >= total) return 0;

        // Minimum maximum difference achievable
        long long low = 0, high = maxDiff;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long ops = 0;

            for (long long d : diff) {
                if (d > mid)
                    ops += d - mid;
            }

            if (ops <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long limit = low;
        long long ops = 0;
        long long ans = 0;

        for (long long d : diff) {
            if (d > limit)
                ops += d - limit;

            long long reduced = min(d, limit);
            ans += reduced * reduced;
        }

        // Use leftover operations to reduce limit to limit - 1
        long long remaining = k - ops;
        ans -= remaining * (2 * limit - 1);

        return ans;
    }
};
