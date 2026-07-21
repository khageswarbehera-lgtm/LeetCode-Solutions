class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.empty())
            return 0;

        int st = 0;
        int end = 1;

        while(end < nums.size())
        {
            if(nums[st] != nums[end])
            {
                nums[++st] = nums[end];
            }
            end++;
        }

        return st + 1;
    }
};