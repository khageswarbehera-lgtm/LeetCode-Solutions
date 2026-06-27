class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        if (freq.count(1)) {
            if (freq[1] % 2 == 0)
                ans = max(ans, freq[1] - 1);
            else
                ans = max(ans, freq[1]);
        }

        for (auto &[x, cnt] : freq) {

            if (x == 1)
                continue;

            long long cur = x;
            int len = 0;

            while (true) {

                if (!freq.count(cur))
                    break;

                if (freq[cur] == 1) {
                    len++;
                    break;
                }

                len += 2;

                if (cur > 1000000000LL / cur) {
                    len--;
                    break;
                }

                long long nxt = cur * cur;

                if (!freq.count(nxt)) {
                    len--;
                    break;
                }

                cur = nxt;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};