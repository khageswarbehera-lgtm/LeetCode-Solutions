class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> prev(k, 0);

        for (int num : nums) {
            vector<long long> cur(k, 0);

            int r = num % k;

            // Subarray containing only num
            cur[r]++;

            // Extend previous subarrays
            for (int j = 0; j < k; j++) {
                int newR = (j * r) % k;
                cur[newR] += prev[j];
            }

            prev = cur;

            // Add all subarrays ending here
            for (int j = 0; j < k; j++) {
                ans[j] += cur[j];
            }
        }

        return ans;
    }
};