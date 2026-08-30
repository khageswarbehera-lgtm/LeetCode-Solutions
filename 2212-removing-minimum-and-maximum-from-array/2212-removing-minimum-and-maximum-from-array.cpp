class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minvalue=INT_MAX;
        int  maxvalue= INT_MIN;
        int minindex=0;
        int maxindex=0;
        for(int i=0;i<nums.size();i++)
        {
            if(minvalue>nums[i])
            {
                minvalue=nums[i];
                minindex=i;
            }
            if(maxvalue<nums[i])
            {
                maxvalue=nums[i];
                maxindex=i;
            }
        }
            int right=max(minindex,maxindex);
            int left=min(minindex,maxindex);

            int option1= right+1;
            int option2  = nums.size()-left;
            int option3=left+nums.size()-right +1;
            int ans=min({option1,option2,option3});
            return ans;       
            
            return ans;
            
        
        
    }
};