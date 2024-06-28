/*
khaled_cpp_mil_241_2024_June_28:

func_PackContainers_khaled_cpp_mil_241_2024_June_28

Problem Description:
You are tasked with efficiently packing containers for international shipping, where each container has a maximum weight capacity. Implement an algorithm to determine the maximum number of items that can be packed into each container without exceeding its weight limit, ensuring cost-effective and efficient logistics operations.

Function:
Function name: PackContainers
Parameters:
  - const std::vector<int>& weights: A vector containing the weights of the items.
  - int max_capacity: The maximum weight capacity of each container.
Return Type:
  - std::vector<int>: A vector where each element represents the maximum number of items that can be packed into each container without exceeding its weight limit.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>
#include <string>


std::vector<int> PackContainers(const std::vector<int>& weights, int max_capacity) {
  
    if (max_capacity <= 0) {
        throw std::invalid_argument("Container capacity must be positive.");
    }

    int nnn = weights.size(); // Changed n to nnn for clarity
    std::vector<int> max_items_per_container(nnn, 0);

    int left = 0, right = 0;
    int current_weight = 0;
    int items_in_container = 0;

    while (right < nnn) {
     
        current_weight += weights[right];
        items_in_container++;

     
        while (current_weight > max_capacity) {
           
            current_weight -= weights[left];
            items_in_container--;
            left++;
        }

        max_items_per_container[right] = items_in_container;
        right++;
    }

    return max_items_per_container;
}

int main() {
   // TEST 
    std::vector<int> weights_4 = {50};
    int max_capacity_4 = 30;
    std::vector<int> expected_result_4 = {0};
    std::vector<int> result_4 = PackContainers(weights_4, max_capacity_4);
    assert(result_4 == expected_result_4);
    // TEST END
    
    // TEST 
    std::vector<int> weights_6;
    int max_capacity_6 = 10;
    std::vector<int> expected_result_6;
    std::vector<int> result_6 = PackContainers(weights_6, max_capacity_6);
    assert(result_6 == expected_result_6);
    // TEST END

}
