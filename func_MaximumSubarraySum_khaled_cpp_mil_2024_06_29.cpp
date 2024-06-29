/*


khaled_cpp_mil_243_2024_June_29:
func_MaximumSubarraySum_khaled_cpp_mil_243_2024_June_29

Problem Description

Design a C++ function called FindMaximumSubarraySum that takes an integer
 vector std::vector<int> representing an array of integers and returns an integer
 representing the maximum sum of a contiguous subarray using Kadane's Algorithm.
*/

#include <cassert>
#include <stdexcept>
#include <string>
#include <vector>

int FindMaximumSubarraySum(const std::vector<int> &arr)
{
    if (arr.empty())
    {
        throw std::invalid_argument("Input array cannot be empty");
    }

    int max_so_far = arr[0];
    int max_ending_here = arr[0];

    for (size_t i = 1; i < arr.size(); ++i)
    {
        max_ending_here = std::max(arr[i], max_ending_here + arr[i]);
        max_so_far = std::max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main()
{
    // TEST
    std::vector<int> arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result1 = FindMaximumSubarraySum(arr1);
    assert(result1 == 6);
    // TEST_END

    // TEST
    std::vector<int> arr2 = {1};
    int result2 = FindMaximumSubarraySum(arr2);
    assert(result2 == 1);
    // TEST_END

    // TEST
    try
    {
        std::vector<int> arr3 = {};
        FindMaximumSubarraySum(arr3);
        assert(false);
    }
    catch (const std::invalid_argument &e)
    {
        assert(true);
    }
    // TEST_END
}
