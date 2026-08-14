#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../0130-surrounded-regions/0130-surrounded-regions.cpp"
#endif
#include SOLUTION_PATH

int main() {
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                 {'X', 'O', 'O', 'X'},
                                 {'X', 'X', 'O', 'X'},
                                 {'X', 'O', 'X', 'X'}};

    Solution().solve(board);

    vector<vector<char>> expected = {{'X', 'X', 'X', 'X'},
                                    {'X', 'X', 'X', 'X'},
                                    {'X', 'X', 'X', 'X'},
                                    {'X', 'O', 'X', 'X'}};

    test::expectEq(board, expected, "example 1");

    for (int trial = 0; trial < 20; trial++) {
        int rows = test::randomInt(1, 6);
        int cols = test::randomInt(1, 6);

        vector<vector<int>> cells = test::randomGrid(rows, cols, 0, 1);
        vector<vector<char>> random(rows, vector<char>(cols));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                random[i][j] = cells[i][j] ? 'O' : 'X';
            }
        }

        Solution().solve(random);

        for (const auto& row : random) {
            test::emit("row", row);
        }
    }

    return test::report();
}
