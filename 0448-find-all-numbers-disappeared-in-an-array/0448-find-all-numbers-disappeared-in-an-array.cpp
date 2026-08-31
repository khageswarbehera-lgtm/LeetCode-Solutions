class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        unordered_set<int> st(nums.begin(),nums.end());
        int x=1;
        while(x<=n)
        {
            if(st.find(x)==st.end())
            ans.push_back(x);
            x++;
        }
        return ans;

        
    }
};