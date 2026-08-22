class Solution {
public:
    bool checkDivisibility(int n) {
        int x=n;
        int sum=0;
        int product=1;
        while(x>0)
        {
         int ld=x%10;
            sum+=ld;
            product*=ld;
            x/=10;
        }
        if(n%(sum+product)==0)
        return true;
        return false;
        
    }
};