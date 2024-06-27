/*


khaled_cpp_mil_241_2024_June_27:

fun_LetterCombinations_khaled_cpp_mil_241_2024_June_27


Problem Description:

You are developing an automated messaging system for a marketing campaign.
Users enter their phone numbers to receive personalized messages.
Your task is to convert these phone numbers into all possible combinations of letters corresponding
to their numeric keys, similar to old mobile phones.

Function Description:

Function Name: LetterCombinations
Parameters:
digits: A string representing the digits (2-9) entered by the user.
Return Type: std::vector<std::string>
Description: Generates and returns all possible letter combinations that can be formed from the digits entered by the user
using the phone keypad.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cassert>

std::vector<std::string> LetterCombinations(const std::string &digits)
{
    if (digits.empty())
    {
        throw std::invalid_argument("Empty input");
    }

    const std::vector<std::string> keypad = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> result;

    result.push_back("");

    for (char digit : digits)
    {
        int num = digit - '0';
        if (num < 2 || num > 9)
        {
            throw std::invalid_argument("Invalid digit: " + std::to_string(num));
        }

        const std::string &letters = keypad[num - 2];
        std::vector<std::string> temp;

        for (const std::string &prefix : result)
        {
            for (char letter : letters)
            {
                temp.push_back(prefix + letter);
            }
        }

        result.swap(temp);
    }

    return result;
}

#include <cassert>

int main()
{
    // TEST
    std::vector<std::string> test_case_1 = LetterCombinations("23");
    assert(test_case_1.size() == 9);
    // TEST_END

    // TEST
    std::vector<std::string> test_case_2 = LetterCombinations("78");
    assert(test_case_2.size() == 12);
    // TEST_END

    // TEST
    std::vector<std::string> test_case_3 = LetterCombinations("9");
    assert(test_case_3.size() == 4);
    // TEST_END
}
