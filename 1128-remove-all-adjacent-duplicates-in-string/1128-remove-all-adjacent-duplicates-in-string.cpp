class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        stack<char>st;
        for(char p:s)
        {
            if(st.empty())
            st.push(p);
            else

           { if(!st.empty()&&st.top()!=p)
            {
                st.push(p);
            }
            else
            st.pop();}
        }
        while(!st.empty())
        {

            ans+=st.top();
            st.pop();
        }
       reverse(ans.begin(),ans.end());
          return ans;
    }
};