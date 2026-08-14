#include "test_util.hpp"

#include "../common/graph.hpp"
#include "../common/grid.hpp"
#include "../common/numeric.hpp"
#include "../common/strings.hpp"

int main() {
    test::expectEq(lc::gcdOf(12, 18), 6LL, "gcdOf");
    test::expectEq(lc::gcdOf(7, 0), 7LL, "gcdOf with zero");
    test::expectEq(lc::powMod(2, 10), 1024LL, "powMod");
    test::expectEq(lc::powMod(5, 0), 1LL, "powMod zero exponent");
    test::expectEq(lc::powMod(10, 20), 4900LL, "powMod wraps modulo 1e9+7");

    test::expectEq(lc::inBounds(0, 0, 1, 1), true, "inBounds inside");
    test::expectEq(lc::inBounds(1, 0, 1, 1), false, "inBounds outside");

    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
    test::expectEq(lc::rowCount(grid), 2, "rowCount");
    test::expectEq(lc::colCount(grid), 3, "colCount");

    vector<int> visited;
    lc::forEachNeighbor4(0, 0, 2, 3, [&](int row, int col) { visited.push_back(grid[row][col]); });
    vector<int> expectedNeighbors = {4, 2};
    test::expectEq(visited, expectedNeighbors, "forEachNeighbor4 skips out-of-bounds cells");

    vector<vector<int>> edges = {{0, 1}, {1, 2}};
    lc::AdjacencyList adj = lc::buildUndirectedGraph(3, edges);
    vector<int> neighborsOfOne = {0, 2};
    test::expectEq(adj[1], neighborsOfOne, "buildUndirectedGraph");

    vector<vector<int>> weighted = {{0, 1, 7}};
    lc::WeightedAdjacencyList weightedAdj = lc::buildWeightedUndirectedGraph(2, weighted);
    test::expectEq(weightedAdj[1][0].second, 7, "buildWeightedUndirectedGraph keeps weights");

    lc::WeightedAdjacencyList directed =
        lc::buildWeightedDirectedGraph(2, weighted, [](int, int, int weight) { return weight > 9; });
    test::expectEq(directed[0].empty(), true, "buildWeightedDirectedGraph filters edges");

    vector<int> freq = lc::lowercaseFrequency("aab");
    test::expectEq(freq[0], 2, "lowercaseFrequency");
    test::expectEq(freq[1], 1, "lowercaseFrequency");

    test::expectEq(lc::stringFromCounts(freq), string("aab"), "stringFromCounts");

    auto [half, middle] = lc::palindromeHalfCounts(lc::lowercaseFrequency("aabbc"));
    test::expectEq(lc::stringFromCounts(half), string("ab"), "palindromeHalfCounts halves");
    test::expectEq(middle, string("c"), "palindromeHalfCounts middle");
    test::expectEq(lc::mirrorPalindrome("ab", "c"), string("abcba"), "mirrorPalindrome");
    test::expectEq(lc::mirrorPalindrome("ab", ""), string("abba"), "mirrorPalindrome without middle");

    return test::report();
}
