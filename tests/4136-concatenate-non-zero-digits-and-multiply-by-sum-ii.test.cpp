#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../4136-concatenate-non-zero-digits-and-multiply-by-sum-ii/4136-concatenate-non-zero-digits-and-multiply-by-sum-ii.cpp"
#endif
#include SOLUTION_PATH

int main() {
    vector<vector<int>> queries = {{0, 2}, {1, 3}};
    // "123" -> 123 * 6, "230" -> 23 * 5
    vector<int> expected = {738, 115};
    test::expectEq(Solution().sumAndMultiply("1230", queries), expected, "small queries");

    for (int trial = 0; trial < 10; trial++) {
        string s;
        for (int i = 0; i < test::randomInt(1, 8); i++) {
            s.push_back(static_cast<char>('0' + test::randomInt(0, 9)));
        }

        vector<vector<int>> random;
        for (int i = 0; i < 3; i++) {
            int l = test::randomInt(0, static_cast<int>(s.size()) - 1);
            int r = test::randomInt(l, static_cast<int>(s.size()) - 1);
            random.push_back({l, r});
        }

        test::emit("sumAndMultiply", Solution().sumAndMultiply(s, random));
    }

    return test::report();
}
