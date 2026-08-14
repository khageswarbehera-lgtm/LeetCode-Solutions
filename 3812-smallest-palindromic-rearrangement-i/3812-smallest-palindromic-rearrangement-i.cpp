#include "../common/strings.hpp"

class Solution {
public:
    string smallestPalindrome(string s) {
        auto [half, mid] = lc::palindromeHalfCounts(lc::lowercaseFrequency(s));

        return lc::mirrorPalindrome(lc::stringFromCounts(half), mid);
    }
};
