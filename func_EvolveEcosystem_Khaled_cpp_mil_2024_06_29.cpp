/*

khaled_cpp_mil_243_2024_June_29:

func_EvolveEcosystem_khaled_cpp_mil_243_2024_June_29

Problem Description:
You are a biologist studying the dynamics of an ecosystem in a specified area, represented as an m x n grid.
Each cell in the grid can either be occupied by a species (live, represented by 1) or be empty (dead, represented by 0).
The ecosystem evolves according to the following rules:
1. Any live cell with fewer than two live neighbors dies due to under-population.
2. Any live cell with two or three live neighbors survives to the next generation.
3. Any live cell with more than three live neighbors dies due to over-population.
4. Any dead cell with exactly three live neighbors becomes a live cell due to reproduction.
Your task is to simulate one step of this ecosystem's evolution and return the next state of the grid.

Function:
Function name: EvolveEcosystem
Parameters:
  - std::vector<std::vector<int>>& grid: A 2D binary grid representing the ecosystem.
Return Type:
  - std::vector<std::vector<int>>: The next state of the grid after one evolution step.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

int count_live_neighbors(const std::vector<std::vector<int>> &grid, int iii, int jjj)
{
    int mmm = grid.size();
    int nnn = grid[0].size();
    int live_neighbors = 0;

    for (int x = -1; x <= 1; ++x)
    {
        for (int y = -1; y <= 1; ++y)
        {
            if (x == 0 && y == 0)
                continue;
            int niii = iii + x;
            int njjj = jjj + y;
            if (niii >= 0 && niii < mmm && njjj >= 0 && njjj < nnn && grid[niii][njjj] == 1)
            {
                ++live_neighbors;
            }
        }
    }
    return live_neighbors;
}

std::vector<std::vector<int>> EvolveEcosystem(std::vector<std::vector<int>> &grid)
{
    int mmm = grid.size();
    if (mmm == 0)
        return grid;
    int nnn = grid[0].size();

    std::vector<std::vector<int>> next_state = grid;

    for (int iii = 0; iii < mmm; ++iii)
    {
        for (int jjj = 0; jjj < nnn; ++jjj)
        {
            int live_neighbors = count_live_neighbors(grid, iii, jjj);

            if (grid[iii][jjj] == 1)
            {
                if (live_neighbors < 2 || live_neighbors > 3)
                {
                    next_state[iii][jjj] = 0;
                }
            }
            else
            {
                if (live_neighbors == 3)
                {
                    next_state[iii][jjj] = 1;
                }
            }
        }
    }
    return next_state;
}
#include <cassert>
int main()
{
    // TEST
    std::vector<std::vector<int>> grid1 = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}};
    std::vector<std::vector<int>> expected1 = {
        {0, 0, 0},
        {1, 0, 1},
        {0, 1, 1},
        {0, 1, 0}};
    std::vector<std::vector<int>> result1 = EvolveEcosystem(grid1);
    assert(result1 == expected1);
    // TEST END

    // TEST
    std::vector<std::vector<int>> grid2 = {
        {1, 1},
        {1, 0}};
    std::vector<std::vector<int>> expected2 = {
        {1, 1},
        {1, 1}};
    std::vector<std::vector<int>> result2 = EvolveEcosystem(grid2);
    assert(result2 == expected2);
    // TEST END

    // TEST
    std::vector<std::vector<int>> grid3 = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
    std::vector<std::vector<int>> expected3 = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
    std::vector<std::vector<int>> result3 = EvolveEcosystem(grid3);
    assert(result3 == expected3);
    // TEST END
}
