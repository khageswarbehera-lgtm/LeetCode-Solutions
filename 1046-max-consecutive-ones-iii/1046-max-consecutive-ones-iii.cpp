class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int zerocount=0;
        int longestone=0;
        int maxone=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zerocount++;
            }
             while(zerocount>k)
            {
                if(nums[left]==0)
                zerocount--;
                left++;
            }
            longestone=i-left+1;
            maxone=max(maxone,longestone);
        }
        return maxone;
        
    }
};