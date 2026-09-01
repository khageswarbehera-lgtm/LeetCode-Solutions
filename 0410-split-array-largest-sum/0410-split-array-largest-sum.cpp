class Solution {
public:

    bool canSplit(vector<int>& nums, int maxSum, int k)
    {
        int parts = 1;
        int currentSum = 0;

        for(int x : nums)
        {
            if(currentSum + x > maxSum)
            {
                parts++;
                currentSum = x;
            }
            else
            {
                currentSum += x;
            }
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums, int k)
    {
        int low = *max_element(nums.begin(), nums.end());

        int high = 0;

        for(int x : nums)
        {
            high += x;
        }

        while(low < high)
        {
            int mid = low + (high - low) / 2;

            if(canSplit(nums, mid, k))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};