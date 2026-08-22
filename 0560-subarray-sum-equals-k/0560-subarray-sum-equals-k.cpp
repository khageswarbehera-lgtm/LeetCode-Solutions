class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int sum=0;
    int ans=0;
    mp[0]=1;
    for(int x:nums)
    {
        sum +=x;
        int required=sum-k;
        if(mp.find(required)!=mp.end())
        ans+=mp[required];
        mp[sum]++;
    }        
    return ans;
    }
};