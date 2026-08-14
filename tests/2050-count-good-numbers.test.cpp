#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../2050-count-good-numbers/2050-count-good-numbers.cpp"
#endif
#include SOLUTION_PATH

int main() {
    test::expectEq(Solution().countGoodNumbers(1), 5, "example 1");
    test::expectEq(Solution().countGoodNumbers(4), 400, "example 2");
    test::expectEq(Solution().countGoodNumbers(50), 564908303, "example 3");

    for (long long n : {2LL, 3LL, 7LL, 100LL, 12345LL, 1000000000LL}) {
        test::emit("countGoodNumbers", Solution().countGoodNumbers(n));
    }

    return test::report();
}
