#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../3608-find-the-number-of-subsequences-with-equal-gcd/3608-find-the-number-of-subsequences-with-equal-gcd.cpp"
#endif
#include SOLUTION_PATH

int main() {
    vector<int> ones = {1, 1};
    test::expectEq(Solution().subsequencePairCount(ones), 2, "two equal elements, either order");

    for (int trial = 0; trial < 10; trial++) {
        vector<int> nums;
        for (int i = 0; i < test::randomInt(2, 6); i++) {
            nums.push_back(test::randomInt(1, 12));
        }

        test::emit("subsequencePairCount", Solution().subsequencePairCount(nums));
    }

    return test::report();
}
