#include "lc_test.h"

namespace lc0130 {
#include "../0130-surrounded-regions/0130-surrounded-regions.cpp"
}
namespace lc0547 {
#include "../0547-number-of-provinces/0547-number-of-provinces.cpp"
}
namespace lc0695 {
#include "../0695-max-area-of-island/0695-max-area-of-island.cpp"
}
namespace lc2121 {
#include "../2121-find-if-path-exists-in-graph/2121-find-if-path-exists-in-graph.cpp"
}
namespace lc2582 {
#include "../2582-minimum-score-of-a-path-between-two-cities/2582-minimum-score-of-a-path-between-two-cities.cpp"
}
namespace lc2793 {
#include "../2793-count-the-number-of-complete-components/2793-count-the-number-of-complete-components.cpp"
}
namespace lc2914 {
#include "../2914-find-the-safest-path-in-a-grid/2914-find-the-safest-path-in-a-grid.cpp"
}
namespace lc3558 {
#include "../3558-find-a-safe-walk-through-a-grid/3558-find-a-safe-walk-through-a-grid.cpp"
}
namespace lc3561 {
#include "../3561-remove-methods-from-project/3561-remove-methods-from-project.cpp"
}
namespace lc3852 {
#include "../3852-path-existence-queries-in-a-graph-ii/3852-path-existence-queries-in-a-graph-ii.cpp"
}
namespace lc3919 {
#include "../3919-network-recovery-pathways/3919-network-recovery-pathways.cpp"
}

using lctest::sorted;

TEST(SurroundedRegions, CapturesInteriorRegions) {
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    lc0130::Solution().solve(board);
    EXPECT_EQ(board, (vector<vector<char>>{{'X', 'X', 'X', 'X'},
                                           {'X', 'X', 'X', 'X'},
                                           {'X', 'X', 'X', 'X'},
                                           {'X', 'O', 'X', 'X'}}));
}

TEST(SurroundedRegions, SingleCellIsOnTheBorder) {
    vector<vector<char>> board = {{'O'}};
    lc0130::Solution().solve(board);
    EXPECT_EQ(board, (vector<vector<char>>{{'O'}}));
}

TEST(NumberOfProvinces, TwoProvinces) {
    vector<vector<int>> is_connected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    EXPECT_EQ(lc0547::Solution().findCircleNum(is_connected), 2);
}

TEST(NumberOfProvinces, EveryCityIsolated) {
    vector<vector<int>> is_connected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    EXPECT_EQ(lc0547::Solution().findCircleNum(is_connected), 3);
}

TEST(MaxAreaOfIsland, LargestConnectedRegion) {
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    EXPECT_EQ(lc0695::Solution().maxAreaOfIsland(grid), 6);
}

TEST(MaxAreaOfIsland, NoLand) {
    vector<vector<int>> grid = {{0, 0}, {0, 0}};
    EXPECT_EQ(lc0695::Solution().maxAreaOfIsland(grid), 0);
}

TEST(FindIfPathExistsInGraph, ConnectedNodes) {
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    EXPECT_TRUE(lc2121::Solution().validPath(3, edges, 0, 2));
}

TEST(FindIfPathExistsInGraph, DisconnectedComponents) {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    EXPECT_FALSE(lc2121::Solution().validPath(6, edges, 0, 5));
}

TEST(FindIfPathExistsInGraph, SourceEqualsDestination) {
    vector<vector<int>> edges = {};
    EXPECT_TRUE(lc2121::Solution().validPath(1, edges, 0, 0));
}

TEST(MinimumScoreOfAPath, UsesCheapestReachableRoad) {
    vector<vector<int>> roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
    EXPECT_EQ(lc2582::Solution().minScore(4, roads), 5);
}

TEST(MinimumScoreOfAPath, IgnoresUnreachableRoads) {
    vector<vector<int>> roads = {{1, 2, 2}, {1, 3, 4}, {3, 4, 7}};
    EXPECT_EQ(lc2582::Solution().minScore(4, roads), 2);
}

TEST(CountTheNumberOfCompleteComponents, MixedComponents) {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    EXPECT_EQ(lc2793::Solution().countCompleteComponents(6, edges), 3);
}

TEST(CountTheNumberOfCompleteComponents, IncompleteComponent) {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};
    EXPECT_EQ(lc2793::Solution().countCompleteComponents(6, edges), 1);
}

