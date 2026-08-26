class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int left = 0;
        long long windowsum = 0;
        int maxfreq = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            windowsum += nums[i];

            while((long long)nums[i] * (i - left + 1) - windowsum > k)
            {
                windowsum -= nums[left];
                left++;
            }

            maxfreq = max(maxfreq, i - left + 1);
        }

        return maxfreq;
    }
};