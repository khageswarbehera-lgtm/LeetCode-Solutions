#include "../common/graph.hpp"

class Solution {
public:
    int ans = INT_MAX;

    void dfs(int node, const lc::WeightedAdjacencyList& adj, vector<int>& vis) {

        vis[node] = 1;

        for (auto &it : adj[node]) {

            int neigh = it.first;
            int wt = it.second;

            ans = min(ans, wt);

            if (!vis[neigh])
                dfs(neigh, adj, vis);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {

        lc::WeightedAdjacencyList adj = lc::buildWeightedUndirectedGraph(n + 1, roads);

        vector<int> vis(n + 1, 0);

        dfs(1, adj, vis);

        return ans;
    }
};