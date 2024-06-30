/*

khaled_cpp_mil_244_2024_June_30:

func_FewestCoins_khaled_cpp_mil_244_2024_June_30

Problem Description:
You are managing a cash register at a busy store and need to provide customers with the exact change using the least number of coins possible.
You have an infinite supply of coins of different denominations, represented by an integer array coins.
Given an integer amount representing the total amount of money you need to provide as change,
determine the fewest number of coins required to make up that amount.
If it is not possible to provide the exact change using the available denominations, return -1.

Function:
Function name: FewestCoins
Parameters:
  - const std::vector<int>& coins: A vector containing the denominations of available coins.
  - int amount: The total amount of money to provide as change.
Return Type:
  - int: The fewest number of coins required to make up the amount, or -1 if it is not possible.

*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

int FewestCoins(const std::vector<int> &coins, int amount)
{
    if (amount < 0)
    {
        throw std::invalid_argument("Amount cannot be negative");
    }

    std::vector<int> dpp(amount + 1, amount + 1);
    dpp[0] = 0;

    for (int iii = 1; iii <= amount; ++iii)
    {
        for (int coin : coins)
        {
            if (iii >= coin)
            {
                dpp[iii] = std::min(dpp[iii], dpp[iii - coin] + 1);
            }
        }
    }

    return (dpp[amount] > amount) ? -1 : dpp[amount];
}
#include <cassert>
int main()
{
    // TEST
    std::vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    int result1 = FewestCoins(coins1, amount1);
    assert(result1 == 3);
    // TEST_END

    // TEST
    std::vector<int> coins2 = {2};
    int amount2 = 3;
    int result2 = FewestCoins(coins2, amount2);
    assert(result2 == -1);
    // TEST_END

    // TEST
    std::vector<int> coins3 = {1};
    int amount3 = 0;
    int result3 = FewestCoins(coins3, amount3);
    assert(result3 == 0);
    // TEST_END
}
