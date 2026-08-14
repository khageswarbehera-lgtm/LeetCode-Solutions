#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../1297-maximum-number-of-balloons/1297-maximum-number-of-balloons.cpp"
#endif
#include SOLUTION_PATH

int main() {
    test::expectEq(Solution().maxNumberOfBalloons("nlaebolko"), 1, "example 1");
    test::expectEq(Solution().maxNumberOfBalloons("loonbalxballpoon"), 2, "example 2");
    test::expectEq(Solution().maxNumberOfBalloons("leetcode"), 0, "example 3");

    for (int trial = 0; trial < 20; trial++) {
        test::emit("maxNumberOfBalloons",
                   Solution().maxNumberOfBalloons(test::randomLowercase(test::randomInt(1, 30))));
    }

    return test::report();
}
