class Solution {
public:
    double pow(double x,long long n)
    {
        if(n==0)
        return 1;
        if(n==1)
        return x;
        if(n%2==0)
        return pow(x*x,n/2);
        return x*pow(x,n-1);
    }
    double myPow(double x, int n) {
        long long num=n;
         if(num<0)
            return pow(1.0/x,-1*num);

         return pow(x,num);
    }
       
};