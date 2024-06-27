/*

khaled_cpp_mil_241_2024_June_27:

fun_MaxStockProfit_khaled_cpp_mil_241_2024_June_27

Problem Description:

Design a C++ function called findMaxStockProfit that takes a constant reference
to a vector of integers representing the stock prices for consecutive days. The function
returns an integer representing the maximum profit that can be achieved
by buying and selling the stock on different days.

*/

#include <algorithm>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;

int findMaxStockProfit(const vector<int> &stock_prices)
{
    int num_days = stock_prices.size();

    if (num_days < 2)
    {
        return 0;
    }

    int max_profit = 0;
    int current_profit = 0;
    for (int day_index = 1; day_index < num_days; ++day_index)
    {
        int price_diff = stock_prices[day_index] - stock_prices[day_index - 1];

        current_profit = max(price_diff, current_profit + price_diff);

        max_profit = max(max_profit, current_profit);
    }

    return max_profit;
}
#include <cassert>
int main()
{
    // TEST
    vector<int> prices1 = {7, 5, 8, 2, 9};
    int expected_profit1 = 7;
    int max_profit1 = findMaxStockProfit(prices1);
    assert(max_profit1 == expected_profit1);
    // TEST END

    // TEST
    vector<int> prices2 = {1, 2, 3, 4, 5};
    int expected_profit2 = 4;
    int max_profit2 = findMaxStockProfit(prices2);
    assert(max_profit2 == expected_profit2);
    // TEST END

    // TEST
    vector<int> prices3 = {5, 4, 3, 2, 1};
    int expected_profit3 = 0;
    int max_profit3 = findMaxStockProfit(prices3);
    assert(max_profit3 == expected_profit3);
    // TEST_END

    // TEST
    vector<int> prices4 = {5};
    int expected_profit4 = 0;
    int max_profit4 = findMaxStockProfit(prices4);
    assert(max_profit4 == expected_profit4);
    // TEST_END

    // TEST
    vector<int> prices5 = {5, 5, 5, 5, 5};
    int expected_profit5 = 0;
    int max_profit5 = findMaxStockProfit(prices5);
    assert(max_profit5 == expected_profit5);
    // TEST_END

    // TEST
    vector<int> prices6 = {1, 7, 5, 3, 6, 4, 8};
    int expected_profit6 = 7;
    int max_profit6 = findMaxStockProfit(prices6);
    assert(max_profit6 == expected_profit6);
    // TEST_END
}
