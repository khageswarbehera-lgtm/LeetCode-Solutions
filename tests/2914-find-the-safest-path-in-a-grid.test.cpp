#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../2914-find-the-safest-path-in-a-grid/2914-find-the-safest-path-in-a-grid.cpp"
#endif
#include SOLUTION_PATH

int main() {
    vector<vector<int>> thiefAtStart = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    test::expectEq(Solution().maximumSafenessFactor(thiefAtStart), 0, "thief on start cell");

    vector<vector<int>> corner = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
    test::expectEq(Solution().maximumSafenessFactor(corner), 2, "single thief in corner");

    for (int trial = 0; trial < 20; trial++) {
        int n = test::randomInt(2, 6);
        vector<vector<int>> grid = test::randomGrid(n, n, 0, 0);

        // Ensure at least one thief so the multi-source BFS has a source.
        grid[test::randomInt(0, n - 1)][test::randomInt(0, n - 1)] = 1;

        test::emit("maximumSafenessFactor", Solution().maximumSafenessFactor(grid));
    }

    return test::report();
}
