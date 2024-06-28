/*


khaled_cpp_mil_241_2024_June_27:

fun_KmpPatternSearch_khaled_cpp_mil_241_2024_June_27

Problem Description:
You are developing a spam detection system for emails.
The system needs to efficiently detect known spam patterns in email texts to prevent them from reaching users' inboxes.

Functions:
   -Function name: KmpPatternSearch
   - Parameters: const std::string& text - the email text to search.
                 const std::string& pattern - the spam pattern to search for.
   - Return Type: bool - true if the pattern is found in the text, false otherwise.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cassert>

std::vector<int> ComputeLPSArray(const std::string &pattern)
{
    int pattern_length = pattern.length();
    std::vector<int> lps(pattern_length, 0);
    int length = 0;
    int iii = 1;

    while (iii < pattern_length)
    {
        if (pattern[iii] == pattern[length])
        {
            ++length;
            lps[iii] = length;
            ++iii;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[iii] = 0;
                ++iii;
            }
        }
    }
    return lps;
}

bool KmpPatternSearch(const std::string &text, const std::string &pattern)
{
    int text_length = text.length();
    int pattern_length = pattern.length();
    std::vector<int> lps = ComputeLPSArray(pattern);
    int iii = 0;
    int jjj = 0;

    while (iii < text_length)
    {
        if (pattern[jjj] == text[iii])
        {
            ++jjj;
            ++iii;
        }

        if (jjj == pattern_length)
        {
            return true;
        }
        else if (iii < text_length && pattern[jjj] != text[iii])
        {
            if (jjj != 0)
            {
                jjj = lps[jjj - 1];
            }
            else
            {
                ++iii;
            }
        }
    }
    return false;
}

#include <cassert>

int main()
{
    // TEST
    std::string email_text_1 = "Dear customer, we have a special offer for you! Click here to claim your prize.";
    std::string spam_pattern_1 = "Click here to claim";
    assert(KmpPatternSearch(email_text_1, spam_pattern_1));
    // TEST_END

    // TEST
    std::string email_text_2 = "Hello, this is an important notification. Please verify your account by clicking the link.";
    std::string spam_pattern_2 = "verify your account";
    assert(KmpPatternSearch(email_text_2, spam_pattern_2));
    // TEST_END

    // TEST
    std::string email_text_3 = "Hi there, I hope this message finds you well. Let's catch up soon!";
    std::string spam_pattern_3 = "urgent";
    assert(!KmpPatternSearch(email_text_3, spam_pattern_3));
    // TEST_END
}
