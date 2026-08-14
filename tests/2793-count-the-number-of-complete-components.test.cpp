#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../2793-count-the-number-of-complete-components/2793-count-the-number-of-complete-components.cpp"
#endif
#include SOLUTION_PATH

int main() {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    test::expectEq(Solution().countCompleteComponents(6, edges), 3, "example 1");

    vector<vector<int>> incomplete = {{0, 1}, {1, 2}};
    test::expectEq(Solution().countCompleteComponents(3, incomplete), 0, "path is not complete");

    for (int trial = 0; trial < 20; trial++) {
        int n = test::randomInt(1, 8);
        set<pair<int, int>> unique;

        for (int i = 0; i < test::randomInt(0, n * 2); i++) {
            int u = test::randomInt(0, n - 1);
            int v = test::randomInt(0, n - 1);

            if (u != v) {
                unique.insert({min(u, v), max(u, v)});
            }
        }

        vector<vector<int>> random;
        for (const auto& edge : unique) {
            random.push_back({edge.first, edge.second});
        }

        test::emit("countCompleteComponents", Solution().countCompleteComponents(n, random));
    }

    return test::report();
}