TEST(FindTheSafestPathInAGrid, ThievesBlockEveryPath) {
    vector<vector<int>> grid = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    EXPECT_EQ(lc2914::Solution().maximumSafenessFactor(grid), 0);
}

TEST(FindTheSafestPathInAGrid, MaximisesDistanceFromThieves) {
    vector<vector<int>> grid = {{0, 0, 1}, {0, 0, 0}, {0, 0, 0}};
    EXPECT_EQ(lc2914::Solution().maximumSafenessFactor(grid), 2);
}

TEST(FindTheSafestPathInAGrid, LargerGrid) {
    vector<vector<int>> grid = {
        {0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}};
    EXPECT_EQ(lc2914::Solution().maximumSafenessFactor(grid), 2);
}

TEST(FindASafeWalkThroughAGrid, JustEnoughHealth) {
    vector<vector<int>> grid = {{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}};
    EXPECT_TRUE(lc3558::Solution().findSafeWalk(grid, 1));
}

TEST(FindASafeWalkThroughAGrid, NotEnoughHealth) {
    vector<vector<int>> grid = {
        {0, 1, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 0}, {0, 1, 1, 1, 0, 1}, {0, 0, 1, 0, 1, 0}};
    EXPECT_FALSE(lc3558::Solution().findSafeWalk(grid, 3));
}

TEST(FindASafeWalkThroughAGrid, DetourAvoidsUnsafeCells) {
    vector<vector<int>> grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    EXPECT_TRUE(lc3558::Solution().findSafeWalk(grid, 5));
}

TEST(RemoveMethodsFromProject, ExternalInvocationBlocksRemoval) {
    vector<vector<int>> invocations = {{1, 2}, {0, 1}, {3, 2}};
    EXPECT_EQ(sorted(lc3561::Solution().remainingMethods(4, 1, invocations)),
              (vector<int>{0, 1, 2, 3}));
}

TEST(RemoveMethodsFromProject, RemovesSuspiciousGroup) {
    vector<vector<int>> invocations = {{1, 2}, {0, 2}, {0, 1}, {3, 4}};
    EXPECT_EQ(sorted(lc3561::Solution().remainingMethods(5, 0, invocations)), (vector<int>{3, 4}));
}

TEST(RemoveMethodsFromProject, WholeProjectIsSuspicious) {
    vector<vector<int>> invocations = {{1, 2}, {0, 1}, {2, 0}};
    EXPECT_TRUE(lc3561::Solution().remainingMethods(3, 2, invocations).empty());
}

TEST(PathExistenceQueriesInAGraphII, DirectNeighbours) {
    vector<int> nums = {1, 8, 3, 4, 2};
    vector<vector<int>> queries = {{0, 3}, {2, 4}};
    EXPECT_EQ(lc3852::Solution().pathExistenceQueries(5, nums, 3, queries), (vector<int>{1, 1}));
}

TEST(PathExistenceQueriesInAGraphII, UnreachablePairsReturnMinusOne) {
    vector<int> nums = {5, 3, 1, 9, 10};
    vector<vector<int>> queries = {{0, 1}, {0, 2}, {2, 3}, {4, 3}};
    EXPECT_EQ(lc3852::Solution().pathExistenceQueries(5, nums, 2, queries),
              (vector<int>{1, 2, -1, 1}));
}

TEST(PathExistenceQueriesInAGraphII, SameNodeHasZeroDistance) {
    vector<int> nums = {3, 6, 1};
    vector<vector<int>> queries = {{0, 0}, {0, 1}, {1, 2}};
    EXPECT_EQ(lc3852::Solution().pathExistenceQueries(3, nums, 1, queries),
              (vector<int>{0, -1, -1}));
}

TEST(NetworkRecoveryPathways, MaximisesBottleneckWithinBudget) {
    vector<vector<int>> edges = {{0, 1, 5}, {1, 3, 10}, {0, 2, 3}, {2, 3, 4}};
    vector<bool> online = {true, true, true, true};
    EXPECT_EQ(lc3919::Solution().findMaxPathScore(edges, online, 10), 3);
}

TEST(NetworkRecoveryPathways, SkipsOfflineNodes) {
    vector<vector<int>> edges = {{0, 1, 7}, {1, 4, 5}, {0, 2, 6}, {2, 3, 6}, {3, 4, 2}, {2, 4, 6}};
    vector<bool> online = {true, true, true, false, true};
    EXPECT_EQ(lc3919::Solution().findMaxPathScore(edges, online, 12), 6);
}
