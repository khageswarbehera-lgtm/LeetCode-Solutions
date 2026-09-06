class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n1=name.length();
        int n2=typed.length();
        int left=0;
        int right=0;
        while(left<n1 && right<n2)
        {
            if(name[left]== typed[right])
            {
                left++;
                right++;
            }
            else
            {
                if(right>0 && typed[right]==typed[right-1])
                {
                    right++;
                }
                else
                 return false;
            }
        }
        if(left<n1)
        return false;
        while(right<n2)
        {
            if(typed[right]!=typed[right-1])
            return false;
            right++;
        }

            return true;

        
    }
};