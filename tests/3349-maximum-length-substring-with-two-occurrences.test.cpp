#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../3349-maximum-length-substring-with-two-occurrences/3349-maximum-length-substring-with-two-occurrences.cpp"
#endif
#include SOLUTION_PATH

int main() {
    test::expectEq(Solution().maximumLengthSubstring("bcbbbcba"), 4, "example 1");
    test::expectEq(Solution().maximumLengthSubstring("aaaa"), 2, "example 2");

    for (int trial = 0; trial < 20; trial++) {
        test::emit("maximumLengthSubstring",
                   Solution().maximumLengthSubstring(
                       test::randomLowercase(test::randomInt(1, 30), 4)));
    }

    return test::report();
}
