class Solution {
public:
vector<string> ans;
void solve(int index, string &num, long long target, string path, long long value, long long prev)
{
    if(index==num.size())
    {
        if(value==target)
        ans.push_back(path);
        return;
    }
    long long curr=0;
    for(int i =index;i<num.size();i++)
    {
        if(i>index && num[index]=='0')
        break;
        curr=curr*10+(num[i]-'0');
        string currstr=num.substr(index,i-index+1);
        if(index==0)
        solve(i+1, num, target, currstr, curr, curr);
        else
        {
            solve(i+1, num,target, path+"+"+currstr,value+curr, curr);
            solve(i+1, num,target, path+"-"+currstr,value-curr, -curr);
            solve(i+1, num,target, path+"*"+currstr,value-prev+prev*curr, prev*curr);
        }
    }
}

    vector<string> addOperators(string num, int target) {
        solve(0, num, target, "", 0, 0);
        return ans;
        
    }
};