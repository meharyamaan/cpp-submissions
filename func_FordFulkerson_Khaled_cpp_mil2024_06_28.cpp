//
//  khaled_cpp_mil_241_2024_June_28:

//  func_FordFulkerson_khaled_cpp_mil_241_2024_June_28

//
//
// Problem Description:
// You are tasked with optimizing the traffic flow in a city by maximizing the capacity of transportation networks represented as a graph.
// Nodes represent intersections, and edges represent roads with capacities indicating the maximum number of vehicles that can pass through.
// Determine the maximum flow of traffic from a starting point (e.g., a central business district) to a destination point (e.g., residential areas).

// Function name: FordFulkerson
// Parameters:
//   graph: Adjacency matrix representing the capacity of edges between nodes.
//   source: Integer representing the index of the source node (starting point).
//   sink: Integer representing the index of the sink node (destination point).
// Return Type: Integer - Maximum flow from the source to the sink.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

bool bfs(std::vector<std::vector<int>>& residual_capacity, int source, int sink, std::vector<int>& parent) {
    int n = residual_capacity.size();
    std::vector<bool> visited(n, false);
    std::queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && residual_capacity[u][v] > 0) {
                if (v == sink) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int FordFulkerson(std::vector<std::vector<int>>& graph, int source, int sink) {
    int n = graph.size();
    std::vector<std::vector<int>> residual_capacity(graph);

    std::vector<int> parent(n, -1);
    int max_flow = 0;

    while (bfs(residual_capacity, source, sink, parent)) {
        int path_flow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            path_flow = std::min(path_flow, residual_capacity[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residual_capacity[u][v] -= path_flow;
            residual_capacity[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}
#include <cassert>
int main() {
    // TEST 
    std::vector<std::vector<int>> graph1 = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
    int source1 = 0, sink1 = 5;
    int expected_result1 = 23;
    int result1 = FordFulkerson(graph1, source1, sink1);
    assert(result1 == expected_result1);
    // TEST END
    
    
    // TEST 
    std::vector<std::vector<int>> graph3 = {
        {0, 5, 7, 0},
        {0, 0, 0, 10},
        {0, 0, 0, 6},
        {0, 0, 0, 0}
    };
    int source3 = 0, sink3 = 3;
    int expected_result3 = 11;
    int result3 = FordFulkerson(graph3, source3, sink3);
    assert(result3 == expected_result3);
    // TEST END

   }
