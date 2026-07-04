class Solution {
public:

    void dfs(int node, vector<int> adj[], vector<int> &vis)
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
        vector<int> adj[n];

        for(auto &it : edges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);

        dfs(source, adj, vis);

        return vis[destination];
    }
};