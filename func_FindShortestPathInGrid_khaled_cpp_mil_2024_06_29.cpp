/*

khaled_cpp_mil_243_2024_June_29:
func_FindShortestPathInGrid_khaled_cpp_mil_243_2024_June_29

Problem Description

Design a C++ function called FindShortestPathInGrid that takes a 2D vector of integers
std::vector<std::vector<int>> representing a grid where each cell is either 0 (walkable) or 1 (blocked),
and two pairs of integers std::pair<int, int> representing the starting and ending coordinates.
The function should return an integer representing the length of the shortest path from the start
to the end using Breadth-First Search (BFS).

*/

#include <cassert>
#include <stdexcept>
#include <string>
#include <vector>
#include <queue>
#include <utility>

int FindShortestPathInGrid(const std::vector<std::vector<int>> &grid, std::pair<int, int> start, std::pair<int, int> end)
{
    if (grid.empty() || grid[0].empty())
    {
        throw std::invalid_argument("Grid cannot be empty");
    }

    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    std::queue<std::pair<int, std::pair<int, int>>> q;
    q.push({0, start});
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        auto [dist, point] = q.front();
        q.pop();
        if (point == end)
        {
            return dist;
        }
        for (const auto &dir : directions)
        {
            int new_row = point.first + dir[0];
            int new_col = point.second + dir[1];
            if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && !visited[new_row][new_col] && grid[new_row][new_col] == 0)
            {
                q.push({dist + 1, {new_row, new_col}});
                visited[new_row][new_col] = true;
            }
        }
    }

    return -1; // Return -1 if there is no path
}

int main()
{
    // TEST
    std::vector<std::vector<int>> grid1 = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}};
    std::pair<int, int> start1 = {0, 0};
    std::pair<int, int> end1 = {4, 4};
    int result1 = FindShortestPathInGrid(grid1, start1, end1);
    assert(result1 == 8);
    // TEST_END

    // TEST
    std::vector<std::vector<int>> grid2 = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}};
    std::pair<int, int> start2 = {0, 0};
    std::pair<int, int> end2 = {3, 2};
    int result2 = FindShortestPathInGrid(grid2, start2, end2);
    assert(result2 == 5);
    // TEST_END

    // TEST
    try
    {
        std::vector<std::vector<int>> grid3 = {};
        std::pair<int, int> start3 = {0, 0};
        std::pair<int, int> end3 = {4, 4};
        FindShortestPathInGrid(grid3, start3, end3);
        assert(false);
    }
    catch (const std::invalid_argument &e)
    {
        assert(true);
    }
    // TEST_END
}
