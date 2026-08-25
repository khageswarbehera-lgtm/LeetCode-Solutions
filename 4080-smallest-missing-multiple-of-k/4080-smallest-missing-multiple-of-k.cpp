class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        if(nums.empty())
        return k;
        unordered_set<int> st(nums.begin(),nums.end());
        int i=1;
        while(i>0)
        {
            if(st.find(k*i)==st.end())
            return k*i;
            i++;
        }
        return 0;

        
    }
};