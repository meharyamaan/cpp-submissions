/*


khaled_cpp_mil_241_2024_June_27:

fun_SelectTwoLargePrimes_khaled_cpp_mil_241_2024_June_27


Problem Description:

You are developing a cryptographic system and need to generate two large prime numbers for RSA encryption.
Implement the Sieve of Eratosthenes algorithm to find all prime numbers up to a given number n.
Use these primes to select two random large primes for RSA key generation.

Functions:
   -Funcyion name: SieveOfEratosthenes
   - Parameters: int limit - the upper bound for finding prime numbers.
   - Return Type: std::vector<int> - a list of all prime numbers up to the limit.

   -Funcyion name: SelectTwoLargePrimes
   - Parameters: const std::vector<int>& primes - a list of prime numbers.
   - Return Type: std::pair<int, int> - a pair of two randomly selected prime numbers from the list.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>

std::vector<int> SieveOfEratosthenes(int limit)
{
    if (limit < 2)
    {
        throw std::invalid_argument("Limit must be greater than or equal to 2");
    }
    std::vector<int> primes;
    std::vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int iii = 2; iii <= std::sqrt(limit); ++iii)
    {
        if (is_prime[iii])
        {
            for (int jjj = iii * iii; jjj <= limit; jjj += iii)
            {
                is_prime[jjj] = false;
            }
        }
    }

    for (int iii = 2; iii <= limit; ++iii)
    {
        if (is_prime[iii])
        {
            primes.push_back(iii);
        }
    }

    return primes;
}

std::pair<int, int> SelectTwoLargePrimes(const std::vector<int> &primes)
{
    if (primes.size() < 2)
    {
        throw std::invalid_argument("Not enough primes to select two large primes");
    }
    std::srand(static_cast<unsigned>(std::time(0)));
    int first_prime_index = std::rand() % primes.size();
    int second_prime_index;
    do
    {
        second_prime_index = std::rand() % primes.size();
    } while (second_prime_index == first_prime_index);

    return {primes[first_prime_index], primes[second_prime_index]};
}
#include <cassert>
int main()
{
    int limit = 100000;

    // TEST
    std::vector<int> primes = SieveOfEratosthenes(limit);
    assert(!primes.empty());
    // TEST_END

    // TEST
    std::pair<int, int> large_primes = SelectTwoLargePrimes(primes);
    assert(large_primes.first != large_primes.second);
    // TEST_END
}
