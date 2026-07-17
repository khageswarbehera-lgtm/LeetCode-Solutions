class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<long long> cntG(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {

            long long cnt = 0;

            for (int j = g; j <= mx; j += g)
                cnt += freq[j];

            cntG[g] = cnt * (cnt - 1) / 2;

            for (int j = g + g; j <= mx; j += g)
                cntG[g] -= cntG[j];
        }

        vector<long long> prefix(mx + 1, 0);

        for (int i = 1; i <= mx; i++)
            prefix[i] = prefix[i - 1] + cntG[i];

        vector<int> ans;

        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1,
                                prefix.end(),
                                q + 1) - prefix.begin();

            ans.push_back(g);
        }

        return ans;
    }
};