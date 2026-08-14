#pragma once

#include "leetcode.hpp"

namespace lc {

// Row/column deltas for the four orthogonal neighbours of a cell.
inline constexpr int kDeltaRow4[4] = {-1, 1, 0, 0};
inline constexpr int kDeltaCol4[4] = {0, 0, -1, 1};

inline bool inBounds(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

template <typename T>
int rowCount(const vector<vector<T>>& grid) {
    return static_cast<int>(grid.size());
}

template <typename T>
int colCount(const vector<vector<T>>& grid) {
    return grid.empty() ? 0 : static_cast<int>(grid[0].size());
}

// Calls visit(nextRow, nextCol) for every in-bounds orthogonal neighbour.
template <typename Visit>
void forEachNeighbor4(int row, int col, int rows, int cols, Visit visit) {
    for (int k = 0; k < 4; k++) {
        int nextRow = row + kDeltaRow4[k];
        int nextCol = col + kDeltaCol4[k];

        if (inBounds(nextRow, nextCol, rows, cols)) {
            visit(nextRow, nextCol);
        }
    }
}

}  // namespace lc
