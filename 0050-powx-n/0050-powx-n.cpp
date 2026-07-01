class Solution {
public:

    double power(double x, long long n) {

        if (n == 0)
            return 1;

        double half = power(x, n / 2);

        if (n % 2 == 0)
            return half * half;

        return x * half * half;
    }

    double myPow(double x, int n) {

        long long powerValue = n;

        if (powerValue < 0) {
            x = 1 / x;
            powerValue = -powerValue;
        }

        return power(x, powerValue);
    }
};