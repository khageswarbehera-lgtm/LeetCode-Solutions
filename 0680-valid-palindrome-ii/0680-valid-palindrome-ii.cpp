class Solution {
public:
bool ispalindrome(int left,int right,string s)
        {
            while(left<right)
            {
                if (s[left] == s[right])
                {
                     left++;
                    right--;
                }
                else
               return false;
            }
                return true;

        }
    bool validPalindrome(string s) {
        if(s.length()<=1)
        return true;
        int left=0;
        int right=s.length()-1;
        
         while(left<right)
            {
                if (s[left] == s[right])
                {
                     left++;
                    right--;
                }
                else
                {
                     return ispalindrome(left+1, right,s) || ispalindrome(left, right-1,s);
                }
            }
            return true;


        
        
    }
};