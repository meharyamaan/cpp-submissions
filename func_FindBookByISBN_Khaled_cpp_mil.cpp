/*

khaled_cpp_mil_241_2024_June_28:

func_FindBookByISBN_khaled_cpp_mil_241_2024_June_28


Problem Description:
You are developing a digital library system that allows users to search for books quickly. 
The library has a large collection of books sorted by their International Standard Book Number (ISBN). 
Users need to find specific books by ISBN efficiently.

Functions:
   - Function name: FindBookByISBN
   - Parameters: const std::vector<std::pair<int, std::string>>& books - a vector of pairs where each pair contains an ISBN (int) and a book title (std::string).
                 int target_isbn - the ISBN of the book to search for.
   - Return Type: std::string - the title of the book if found, or an empty string if not found.
*/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

std::string FindBookByISBN(const std::vector<std::pair<unsigned long long int, std::string>>& books, unsigned long long int target_isbn) {
    int left_index = 0;
    int right_index = books.size() - 1;

    while (left_index <= right_index) {
        int middle_index = left_index + (right_index - left_index) / 2;
        unsigned long long int middle_isbn = books[middle_index].first;

        if (middle_isbn == target_isbn) {
            return books[middle_index].second;
        } else if (middle_isbn < target_isbn) {
            left_index = middle_index + 1;
        } else {
            right_index = middle_index - 1;
        }
    }
    return "";
}

int main() {
    // TEST
    std::vector<std::pair<unsigned long long int, std::string>> books_1 = {
        {9780131103627ULL, "The C Programming Language"},
        {9780131103628ULL, "Artificial Intelligence: A Modern Approach"},
        {9780201633610ULL, "Design Patterns: Elements of Reusable Object-Oriented Software"},
        {9780262033848ULL, "Introduction to Algorithms"},
        {9780321356680ULL, "The C++ Programming Language"}
    };
    assert(FindBookByISBN(books_1, 9780131103627ULL) == "The C Programming Language");
    // TEST_END

    // TEST
    std::vector<std::pair<unsigned long long int, std::string>> books_2 = {
        {9780131103627ULL, "The C Programming Language"},
        {9780132350884ULL, "Clean Code: A Handbook of Agile Software Craftsmanship"},
        {9780135957059ULL, "Clean Architecture: A Craftsman's Guide to Software Structure and Design"},
        {9780201485677ULL, "Refactoring: Improving the Design of Existing Code"},
        {9780596007126ULL, "Head First Design Patterns"}
    };
    assert(FindBookByISBN(books_2, 9780132350884ULL) == "Clean Code: A Handbook of Agile Software Craftsmanship");
    // TEST_END

    // TEST
    std::vector<std::pair<unsigned long long int, std::string>> books_3 = {
        {9780131101630ULL, "Computer Networks"},
        {9780131101632ULL, "Computer Networking: A Top-Down Approach"},
        {9780131103629ULL, "The Pragmatic Programmer: Your Journey to Mastery"},
        {9780321356680ULL, "The C++ Programming Language"},
        {9780321751041ULL, "C++ Primer"}
    };
    assert(FindBookByISBN(books_3, 9780131101631ULL) == "");
    // TEST_END
}
