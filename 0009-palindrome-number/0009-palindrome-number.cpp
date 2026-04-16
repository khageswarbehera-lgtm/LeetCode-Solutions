class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return false;
        int num=x;
        int ld=0;
        long long rev=0;
        while(num!=0)
        {
            ld=num%10;
            num=num/10;
            rev=rev*10+ld;
            if(rev>x)
            return false;
        }
        if(rev==x)
        return true;
        return false;
        
    }
};