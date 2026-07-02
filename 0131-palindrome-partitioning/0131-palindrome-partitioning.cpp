class Solution {
public:
bool isPalindrom(string &s,int start, int end)
{
    while(start<end)
    {
        if(s[start]!=s[end])
        return false;
        start++;
        end--;
    }
        return true;

}
vector<vector<string>> ans;
void solve(int index, string &s,vector<string> &path)
{
    if(index==s.size())
    {
        ans.push_back(path);
        return;
    }
    for(int i=index;i<s.size();i++)
    {
        if(isPalindrom(s,index,i))
        {
            path.push_back(s.substr(index,i-index+1));
            solve(i+1,s,path);
            path.pop_back();
        }

    }
}
    vector<vector<string>> partition(string s) {
        vector<string>path;
        solve(0,s,path);
        return ans;
        
    }
};