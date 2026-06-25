class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] == k)
                    count++;

                int len = j - i + 1;

                if (2 * count > len)
                    ans++;
            }
        }

        return ans;
    }
};