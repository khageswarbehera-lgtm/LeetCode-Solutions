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

        for (int i = 0; i < 26; i++) {
            ans *= C(total, cnt[i]);
            if (ans >= LIMIT) return LIMIT;
            total -= cnt[i];
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1) {
                mid = char('a' + i);
                freq[i]--;
                break;
            }
        }

        vector<int> half(26);

        int len = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];
        }

        if (countWays(half) < k)
            return "";

        string left;

        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

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

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + string(1, mid) + right;

        return left + right;
    }
};