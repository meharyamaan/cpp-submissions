/*

khaled_cpp_mil_243_2024_June_29:

func_FindWinnerIndex_khaled_cpp_mil_243_2024_June_29

Problem Description:
You are organizing a series of one-on-one skill-based games among n players, each identified by their unique skill level.
Players are arranged in a queue from player 0 to player n - 1. The winner moves to the front and loser to the end of the queue after each game.
The competition continues until a player wins k consecutive games in a row.
Determine the initial index of the player who achieves this winning streak.

Function:
Function name: FindWinnerIndex
Parameters:
  - vector<int>& skill_levels: A vector containing the skill levels of players in order.
  - int kkk: The number of consecutive wins required to declare a winner.
Return Type:
  - int: The initial index (0-based) of the player who achieves k consecutive wins.

*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <queue>

int FindWinnerIndex(std::vector<int> &skill_levels, int kkk)
{
    int nnn = skill_levels.size();
    std::deque<int> players;

    for (int iii = 0; iii < nnn; ++iii)
    {
        players.push_back(iii);
    }

    int consecutive_wins = 0;
    int winner_index = -1;

    while (!players.empty())
    {
        int player1_index = players.front();
        players.pop_front();

        if (players.empty())
        {
            winner_index = player1_index;
            break;
        }

        int player2_index = players.front();
        players.pop_front();

        int winner = (skill_levels[player1_index] > skill_levels[player2_index]) ? player1_index : player2_index;
        int loser = (winner == player1_index) ? player2_index : player1_index;

        players.push_front(winner);
        players.push_back(loser);

        if (winner == player1_index)
        {
            consecutive_wins++;
            if (consecutive_wins == kkk)
            {
                winner_index = player1_index;
                break;
            }
        }
        else
        {
            consecutive_wins = 0;
        }
    }

    return winner_index;
}

#include <cassert>
int main()
{
    // TEST
    std::vector<int> skill_levels1 = {3, 5, 2, 8, 1};
    int kkk1 = 2;
    int result1 = FindWinnerIndex(skill_levels1, kkk1);
    assert(result1 == 3);
    // TEST END

    // TEST
    std::vector<int> skill_levels3 = {1, 2, 3, 4, 5};
    int kkk3 = 1;
    int result3 = FindWinnerIndex(skill_levels3, kkk3);
    assert(result3 == 4);
    // TEST END
}
