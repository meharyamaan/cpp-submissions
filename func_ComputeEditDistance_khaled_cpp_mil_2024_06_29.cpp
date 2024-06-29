/*

khaled_cpp_mil_243_2024_June_29:
func_ComputeEditDistance_khaled_cpp_mil_243_2024_June_29

Problem Description

Design a C++ function called ComputeEditDistance that takes two strings
std::string representing the source and target strings, and returns
an integer representing the minimum edit distance using dynamic programming.
*/

#include <cassert>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm> // Add this header for std::min and std::initializer_list

int ComputeEditDistance(const std::string &source, const std::string &target)
{
    if (source.empty() || target.empty())
    {
        throw std::invalid_argument("Input strings cannot be empty");
    }

    size_t m = source.size();
    size_t t = target.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(t + 1, 0));

    for (size_t i = 0; i <= m; ++i)
    {
        for (size_t j = 0; j <= t; ++j)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (source[i - 1] == target[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    return dp[m][t];
}

int main()
{
    // TEST
    std::string source1 = "kitten";
    std::string target1 = "sitting";
    int result1 = ComputeEditDistance(source1, target1);
    assert(result1 == 3);
    // TEST_END

    // TEST
    std::string source2 = "flaw";
    std::string target2 = "lawn";
    int result2 = ComputeEditDistance(source2, target2);
    assert(result2 == 2);
    // TEST_END

    // TEST
    try
    {
        std::string source3 = "";
        std::string target3 = "abc";
        ComputeEditDistance(source3, target3);
        assert(false);
    }
    catch (const std::invalid_argument &e)
    {
        assert(true);
    }
    // TEST_END
}
