class Solution {
public:
    string reverseVowels(string s) {
        int left=0;
        int right=s.length()-1;
        while(left<right)
        {
            char x=tolower(s[left]);
            char y= tolower(s[right]);
            if((x=='a'||x=='e'||x=='i'||x=='o'||x=='u')
            &&(y=='a'||y=='e'||y=='i'||y=='o'||y=='u') )
            {
                swap(s[left],s[right]);
                left++;
                right--;
            }
            else
            {
                if(x!='a'&& x!='e'&& x!='i'&&x!='o'&& x!='u')
                {
                    left++;
                }
               else if(y!='a'&& y!='e'&& y!='i'&& y!='o'&& y!='u')
                {
                    right--;
                }
                else {
                    left++;
                    right--;
                }
            }
        }
        return s;
        
    }
};