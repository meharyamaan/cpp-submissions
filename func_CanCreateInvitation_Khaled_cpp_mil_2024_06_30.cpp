/*

khaled_cpp_mil_244_2024_June_30:

func_CanCreateInvitation_khaled_cpp_mil_244_2024_June_30

Problem Description:
You are designing a custom invitation and want to use letters cut out from a magazine to create the text.
You have two strings:
- invitationText: the text you want on the invitation.
- magazineText: the text from the magazine that you can use.
Determine if it's possible to create the invitationText using the letters from magazineText. Each letter in the magazine can only be used once.

Function:
Function name: CanCreateInvitation
Parameters:
  - const std::string& invitation_text: The text you want on the invitation.
  - const std::string& magazine_text: The text from the magazine that you can use.
Return Type:
  - bool: True if it's possible to create the invitation, otherwise false.

*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <stdexcept>

bool CanCreateInvitation(const std::string& invitation_text, const std::string& magazine_text) {
    std::unordered_map<char, int> magazine_count;

    for (char c : magazine_text) {
        magazine_count[c]++;
    }

    for (char c : invitation_text) {
        if (magazine_count[c] == 0) {
            return false;
        }
        magazine_count[c]--;
    }

    return true;
}

#include <cassert>

int main() {
    // TEST 
    std::string invitation_text1 = "hello";
    std::string magazine_text1 = "helloworld";
    bool result1 = CanCreateInvitation(invitation_text1, magazine_text1);
    assert(result1 == true);
    // TEST END

    // TEST 
    std::string invitation_text2 = "invite";
    std::string magazine_text2 = "eventinvitation";
    bool result2 = CanCreateInvitation(invitation_text2, magazine_text2);
    assert(result2 == true);
    // TEST END

    // TEST 
    std::string invitation_text3 = "party";
    std::string magazine_text3 = "patt";
    bool result3 = CanCreateInvitation(invitation_text3, magazine_text3);
    assert(result3 == false);
    // TEST END
}
