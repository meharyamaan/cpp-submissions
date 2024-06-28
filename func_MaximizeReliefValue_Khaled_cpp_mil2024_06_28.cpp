/*

khaled_cpp_mil_241_2024_June_28:

func_MaximizeReliefValue_khaled_cpp_mil_241_2024_June_28


Problem Description:
You are working for a disaster relief organization. After a natural disaster, you need to distribute limited resources 
to various affected areas. Each area has a different need and urgency level. Given the limited capacity of your supply vehicles,
you need to allocate resources in a way that maximizes the total relief value provided to the affected areas.

Functions:
   - Function name: MaximizeReliefValue
   - Parameters: const std::vector<int>& values - the values (importance/urgency) of the resources.
                 const std::vector<int>& weights - the weights of the resources.
                 int capacity - the maximum weight capacity of the supply vehicles.
   - Return Type: int - the maximum total relief value.
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

int MaximizeReliefValue(const std::vector<int>& values, const std::vector<int>& weights, int capacity) {
    if (values.size() != weights.size()) {
        throw std::invalid_argument("Values and weights must have the same size");
    }

    int num_items = values.size();
    std::vector<std::vector<int>> dp(num_items + 1, std::vector<int>(capacity + 1, 0));

    for (int iii = 1; iii <= num_items; ++iii) {
        for (int jjj = 1; jjj <= capacity; ++jjj) {
            if (weights[iii - 1] <= jjj) {
                dp[iii][jjj] = std::max(dp[iii - 1][jjj], dp[iii - 1][jjj - weights[iii - 1]] + values[iii - 1]);
            } else {
                dp[iii][jjj] = dp[iii - 1][jjj];
            }
        }
    }

    return dp[num_items][capacity];
}

int main() {
    // TEST 
    std::vector<int> values_1 = {60, 100, 120};
    std::vector<int> weights_1 = {10, 20, 30};
    int capacity_1 = 50;
    assert(MaximizeReliefValue(values_1, weights_1, capacity_1) == 220);
    // TEST_END

    // TEST 
    std::vector<int> values_2 = {10, 20, 30};
    std::vector<int> weights_2 = {1, 1, 1};
    int capacity_2 = 2;
    assert(MaximizeReliefValue(values_2, weights_2, capacity_2) == 50);
    // TEST_END

    // TEST 
    std::vector<int> values_3 = {10, 40, 50, 70};
    std::vector<int> weights_3 = {1, 3, 4, 5};
    int capacity_3 = 8;
    assert(MaximizeReliefValue(values_3, weights_3, capacity_3) == 110);
    // TEST_END

}
