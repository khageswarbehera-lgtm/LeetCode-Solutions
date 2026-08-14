#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../3558-find-a-safe-walk-through-a-grid/3558-find-a-safe-walk-through-a-grid.cpp"
#endif
#include SOLUTION_PATH

int main() {
    vector<vector<int>> grid = {{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}};
    test::expectEq(Solution().findSafeWalk(grid, 1), true, "safe path with health 1");

    vector<vector<int>> blocked = {{1, 1}, {1, 1}};
    test::expectEq(Solution().findSafeWalk(blocked, 1), false, "start cell drains health");

    for (int trial = 0; trial < 20; trial++) {
        vector<vector<int>> random =
            test::randomGrid(test::randomInt(1, 5), test::randomInt(1, 5), 0, 1);

        test::emit("findSafeWalk", Solution().findSafeWalk(random, test::randomInt(1, 4)));
    }

    return test::report();
}
