#include "../common/graph.hpp"

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        lc::WeightedAdjacencyList g = lc::buildWeightedDirectedGraph(
            n, edges, [&](int u, int v, int) { return online[u] && online[v]; });

        int min_w = 2e9, max_w = -1;

        for (const auto& adj : g) {
            for (const auto& edge : adj) {
                min_w = min(min_w, edge.second);
                max_w = max(max_w, edge.second);
            }
        }
        
        if (max_w == -1) return -1;
        
        auto check = [&](int mid) {
            vector<long long> dist(n, 2e18); 
            dist[0] = 0;
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            pq.push({0, 0});
            
            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                
                if (d > k) return false;
                if (u == n - 1) return true;
                if (d > dist[u]) continue;
                
                for (auto& edge : g[u]) {
                    int v = edge.first;
                    int w = edge.second;
                    
                    if (w < mid) continue; 
                    
                    long long new_dist = d + w;
                    if (new_dist < dist[v]) {
                        dist[v] = new_dist;
                        pq.push({new_dist, v});
                    }
                }
            }
            return false;
        };
        
        int l = min_w, r = max_w;
        int ans = -1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};