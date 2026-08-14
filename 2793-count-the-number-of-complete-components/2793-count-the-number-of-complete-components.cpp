#include "../common/graph.hpp"

class Solution {
public:
    void dfs(int node, const lc::AdjacencyList& adj, vector<bool>& vis,
             int& nodes, int& degreeSum) {

        vis[node] = true;
        nodes++;
        degreeSum += adj[node].size();

        for (int nei : adj[node]) {
            if (!vis[nei])
                dfs(nei, adj, vis, nodes, degreeSum);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        lc::AdjacencyList adj = lc::buildUndirectedGraph(n, edges);

        vector<bool> vis(n, false);

        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                int nodes = 0;
                int degreeSum = 0;

                dfs(i, adj, vis, nodes, degreeSum);

                int edgeCount = degreeSum / 2;

                if (edgeCount == nodes * (nodes - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};