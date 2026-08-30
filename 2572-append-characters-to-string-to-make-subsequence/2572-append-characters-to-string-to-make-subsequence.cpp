class Solution {
public:
    int appendCharacters(string s, string t) {
        int l1=t.size();
        int l2=s.size();
        int left=0;
        int right=0;
        while(left<l1 && right<l2)
        {
            if(t[left] == s[right])
            {
                left++;
                right++;
            }
            else
            right++;
        }
        return l1-left;
        
    }
};