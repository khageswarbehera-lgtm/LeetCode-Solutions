#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../2121-find-if-path-exists-in-graph/2121-find-if-path-exists-in-graph.cpp"
#endif
#include SOLUTION_PATH

int main() {
    vector<vector<int>> triangle = {{0, 1}, {1, 2}, {2, 0}};
    test::expectEq(Solution().validPath(3, triangle, 0, 2), true, "example 1");

    vector<vector<int>> split = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    test::expectEq(Solution().validPath(6, split, 0, 5), false, "example 2");

    for (int trial = 0; trial < 20; trial++) {
        int n = test::randomInt(2, 8);
        vector<vector<int>> edges;

        for (int i = 0; i < test::randomInt(0, n); i++) {
            edges.push_back({test::randomInt(0, n - 1), test::randomInt(0, n - 1)});
        }

        test::emit("validPath",
                   Solution().validPath(n, edges, test::randomInt(0, n - 1),
                                        test::randomInt(0, n - 1)));
    }

    return test::report();
}
