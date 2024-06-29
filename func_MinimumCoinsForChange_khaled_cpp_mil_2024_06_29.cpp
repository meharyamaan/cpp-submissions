/*

khaled_cpp_mil_243_2024_June_29:
func_MinimumCoinsForChange_khaled_cpp_mil_243_2024_June_29:

Problem Description


Design a C++ function called MinimumCoinsForChange that takes an integer
int representing the amount, and a vector of integers std::vector<int>
representing coin denominations. The function should return an integer
representing the minimum number of coins needed to make the amount using
dynamic programming.
*/

#include <cassert>
#include <stdexcept>
#include <string>
#include <vector>

int MinimumCoinsForChange(int amount, const std::vector<int> &coins)
{
    if (amount < 0 || coins.empty())
    {
        throw std::invalid_argument("Invalid input values");
    }

    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int coin : coins)
    {
        for (int i = coin; i <= amount; ++i)
        {
            dp[i] = std::min(dp[i], dp[i - coin] + 1);
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

int main()
{
    // TEST
    int amount1 = 11;
    std::vector<int> coins1 = {1, 2, 5};
    int result1 = MinimumCoinsForChange(amount1, coins1);
    assert(result1 == 3);
    // TEST_END

    // TEST
    int amount2 = 3;
    std::vector<int> coins2 = {2};
    int result2 = MinimumCoinsForChange(amount2, coins2);
    assert(result2 == -1);
    // TEST_END

    // TEST
    try
    {
        int amount3 = -1;
        std::vector<int> coins3 = {1, 2, 5};
        MinimumCoinsForChange(amount3, coins3);
        assert(false);
    }
    catch (const std::invalid_argument &e)
    {
        assert(true);
    }
    // TEST_END
}
