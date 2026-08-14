#pragma once

#include "leetcode.hpp"

namespace lc {

using AdjacencyList = vector<vector<int>>;
using WeightedAdjacencyList = vector<vector<pair<int, int>>>;

// Adjacency list of an undirected graph over vertices [0, vertexCount).
// Each edge is {u, v}.
inline AdjacencyList buildUndirectedGraph(int vertexCount, const vector<vector<int>>& edges) {
    AdjacencyList adj(vertexCount);

    for (const auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    return adj;
}

// Same as above for edges of the form {u, v, weight}; neighbours are
// stored as {vertex, weight}.
inline WeightedAdjacencyList buildWeightedUndirectedGraph(int vertexCount,
                                                          const vector<vector<int>>& edges) {
    WeightedAdjacencyList adj(vertexCount);

    for (const auto& edge : edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }

    return adj;
}

// Directed variant of buildWeightedUndirectedGraph. `keepEdge(u, v, weight)`
// selects which edges make it into the graph.
template <typename KeepEdge>
WeightedAdjacencyList buildWeightedDirectedGraph(int vertexCount,
                                                 const vector<vector<int>>& edges,
                                                 KeepEdge keepEdge) {
    WeightedAdjacencyList adj(vertexCount);

    for (const auto& edge : edges) {
        if (keepEdge(edge[0], edge[1], edge[2])) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
    }

    return adj;
}

}  // namespace lc
