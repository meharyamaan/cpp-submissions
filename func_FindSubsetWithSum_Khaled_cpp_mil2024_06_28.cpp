/*

khaled_cpp_mil_241_2024_June_28:

func_FindSubsetWithSum_khaled_cpp_mil_241_2024_June_28

Problem Description:
You are managing inventory for a retail store and need to determine the optimal combination of items to restock based on sales data.
Implement an algorithm to find subsets of items that match a specific restocking budget, ensuring efficient allocation of resources.

Function:
Function name: FindSubsetWithSum
Parameters:
  - const std::vector<int>& items: A vector containing the costs of available items.
  - int budget: The specific restocking budget to match.
Return Type:
  - std::vector<int>: A vector containing the subset of item costs that sum up to the budget. An empty vector if no such subset exists.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>

std::vector<int> FindSubsetWithSum(const std::vector<int>& items, int budget) {
    int nnn = items.size();
    std::vector<std::vector<bool>> dp(nnn + 1, std::vector<bool>(budget + 1, false));

    for (int iii = 0; iii <= nnn; ++iii) {
        dp[iii][0] = true;
    }

    for (int iii = 1; iii <= nnn; ++iii) {
        for (int jjj = 1; jjj <= budget; ++jjj) {
            dp[iii][jjj] = dp[iii - 1][jjj];
            if (jjj >= items[iii - 1]) {
                dp[iii][jjj] = dp[iii][jjj] || dp[iii - 1][jjj - items[iii - 1]];
            }
        }
    }

    if (!dp[nnn][budget]) {
        return std::vector<int>();
    }

    std::vector<int> subset;
    int iii = nnn, jjj = budget;
    while (iii > 0 && jjj > 0) {
        if (dp[iii - 1][jjj]) {
            --iii;
        } else {
            subset.push_back(items[iii - 1]);
            jjj -= items[iii - 1];
            --iii;
        }
    }

    return subset;
}

int main() {
    // TEST CASE 1
    std::vector<int> items_1 = {10, 7, 5, 18, 12, 20, 15};
    int budget_1 = 35;
    std::vector<int> result_1 = FindSubsetWithSum(items_1, budget_1);
    assert(result_1.size() > 0);
    // TEST END

    // TEST CASE 2
    std::vector<int> items_2 = {5, 10, 15, 20};
    int budget_2 = 30;
    std::vector<int> result_2 = FindSubsetWithSum(items_2, budget_2);
    assert(result_2.size() > 0);
    // TEST END

    // TEST CASE 3
    std::vector<int> items_3 = {7, 8, 10, 13};
    int budget_3 = 25;
    std::vector<int> result_3 = FindSubsetWithSum(items_3, budget_3);
    assert(result_3.size() > 0);
    // TEST END
}
