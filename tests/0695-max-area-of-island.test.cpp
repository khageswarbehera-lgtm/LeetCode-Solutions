#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../0695-max-area-of-island/0695-max-area-of-island.cpp"
#endif
#include SOLUTION_PATH

int main() {
    vector<vector<int>> grid = {{1, 1, 0}, {0, 1, 0}, {0, 0, 1}};
    test::expectEq(Solution().maxAreaOfIsland(grid), 3, "connected island");

    vector<vector<int>> empty = {{0, 0}, {0, 0}};
    test::expectEq(Solution().maxAreaOfIsland(empty), 0, "no island");

    for (int trial = 0; trial < 20; trial++) {
        vector<vector<int>> random =
            test::randomGrid(test::randomInt(1, 6), test::randomInt(1, 6), 0, 1);

        test::emit("maxAreaOfIsland", Solution().maxAreaOfIsland(random));
    }

    return test::report();
}
