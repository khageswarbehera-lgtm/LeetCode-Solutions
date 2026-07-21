class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int st = 0;

        for(int end = 0; end < nums.size(); end++)
        {
            if(nums[end] != val)
            {
                nums[st] = nums[end];
                st++;
            }
        }

        return st;
    }
};