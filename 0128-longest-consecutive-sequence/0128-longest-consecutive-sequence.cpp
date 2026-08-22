class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
        return 0;
        unordered_set<int> st(nums.begin(),nums.end());
        int longestcount=0;
       for(int x:st)
       {

        if(st.find(x-1)==st.end())
        {
            int count=1;
            int p=x;
             while(st.find(p+1)!=st.end())
        {
            p++;
            count++;
        }
         longestcount=max(longestcount,count);

        }
       
       
       }
    
        return longestcount;
    }
        
    
};