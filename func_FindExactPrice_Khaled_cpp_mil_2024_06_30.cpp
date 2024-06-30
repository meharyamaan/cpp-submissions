/*

khaled_cpp_mil_244_2024_June_30:

func_FindExactPrice_khaled_cpp_mil_244_2024_June_30

Problem Description:
You are at an auction and need to guess the exact price of a hidden product. The price is an integer between 1 and n.
Each time you guess, the auctioneer tells you if the actual price is higher or lower than your guess.
Your goal is to determine the exact price using the fewest guesses possible.

Function:
Function name: FindExactPrice
Parameters:
  - int nnn: The upper limit of the price range.
Return Type:
  - int: The exact price of the product.

*/

#include <stdexcept>
#include <string>
#include <iostream>

int check_price(int guess);

int FindExactPrice(int nnn)
{
    int low = 1;
    int high = nnn;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int result = check_price(mid);

        if (result == 0)
        {
            return mid;
        }
        else if (result == -1)
        {
            high = mid - 1;
        }
        else if (result == 1)
        {
            low = mid + 1;
        }
    }

    throw std::runtime_error("Price not found within the given range");
}

int check_price(int guess)
{

    const int actual_price = 23;
    if (guess > actual_price)
    {
        return -1;
    }
    else if (guess < actual_price)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
#include <cassert>
int main()
{
    // TEST
    int nnn1 = 100;
    int result1 = FindExactPrice(nnn1);
    assert(result1 == 23);
    // TEST_END

    // TEST
    int nnn2 = 50;
    int result2 = FindExactPrice(nnn2);
    assert(result2 == 23);
    // TEST_END

    // TEST
    int nnn3 = 30;
    int result3 = FindExactPrice(nnn3);
    assert(result3 == 23);
    // TEST_END
}
