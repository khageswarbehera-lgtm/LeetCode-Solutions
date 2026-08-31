class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int missing;
        int duplicate;
        unordered_map<int,int>mp;
          for(int x : nums)
            mp[x]++;
        for(int i = 1; i <= nums.size(); i++)
        {
            if(mp[i] == 0)
                missing = i;

            if(mp[i] == 2)
                duplicate = i;
        }
                
        return {duplicate,missing};
        
    }
};