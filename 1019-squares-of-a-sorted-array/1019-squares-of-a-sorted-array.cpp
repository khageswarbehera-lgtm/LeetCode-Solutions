class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=nums.size()-1;
        vector<int> ans(n);
        while(left<=right)
        {
            if(abs(nums[left]) < abs(nums[right]))
            {
                ans[--n]=nums[right]*nums[right];
                right--;
            }
            else
            {
             ans[--n]=nums[left]*nums[left];

                left++;
            }
        }
            return ans;

        
    }
};