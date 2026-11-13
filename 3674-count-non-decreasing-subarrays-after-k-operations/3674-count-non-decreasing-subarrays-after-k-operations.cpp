class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;
        int r = n - 1;
        deque<int> dq;

        for (int l = n - 1; l >= 0; --l) {
            while (!dq.empty() && nums[dq.front()] < nums[l]) {
                int idx = dq.front();
                dq.pop_front();
                int next_idx = dq.empty() ? r + 1 : dq.front();
                cost += 1LL * (nums[l] - nums[idx]) * (next_idx - idx);
            }
            dq.push_front(l);

            while (cost > k) {
                cost -= nums[dq.back()] - nums[r];
                if (dq.back() == r) {
                    dq.pop_back();
                }
                --r;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};