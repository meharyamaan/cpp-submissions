/*

khaled_cpp_mil_244_2024_June_30:
func_SolveKnapsack_khaled_cpp_mil_244_2024_June_30

Problem Description

Design a C++ function called SolveKnapsack that takes an integer capacity,
a vector of integers std::vector<int> representing the weights of items,
and a vector of integers std::vector<int> representing the values of items.
The function should return an integer representing the maximum value that can be obtained
by selecting items such that their total weight does not exceed the capacity using dynamic programming.

*/

#include <cassert>
#include <stdexcept>
#include <string>
#include <vector>

int SolveKnapsack(int capacity, const std::vector<int> &weights, const std::vector<int> &values)
{
    if (capacity <= 0 || weights.empty() || values.empty() || weights.size() != values.size())
    {
        throw std::invalid_argument("Invalid input values");
    }

    size_t n = weights.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    for (size_t i = 1; i <= n; ++i)
    {
        for (int w = 0; w <= capacity; ++w)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    // TEST
    int capacity1 = 50;
    std::vector<int> weights1 = {10, 20, 30};
    std::vector<int> values1 = {60, 100, 120};
    int result1 = SolveKnapsack(capacity1, weights1, values1);
    assert(result1 == 220);
    // TEST_END

    // TEST
    int capacity2 = 7;
    std::vector<int> weights2 = {1, 3, 4, 5};
    std::vector<int> values2 = {1, 4, 5, 7};
    int result2 = SolveKnapsack(capacity2, weights2, values2);
    assert(result2 == 9);
    // TEST_END

    // TEST
    try
    {
        int capacity3 = -1;
        std::vector<int> weights3 = {1, 2, 3};
        std::vector<int> values3 = {10, 20, 30};
        SolveKnapsack(capacity3, weights3, values3);
        assert(false);
    }
    catch (const std::invalid_argument &e)
    {
        assert(true);
    }
    // TEST_END
}
