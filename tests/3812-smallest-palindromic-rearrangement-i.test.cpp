#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../3812-smallest-palindromic-rearrangement-i/3812-smallest-palindromic-rearrangement-i.cpp"
#endif
#include SOLUTION_PATH

int main() {
    test::expectEq(Solution().smallestPalindrome("z"), string("z"), "single character");
    test::expectEq(Solution().smallestPalindrome("babab"), string("abbba"), "odd length");
    test::expectEq(Solution().smallestPalindrome("daccad"), string("acddca"), "even length");

    for (int trial = 0; trial < 20; trial++) {
        // Build a palindromic input from random halves.
        string half = test::randomLowercase(test::randomInt(1, 6), 5);
        string mirrored = half;
        reverse(mirrored.begin(), mirrored.end());

        string s = half + (test::randomInt(0, 1) ? string("k") : string("")) + mirrored;

        test::emit("smallestPalindrome", Solution().smallestPalindrome(s));
    }

    return test::report();
}
