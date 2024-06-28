/*

khaled_cpp_mil_241_2024_June_28:

func_ShortestPath_khaled_cpp_mil_241_2024_June_28



Problem Description:
You are developing a route planning system for a delivery service company. 
The city map is represented as an undirected graph where intersections are nodes and roads are edges with weights representing distances between intersections. 
Find the shortest path from the company's warehouse (starting point) to a customer's location (destination).

Functions:
   - Function name: ShortestPath
   - Parameters: int num_intersections - Total number of intersections (nodes) in the city map.
                 const std::vector<std::vector<int>>& city_map - Adjacency list representing the city map. Each element city_map[i] is a vector containing integers representing intersections directly connected to intersection i.
                 int warehouse - Starting point (warehouse) intersection index.
                 int customer_location - Destination (customer's location) intersection index.
   - Return Type: int - Minimum distance (shortest path length) from the warehouse to the customer's location. Return -1 if no path exists.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>
#include <cassert>

int ShortestPath(int num_intersections, const std::vector<std::vector<int>>& city_map, int warehouse, int customer_location) {
    if (warehouse < 0 || warehouse >= num_intersections || customer_location < 0 || customer_location >= num_intersections) {
        throw std::invalid_argument("Invalid warehouse or customer location index");
    }

    std::vector<int> distances(num_intersections, -1); 
    std::queue<int> queue;
    queue.push(warehouse);
    distances[warehouse] = 0;

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        for (int neighbor : city_map[current]) {
            if (distances[neighbor] == -1) { // Unvisited node
                distances[neighbor] = distances[current] + 1;
                queue.push(neighbor);

                if (neighbor == customer_location) {
                    return distances[neighbor];
                }
            }
        }
    }

    return -1; 
}

int main() {
    // TEST
    int num_intersections_1 = 6;
    std::vector<std::vector<int>> city_map_1 = {{1, 2}, {0, 2, 3}, {0, 1, 4}, {1, 5}, {2}, {3}};
    int warehouse_1 = 0;
    int customer_location_1 = 5;
    assert(ShortestPath(num_intersections_1, city_map_1, warehouse_1, customer_location_1) == 3);
    // TEST_END

    // TEST
    int num_intersections_2 = 5;
    std::vector<std::vector<int>> city_map_2 = {{1, 2}, {0, 3}, {0, 3}, {1, 2, 4}, {3}};
    int warehouse_2 = 0;
    int customer_location_2 = 4;
    assert(ShortestPath(num_intersections_2, city_map_2, warehouse_2, customer_location_2) == 3);
    // TEST_END

    // TEST
    int num_intersections_3 = 4;
    std::vector<std::vector<int>> city_map_3 = {{1, 2}, {0, 2}, {0, 1, 3}, {2}};
    int warehouse_3 = 0;
    int customer_location_3 = 3;
    assert(ShortestPath(num_intersections_3, city_map_3, warehouse_3, customer_location_3) == 2);
    // TEST_END

}
