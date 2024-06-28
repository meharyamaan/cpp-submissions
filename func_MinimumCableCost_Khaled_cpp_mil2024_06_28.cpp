/*

khaled_cpp_mil_241_2024_June_28:

func_MinimumCableCost_khaled_cpp_mil_241_2024_June_28


Problem Description:
You are a network engineer tasked with designing a cost-efficient network for a new office building. 
The building has multiple rooms, and you need to connect all rooms with network cables. Each pair of rooms has a potential cable
installation cost. Your goal is to connect all the rooms with the minimum total cable cost, ensuring there is a path between any 
two rooms.

Functions:
   - Function name: MinimumCableCost
   - Parameters: int num_rooms - number of rooms in the building.
                 const std::vector<std::tuple<int, int, int>>& cable_costs - vector of tuples containing costs to connect each pair of rooms (from, to, cost).
   - Return Type: int - the minimum total cable cost to connect all rooms.

*/

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cassert>
#include <stdexcept>

int find(std::vector<int>& parent, int node) {
    if (parent[node] != node) {
        parent[node] = find(parent, parent[node]);
    }
    return parent[node];
}

void unite(std::vector<int>& parent, std::vector<int>& rank, int node1, int node2) {
    int root1 = find(parent, node1);
    int root2 = find(parent, node2);

    if (root1 != root2) {
        if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        } else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
}

int MinimumCableCost(int num_rooms, const std::vector<std::tuple<int, int, int>>& cable_costs) {
    std::vector<int> parent(num_rooms);
    std::vector<int> rank(num_rooms, 0);

    for (int iii = 0; iii < num_rooms; ++iii) {
        parent[iii] = iii;
    }

    std::vector<std::tuple<int, int, int>> sorted_costs = cable_costs;
    std::sort(sorted_costs.begin(), sorted_costs.end(), [](const std::tuple<int, int, int>& a, const std::tuple<int, int, int>& b) {
        return std::get<2>(a) < std::get<2>(b);
    });

    int total_cost = 0;
    int edges_added = 0;

    for (int iii = 0; iii < sorted_costs.size(); ++iii) {
        int room1 = std::get<0>(sorted_costs[iii]);
        int room2 = std::get<1>(sorted_costs[iii]);
        int cost_value = std::get<2>(sorted_costs[iii]);

        if (find(parent, room1) != find(parent, room2)) {
            unite(parent, rank, room1, room2);
            total_cost += cost_value;
            edges_added++;
            if (edges_added == num_rooms - 1) {
                break; 
            }
        }
    }

    if (edges_added != num_rooms - 1) {
        throw std::invalid_argument("Not enough edges to connect all rooms");
    }

    return total_cost;
}

#include <cassert>

int main() {
    // TEST
    int num_rooms_1 = 4;
    std::vector<std::tuple<int, int, int>> cable_costs_1 = {{0, 1, 1}, {1, 2, 2}, {2, 3, 3}, {0, 3, 4}, {1, 3, 5}};
    assert(MinimumCableCost(num_rooms_1, cable_costs_1) == 6);
    // TEST_END

    // TEST
    int num_rooms_2 = 5;
    std::vector<std::tuple<int, int, int>> cable_costs_2 = {{0, 1, 1}, {1, 2, 2}, {2, 3, 3}, {3, 4, 4}};
    assert(MinimumCableCost(num_rooms_2, cable_costs_2) == 10);
    // TEST_END

    // TEST
    int num_rooms_3 = 3;
    std::vector<std::tuple<int, int, int>> cable_costs_3 = {{0, 1, 2}, {1, 2, 1}, {0, 2, 3}};
    assert(MinimumCableCost(num_rooms_3, cable_costs_3) == 3);
    // TEST_END

}