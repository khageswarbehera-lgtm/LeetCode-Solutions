#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../2106-find-greatest-common-divisor-of-array/2106-find-greatest-common-divisor-of-array.cpp"
#endif
#include SOLUTION_PATH

int main() {
    vector<int> example1 = {2, 5, 6, 9, 10};
    test::expectEq(Solution().findGCD(example1), 2, "example 1");

    vector<int> example2 = {7, 5, 6, 8, 3};
    test::expectEq(Solution().findGCD(example2), 1, "example 2");

    vector<int> example3 = {3, 3};
    test::expectEq(Solution().findGCD(example3), 3, "example 3");

    for (int trial = 0; trial < 20; trial++) {
        vector<int> nums;
        for (int i = 0; i < test::randomInt(2, 8); i++) {
            nums.push_back(test::randomInt(1, 1000));
        }

        test::emit("findGCD", Solution().findGCD(nums));
    }

    return test::report();
}
