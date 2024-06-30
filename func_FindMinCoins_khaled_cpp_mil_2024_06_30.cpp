/*

khaled_cpp_mil_244_2024_June_30:
func_FindMinCoins_khaled_cpp_mil_244_2024_June_30

Problem Description

Design a C++ function called FindMinCoins that takes an integer amount
and a vector of integers std::vector<int> representing the coin denominations.
The function should return an integer representing the minimum number of coins
needed to make up that amount using dynamic programming.

*/

#include <cassert>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm> // Add this header for std::min

int FindMinCoins(int amount, const std::vector<int> &coins)
{
    if (amount < 0 || coins.empty())
    {
        throw std::invalid_argument("Invalid input values");
    }

    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i)
    {
        for (const int &coin : coins)
        {
            if (coin <= i)
            {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

int main()
{
    // TEST
    int amount1 = 11;
    std::vector<int> coins1 = {1, 2, 5};
    int result1 = FindMinCoins(amount1, coins1);
    assert(result1 == 3);
    // TEST_END

    // TEST
    int amount2 = 3;
    std::vector<int> coins2 = {2};
    int result2 = FindMinCoins(amount2, coins2);
    assert(result2 == -1);
    // TEST_END

    // TEST
    try
    {
        int amount3 = -1;
        std::vector<int> coins3 = {1, 2, 5};
        FindMinCoins(amount3, coins3);
        assert(false);
    }
    catch (const std::invalid_argument &e)
    {
        assert(true);
    }
    // TEST_END
}
