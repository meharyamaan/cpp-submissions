/*

khaled_cpp_mil_244_2024_June_30:
func_FindLongestCommonSubsequence_khaled_cpp_mil_244_2024_June_30

Problem Description

Design a C++ function called FindLongestCommonSubsequence that takes two strings
std::string representing the source and target strings and returns an integer
representing the length of the longest common subsequence using dynamic programming.

*/

#include <cassert>
#include <stdexcept>
#include <string>
#include <vector>

int FindLongestCommonSubsequence(const std::string &source, const std::string &target)
{
    if (source.empty() || target.empty())
    {
        throw std::invalid_argument("Input strings cannot be empty");
    }

    size_t m = source.size();
    size_t n = target.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (size_t i = 1; i <= m; ++i)
    {
        for (size_t j = 1; j <= n; ++j)
        {
            if (source[i - 1] == target[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main()
{
    // TEST
    std::string source1 = "abcde";
    std::string target1 = "ace";
    int result1 = FindLongestCommonSubsequence(source1, target1);
    assert(result1 == 3);
    // TEST_END

    // TEST
    std::string source2 = "abc";
    std::string target2 = "abc";
    int result2 = FindLongestCommonSubsequence(source2, target2);
    assert(result2 == 3);
    // TEST_END

    // TEST
    try
    {
        std::string source3 = "";
        std::string target3 = "abc";
        FindLongestCommonSubsequence(source3, target3);
        assert(false);
    }
    catch (const std::invalid_argument &e)
    {
        assert(true);
    }
    // TEST_END
}
