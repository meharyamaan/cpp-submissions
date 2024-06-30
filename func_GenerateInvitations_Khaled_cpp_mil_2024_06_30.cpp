/*

khaled_cpp_mil_244_2024_June_30:

func_GenerateInvitations_khaled_cpp_mil_244_2024_June_30

Problem Description:
You are organizing a large event and need to send out special invitations based on guest numbers.
Each guest is assigned a unique number from 1 to n. Based on their guest number, the invitation should contain a special message:

If the guest number is divisible by both 3 and 5, the invitation should say "SpecialVIP".
If the guest number is divisible by 3, the invitation should say "VIP".
If the guest number is divisible by 5, the invitation should say "Guest".
If none of the above conditions are met, the invitation should just include their guest number as a string.

Function:
Function name: GenerateInvitations
Parameters:
  - int nnn: The total number of guests.
Return Type:
  - std::vector<std::string>: A vector containing the appropriate invitation messages for all guests.

*/

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

std::vector<std::string> GenerateInvitations(int nnn)
{
    if (nnn <= 0)
    {
        throw std::invalid_argument("Number of guests must be greater than 0.");
    }

    std::vector<std::string> invitations;

    for (int iii = 1; iii <= nnn; ++iii)
    {
        if (iii % 15 == 0)
        {
            invitations.push_back("SpecialVIP");
        }
        else if (iii % 3 == 0)
        {
            invitations.push_back("VIP");
        }
        else if (iii % 5 == 0)
        {
            invitations.push_back("Guest");
        }
        else
        {
            invitations.push_back(std::to_string(iii));
        }
    }

    return invitations;
}

#include <cassert>

int main()
{
    // TEST
    int nnn1 = 15;
    std::vector<std::string> expected1 = {"1", "2", "VIP", "4", "Guest", "VIP", "7", "8", "VIP", "Guest", "11", "VIP", "13", "14", "SpecialVIP"};
    std::vector<std::string> result1 = GenerateInvitations(nnn1);
    assert(result1 == expected1);
    // TEST_END

    // TEST
    int nnn2 = 5;
    std::vector<std::string> expected2 = {"1", "2", "VIP", "4", "Guest"};
    std::vector<std::string> result2 = GenerateInvitations(nnn2);
    assert(result2 == expected2);
    // TEST_END

    // TEST
    int nnn3 = 1;
    std::vector<std::string> expected3 = {"1"};
    std::vector<std::string> result3 = GenerateInvitations(nnn3);
    assert(result3 == expected3);
    // TEST_END
}
