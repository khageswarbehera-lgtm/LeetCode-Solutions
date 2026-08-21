class Solution {
public:

    long long findKthSmallest(vector<int>& coins, int k) {

        int n = coins.size();

        // The answer cannot be greater than:
        // k * smallest coin
        long long left = 1;
        long long right = 1LL * k * (*min_element(coins.begin(), coins.end()));

        // Binary Search
        while (left < right) {

            long long mid = left + (right - left) / 2;

            if (countAmounts(coins, mid) >= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }

private:

    long long countAmounts(vector<int>& coins, long long x) {

        int n = coins.size();

        long long count = 0;

        // Enumerate every non-empty subset
        for (int mask = 1; mask < (1 << n); mask++) {

            long long lcmValue = 1;

            bool tooLarge = false;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    lcmValue = lcm(
                        lcmValue,
                        (long long)coins[i]
                    );

                    // No multiple of this LCM
                    // can be <= x
                    if (lcmValue > x) {
                        tooLarge = true;
                        break;
                    }
                }
            }

            if (tooLarge)
                continue;

            long long multiples = x / lcmValue;

            // Odd number of selected coins:
            // add
            if (__builtin_popcount(mask) % 2 == 1) {
                count += multiples;
            }
            // Even number:
            // subtract
            else {
                count -= multiples;
            }
        }

        return count;
    }
};