#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../3813-smallest-palindromic-rearrangement-ii/3813-smallest-palindromic-rearrangement-ii.cpp"
#endif
#include SOLUTION_PATH

int main() {
    test::expectEq(Solution().smallestPalindrome("abba", 1), string("abba"), "first arrangement");
    test::expectEq(Solution().smallestPalindrome("abba", 2), string("baab"), "second arrangement");
    test::expectEq(Solution().smallestPalindrome("abba", 3), string(""), "k out of range");

    for (int trial = 0; trial < 20; trial++) {
        string half = test::randomLowercase(test::randomInt(1, 5), 4);
        string mirrored = half;
        reverse(mirrored.begin(), mirrored.end());

        string s = half + (test::randomInt(0, 1) ? string("k") : string("")) + mirrored;

        test::emit("smallestPalindrome", Solution().smallestPalindrome(s, test::randomInt(1, 6)));
    }

    return test::report();
}
