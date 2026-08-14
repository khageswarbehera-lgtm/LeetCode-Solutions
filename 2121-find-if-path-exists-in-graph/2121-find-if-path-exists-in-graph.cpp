#include "../common/graph.hpp"

class Solution {
public:

    void dfs(int node, const lc::AdjacencyList &adj, vector<int> &vis)
    {
        vis[node] = 1;

        for(auto it : adj[node])
        {
            if(!vis[it])
                dfs(it, adj, vis);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        lc::AdjacencyList adj = lc::buildUndirectedGraph(n, edges);

        vector<int> vis(n,0);

        dfs(source, adj, vis);

        return vis[destination];
    }
};