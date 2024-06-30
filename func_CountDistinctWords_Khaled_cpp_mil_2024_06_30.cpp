/*

khaled_cpp_mil_244_2024_June_30:

func_CountDistinctWords_khaled_cpp_mil_244_2024_June_30

Problem Description:
You are analyzing a document and need to determine the number of distinct words (segments) it contains.
Words are defined as contiguous sequences of non-space characters.

Function:
Function name: CountDistinctWords
Parameters:
  - const std::string& document: The document string to analyze.
Return Type:
  - int: The number of distinct words (segments) in the document.

*/

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <stdexcept>

int CountDistinctWords(const std::string &document)
{
  std::istringstream iss(document);
  std::unordered_set<std::string> words;

  std::string word;
  while (iss >> word)
  {
    words.insert(word);
  }

  return words.size();
}

#include <cassert>

int main()
{
  // TEST
  std::string document1 = "Hello world! This is a test document. Hello world again.";
  int result1 = CountDistinctWords(document1);
  assert(result1 == 9);
  // TEST_END

  // TEST
  std::string document4 = "";
  int result4 = CountDistinctWords(document4);
  assert(result4 == 0);
  // TEST_END

  // TEST
  std::string document5 = "C++ is a powerful programming language. C++ is used worldwide.";
  int result5 = CountDistinctWords(document5);
  assert(result5 == 7);
  // TEST_END
}
