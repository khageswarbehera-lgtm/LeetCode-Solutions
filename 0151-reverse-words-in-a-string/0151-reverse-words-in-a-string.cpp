class Solution {
public:
    string reverseWords(string s) {
        vector<string>st;
        string word;
        string ans;

        for(char x:s)
        {
            if(x!=' ')
            word+=x;
            else
            {
                if(!word.empty())
                {
                    st.push_back(word);
                    word.clear();
                }
            }
        }
        if(!word.empty())
        st.push_back(word);
        reverse(st.begin(),st.end());
        for(int i=0;i<st.size();i++)
        {
            if(i>0)
            ans+=' ';
            ans+=st[i];
        }
        return ans;
        
    }
};