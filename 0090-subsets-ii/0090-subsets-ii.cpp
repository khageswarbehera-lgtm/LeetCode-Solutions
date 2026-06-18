class Solution {
public:
void subset(int start,vector<int> &nums,vector<int>&curr,vector<vector<int>> &result)
{
    result.push_back(curr);
    for(int i=start;i<nums.size();i++)
    {
        if(i>start && nums[i]==nums[i-1])continue;
        curr.push_back(nums[i]);
        subset(i+1,nums,curr,result);
        curr.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int>curr;
        subset(0,nums,curr,result);
        return result;
        
    }
};