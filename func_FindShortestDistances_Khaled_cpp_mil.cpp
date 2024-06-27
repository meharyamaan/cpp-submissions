/*


khaled_cpp_mil_241_2024_June_27:

fun_FindShortestDistances_khaled_cpp_mil_241_2024_June_27

Problem Description:

You have a map of Faisalabad with six colonies: Wapda City, Sitara Valley, Eden Valley, City Housing, Canal Garden, and DHA.
Suppose you are located in three different areas.
you need to find the shortest distance from each area to all six colonies.
Test Case 1: You are currently located in Madina Town. Find the shortest distance from Madina Town to each of the six colonies.
Test Case 2: You are currently located in Jinnah Colony. Find the shortest distance from Jinnah Colony to each of the six colonies.
Test Case 3: You are currently located in People's Colony. Find the shortest distance from People's Colony to each of the six colonies.

Functions:

Function Name: FindShortestDistances
Parameters: None
Return Type: void

Function Name: AddEdge
Parameters:
adj_list: Reference to a vector of vectors of pairs representing the adjacency list of the graph.
vertex1: Integer representing one endpoint of the edge.
vertex2: Integer representing the other endpoint of the edge.
weight: Integer representing the weight or distance of the edge.
Return Type: void
Description: Adds an undirected edge between vertex1 and vertex2 with the specified weight to the adjacency list adj_list.


Function Name: Dijkstra
Parameters:
adj_list: Reference to a vector of vectors of pairs representing the adjacency list of the graph.
num_vertices: Integer representing the number of vertices in the graph.
start_vertex: Integer representing the starting vertex for Dijkstra's algorithm.
Return Type: std::vector<int>
Description: Computes and returns the shortest distances from start_vertex to all other vertices in the graph
using Dijkstra's algorithm.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>
#include <string>
#include <limits>
#include <cassert>

void AddEdge(std::vector<std::vector<std::pair<int, int>>> &adj_list, int vertex1, int vertex2, int weight)
{
    adj_list[vertex1].emplace_back(vertex2, weight);
    adj_list[vertex2].emplace_back(vertex1, weight);
}

std::vector<int> Dijkstra(std::vector<std::vector<std::pair<int, int>>> &adj_list, int num_vertices, int start_vertex)
{
    std::vector<int> distances(num_vertices, std::numeric_limits<int>::max());
    distances[start_vertex] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> priority_queue;
    priority_queue.emplace(0, start_vertex);

    while (!priority_queue.empty())
    {
        int current_distance = priority_queue.top().first;
        int current_vertex = priority_queue.top().second;
        priority_queue.pop();

        if (current_distance > distances[current_vertex])
        {
            continue;
        }

        for (int iii = 0; iii < adj_list[current_vertex].size(); ++iii)
        {
            int next_vertex = adj_list[current_vertex][iii].first;
            int weight = adj_list[current_vertex][iii].second;
            int new_distance = current_distance + weight;

            if (new_distance < distances[next_vertex])
            {
                distances[next_vertex] = new_distance;
                priority_queue.emplace(new_distance, next_vertex);
            }
        }
    }
    return distances;
}

void FindShortestDistances()
{
    int num_vertices = 9;
    std::vector<std::vector<std::pair<int, int>>> adj_list(num_vertices);

    AddEdge(adj_list, 0, 3, 10);
    AddEdge(adj_list, 0, 4, 20);
    AddEdge(adj_list, 0, 5, 30);
    AddEdge(adj_list, 0, 6, 40);
    AddEdge(adj_list, 0, 7, 50);
    AddEdge(adj_list, 0, 8, 60);
    AddEdge(adj_list, 1, 3, 15);
    AddEdge(adj_list, 1, 4, 25);
    AddEdge(adj_list, 1, 5, 35);
    AddEdge(adj_list, 1, 6, 45);
    AddEdge(adj_list, 1, 7, 55);
    AddEdge(adj_list, 1, 8, 65);
    AddEdge(adj_list, 2, 3, 20);
    AddEdge(adj_list, 2, 4, 30);
    AddEdge(adj_list, 2, 5, 40);
    AddEdge(adj_list, 2, 6, 50);
    AddEdge(adj_list, 2, 7, 60);
    AddEdge(adj_list, 2, 8, 70);

    // TEST
    std::vector<int> distances_from_madina = Dijkstra(adj_list, num_vertices, 0);
    assert(distances_from_madina.size() == 9);
    for (int iii = 0; iii < distances_from_madina.size(); ++iii)
    {
        if (distances_from_madina[iii] < 0)
        {
            throw std::invalid_argument("Negative distance found");
        }
    }
    // TEST_END

    // TEST
    std::vector<int> distances_from_jinnah = Dijkstra(adj_list, num_vertices, 1);
    assert(distances_from_jinnah.size() == 9);
    for (int iii = 0; iii < distances_from_jinnah.size(); ++iii)
    {
        if (distances_from_jinnah[iii] < 0)
        {
            throw std::invalid_argument("Negative distance found");
        }
    }
    // TEST_END

    // TEST
    std::vector<int> distances_from_peoples = Dijkstra(adj_list, num_vertices, 2);
    assert(distances_from_peoples.size() == 9);
    for (int iii = 0; iii < distances_from_peoples.size(); ++iii)
    {
        if (distances_from_peoples[iii] < 0)
        {
            throw std::invalid_argument("Negative distance found");
        }
    }
    // TEST_END
}

#include <cassert>

int main()
{
    FindShortestDistances();
}
