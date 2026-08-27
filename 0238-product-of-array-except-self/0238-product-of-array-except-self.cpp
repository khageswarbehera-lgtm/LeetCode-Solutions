class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix(nums.size());
        int suffix=1;

       prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i]=prefix[i-1]*nums[i];
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i==0)
            prefix[i]=suffix;
            else
            prefix[i]=prefix[i-1]*suffix;
            suffix=suffix*nums[i];
        }
        return prefix;

        
    }
};