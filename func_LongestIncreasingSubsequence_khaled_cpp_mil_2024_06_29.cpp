/*

khaled_cpp_mil_243_2024_June_29:
func_LongestIncreasingSubsequence_khaled_cpp_mil_243_2024_June_29

Problem Description

Design a C++ function called FindLongestIncreasingSubsequence that takes an
integer vector std::vector<int> representing an array of integers and returns
an integer representing the length of the longest increasing subsequence using
 dynamic programming.
*/

#include <cassert>
#include <stdexcept>
#include <string>
#include <vector>

int FindLongestIncreasingSubsequence(const std::vector<int> &arr)
{
    if (arr.empty())
    {
        throw std::invalid_argument("Input array cannot be empty");
    }

    std::vector<int> lis(arr.size(), 1);

    for (size_t i = 1; i < arr.size(); ++i)
    {
        for (size_t j = 0; j < i; ++j)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int max_lis = 0;
    for (size_t i = 0; i < arr.size(); ++i)
    {
        max_lis = std::max(max_lis, lis[i]);
    }

    return max_lis;
}

int main()
{
    // TEST
    std::vector<int> arr1 = {10, 9, 2, 5, 3, 7, 101, 18};
    int result1 = FindLongestIncreasingSubsequence(arr1);
    assert(result1 == 4);
    // TEST_END

    // TEST
    std::vector<int> arr2 = {0, 1, 0, 3, 2, 3};
    int result2 = FindLongestIncreasingSubsequence(arr2);
    assert(result2 == 4);
    // TEST_END

    // TEST
    try
    {
        std::vector<int> arr3 = {};
        FindLongestIncreasingSubsequence(arr3);
        assert(false);
    }
    catch (const std::invalid_argument &e)
    {
        assert(true);
    }
    // TEST_END
}
