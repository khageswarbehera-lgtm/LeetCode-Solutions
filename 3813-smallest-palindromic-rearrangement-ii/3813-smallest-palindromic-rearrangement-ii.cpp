#include "../common/strings.hpp"

class Solution {
public:
    static const long long LIMIT = 1000001;

    long long C(int n, int k) {
        if (k > n) return 0;
        k = min(k, n - k);

        long long ans = 1;

        for (int i = 1; i <= k; i++) {
            ans = ans * (n - i + 1) / i;
            if (ans >= LIMIT) return LIMIT;
        }

        return ans;
    }

    long long countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        long long ans = 1;

        for (int i = 0; i < lc::kAlphabet; i++) {
            ans *= C(total, cnt[i]);
            if (ans >= LIMIT) return LIMIT;
            total -= cnt[i];
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        auto [half, mid] = lc::palindromeHalfCounts(lc::lowercaseFrequency(s));

        int len = accumulate(half.begin(), half.end(), 0);

        if (countWays(half) < k)
            return "";

        string left;

        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < lc::kAlphabet; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        return lc::mirrorPalindrome(left, mid);
    }
};