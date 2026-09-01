class Solution {
public:
    bool canship(vector<int> weights, int w, int day)
    {
        int days=1;
        int currweight=0;
        for(int x:weights)
        {
            if((currweight+x)>w)
            {
                days++;
                currweight=x;
            }
            else
            currweight+=x;
        }
            return days<=day;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
            for(int x:weights)
            {
                high+=x;
            }
             while(low < high)
             {
                int mid = low + (high - low) / 2;

                if(canship(weights, mid, days)) {
                    high = mid;
                }
                else {
                    low = mid + 1;
                }
            }
            return low;
        
    }
};