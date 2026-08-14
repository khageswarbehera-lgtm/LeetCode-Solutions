#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../2582-minimum-score-of-a-path-between-two-cities/2582-minimum-score-of-a-path-between-two-cities.cpp"
#endif
#include SOLUTION_PATH

int main() {
    vector<vector<int>> roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
    test::expectEq(Solution().minScore(4, roads), 5, "example 1");

    vector<vector<int>> chain = {{1, 2, 2}, {2, 3, 4}, {3, 4, 7}};
    test::expectEq(Solution().minScore(4, chain), 2, "example 2");

    for (int trial = 0; trial < 20; trial++) {
        int n = test::randomInt(2, 8);
        vector<vector<int>> random;

        // Keep the graph connected: chain every city, then add extra roads.
        for (int city = 2; city <= n; city++) {
            random.push_back({test::randomInt(1, city - 1), city, test::randomInt(1, 100)});
        }

        for (int i = 0; i < test::randomInt(0, n); i++) {
            random.push_back(
                {test::randomInt(1, n), test::randomInt(1, n), test::randomInt(1, 100)});
        }

        test::emit("minScore", Solution().minScore(n, random));
    }

    return test::report();
}
