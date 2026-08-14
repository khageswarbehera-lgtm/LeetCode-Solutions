#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../3276-minimum-number-of-pushes-to-type-word-ii/3276-minimum-number-of-pushes-to-type-word-ii.cpp"
#endif
#include SOLUTION_PATH

int main() {
    test::expectEq(Solution().minimumPushes("abcde"), 5, "example 1");
    test::expectEq(Solution().minimumPushes("xycdefghij"), 12, "example 2");

    for (int trial = 0; trial < 20; trial++) {
        test::emit("minimumPushes",
                   Solution().minimumPushes(test::randomLowercase(test::randomInt(1, 40))));
    }

    return test::report();
}
