class Solution {
public:
bool canfinish(vector<int> piles,int h,int k)
{
    long long hours=0;
    for(int x:piles)
    {
        hours+=(x+k-1)/k;
        if(hours>h)
        return false;
    }
    return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int  high= *max_element(piles.begin(),piles.end());
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(canfinish(piles,h,mid))
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
        
    };
};