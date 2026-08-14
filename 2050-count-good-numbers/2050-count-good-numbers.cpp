#include "../common/numeric.hpp"

class Solution {
public:

    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;

        long long odd = n / 2;

        return (lc::powMod(5, even) * lc::powMod(4, odd)) % lc::kMod;
    }
};