


/*
khaled_cpp_mil_241_2024_June_28:

func_MaxItemsWithinBudget_khaled_cpp_mil_241_2024_June_28

Problem Description:
You are going grocery shopping and have a limited budget.
Implement a Dynamic Programming (DP) solution to determine the maximum number of items you can buy without exceeding your budget, given the prices of different grocery items.

Function:
Function name: MaxItemsWithinBudget
Parameters:
  - const std::vector<int>& prices: A vector containing the prices of each grocery item.
  - int budget: The maximum budget you have.
Return Type:
  - int: The maximum number of items you can buy without exceeding the budget.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <string>

int MaxItemsWithinBudget(const std::vector<int>& prices, int budget) {
    int nnn = prices.size();

   
    std::vector<int> dp(budget + 1, 0);

    
    for (int iii = 0; iii < nnn; ++iii) {
       
        for (int jjj = budget; jjj >= prices[iii]; --jjj) {
            dp[jjj] = std::max(dp[jjj], dp[jjj - prices[iii]] + 1);
        }
    }

    return dp[budget];
}

int main() {
    // TEST 
    std::vector<int> prices1 = {10, 5, 15, 7, 6};
    int budget1 = 20;
    int expected_result1 = 3; // Prices: {10, 5, 6}
    int result1 = MaxItemsWithinBudget(prices1, budget1);
    
    assert(result1 == expected_result1);
    // TEST END

    // TEST 
    std::vector<int> prices2 = {5, 5, 5, 5};
    int budget2 = 15;
    int expected_result2 = 3; // Prices: {5, 5, 5}
    int result2 = MaxItemsWithinBudget(prices2, budget2);
    
    assert(result2 == expected_result2);
    // TEST END

    // TEST 
    std::vector<int> prices3 = {8, 10, 12, 15};
    int budget3 = 30;
    int expected_result3 = 3; // Prices: {8, 10, 12}
    int result3 = MaxItemsWithinBudget(prices3, budget3);
    
    assert(result3 == expected_result3);
    // TEST END
}
