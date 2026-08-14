#include "test_util.hpp"

#ifndef SOLUTION_PATH
#define SOLUTION_PATH "../3919-network-recovery-pathways/3919-network-recovery-pathways.cpp"
#endif
#include SOLUTION_PATH

int main() {
    vector<vector<int>> edges = {{0, 1, 5}, {1, 3, 10}, {0, 2, 3}, {2, 3, 4}};
    vector<bool> online = {true, true, true, true};
    test::expectEq(Solution().findMaxPathScore(edges, online, 10), 3, "cheapest path wins");

    vector<bool> offline = {true, false, false, true};
    test::expectEq(Solution().findMaxPathScore(edges, offline, 100), -1, "no usable edge");

    for (int trial = 0; trial < 20; trial++) {
        int n = test::randomInt(2, 7);
        vector<bool> random(n, true);

        for (int i = 1; i + 1 < n; i++) {
            random[i] = test::randomInt(0, 1) == 1;
        }

        vector<vector<int>> randomEdges;
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (test::randomInt(0, 1)) {
                    randomEdges.push_back({u, v, test::randomInt(1, 20)});
                }
            }
        }

        test::emit("findMaxPathScore",
                   Solution().findMaxPathScore(randomEdges, random, test::randomInt(1, 60)));
    }

    return test::report();
}
