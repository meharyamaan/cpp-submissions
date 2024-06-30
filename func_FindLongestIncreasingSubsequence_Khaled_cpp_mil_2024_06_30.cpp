/*

khaled_cpp_mil_244_2024_June_30:
func_FindLongestIncreasingSubsequence_khaled_cpp_mil_244_2024_June_30

Problem Description

Design a C++ function called FindLongestIncreasingSubsequence that takes a vector of integers
std::vector<int> representing an array and returns an integer representing the length of the longest increasing subsequence
using dynamic programming.

*/

#include <cassert>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

int FindLongestIncreasingSubsequence(const std::vector<int> &nums)
{
    if (nums.empty())
    {
        throw std::invalid_argument("Array cannot be empty");
    }

    std::vector<int> dp(nums.size(), 1);
    int max_length = 1;

    for (size_t i = 1; i < nums.size(); ++i)
    {
        for (size_t j = 0; j < i; ++j)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        max_length = std::max(max_length, dp[i]);
    }

    return max_length;
}

int main()
{
    // TEST
    std::vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    int result1 = FindLongestIncreasingSubsequence(nums1);
    assert(result1 == 4);
    // TEST_END

    // TEST
    std::vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    int result2 = FindLongestIncreasingSubsequence(nums2);
    assert(result2 == 4);
    // TEST_END

    // TEST
    try
    {
        std::vector<int> nums3 = {};
        FindLongestIncreasingSubsequence(nums3);
        assert(false);
    }
    catch (const std::invalid_argument &e)
    {
        assert(true);
    }
    // TEST_END
}
