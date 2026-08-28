class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        int circularsum;
        int minsum=INT_MAX;
        int maxsum=INT_MIN;
        int sum1=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            totalsum+=nums[i];

           sum+=nums[i];
           maxsum=max(sum,maxsum);
           if(sum<0)
           sum=0;

        }

        for(int i=0;i<n;i++)
        {

           sum1+=nums[i];
           minsum=min(sum1,minsum);
           if(sum1>0)
           sum1=0;

        }
        circularsum=max(maxsum,totalsum-minsum);
        if (maxsum<0)
        return maxsum;
        return circularsum;
        
    }
};