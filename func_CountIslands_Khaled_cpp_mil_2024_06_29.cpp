/*

khaled_cpp_mil_243_2024_June_29:

func_CountIslands_khaled_cpp_mil_243_2024_June_29

Problem Description:
You are working for a disaster management agency that monitors flood-prone areas using satellite images.
The satellite images are represented as an m x n 2D binary grid where '1' indicates land and '0' indicates water.
Your task is to write a program that counts the number of distinct islands in the area.
An island is defined as a group of '1's connected horizontally or vertically and surrounded by water.

Function:
Function name: CountIslands
Parameters:
  - std::vector<std::vector<int>>& grid: A 2D binary grid representing the satellite images.
Return Type:
  - int: The number of distinct islands in the grid.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

void dfs(std::vector<std::vector<int>> &grid, int iii, int jjj)
{
    int mmm = grid.size();
    int nnn = grid[0].size();

    if (iii < 0 || jjj < 0 || iii >= mmm || jjj >= nnn || grid[iii][jjj] == 0)
    {
        return;
    }

    grid[iii][jjj] = 0;

    dfs(grid, iii + 1, jjj);
    dfs(grid, iii - 1, jjj);
    dfs(grid, iii, jjj + 1);
    dfs(grid, iii, jjj - 1);
}

int CountIslands(std::vector<std::vector<int>> &grid)
{
    int mmm = grid.size();
    if (mmm == 0)
        return 0;
    int nnn = grid[0].size();

    int count = 0;
    for (int iii = 0; iii < mmm; ++iii)
    {
        for (int jjj = 0; jjj < nnn; ++jjj)
        {
            if (grid[iii][jjj] == 1)
            {
                ++count;
                dfs(grid, iii, jjj);
            }
        }
    }

    return count;
}
#include <cassert>
int main()
{
    // TEST
    std::vector<std::vector<int>> grid1 = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}};
    int result1 = CountIslands(grid1);
    assert(result1 == 3);
    // TEST END

    // TEST
    std::vector<std::vector<int>> grid2 = {
        {1, 0, 0, 1},
        {0, 0, 1, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 1}};
    int result2 = CountIslands(grid2);
    assert(result2 == 5);
    // TEST END

    // TEST
    std::vector<std::vector<int>> grid3 = {
        {1, 1, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}};
    int result3 = CountIslands(grid3);
    assert(result3 == 1);
    // TEST END
}
