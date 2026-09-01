class Solution {
public:

    bool canMake(vector<int>& bloomDay, int day, int m, int k)
    {
        int bouquets = 0;
        int consecutive = 0;

        for(int x : bloomDay)
        {
            if(x <= day)
            {
                consecutive++;

                if(consecutive == k)
                {
                    bouquets++;

                    consecutive = 0;
                }
            }
            else
            {
                consecutive = 0;
            }
        }

        return bouquets >= m;
    }


    int minDays(vector<int>& bloomDay, int m, int k)
    {
        int n = bloomDay.size();

        if((long long)m * k > n)
            return -1;

        int low = *min_element(
            bloomDay.begin(),
            bloomDay.end()
        );

        int high = *max_element(
            bloomDay.begin(),
            bloomDay.end()
        );

        while(low < high)
        {
            int mid = low + (high - low) / 2;

            if(canMake(bloomDay, mid, m, k))
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