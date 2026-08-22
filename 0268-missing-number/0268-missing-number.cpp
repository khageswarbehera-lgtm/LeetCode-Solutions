class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorall=0;
        int xorarr=0;
        for(int i=1;i<=nums.size();i++)
        {
            xorall^=i;
        }
        for(int x:nums)
        {
            xorarr^=x;
        }
        return xorall^xorarr;
    }
};