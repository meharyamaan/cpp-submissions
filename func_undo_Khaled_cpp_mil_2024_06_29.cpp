/*

khaled_cpp_mil_243_2024_June_29:

func_undo_khaled_cpp_mil_243_2024_June_29

Problem Description:
You are developing a simple text editor for a writing application that needs to support basic typing features along with undo and redo functionality.
Users should be able to type text, undo the last changes, and redo the undone changes. Design a system that efficiently manages these operations.

Function:
Function name: undo
Parameters:
  - None
Return Type:
  - None

Function name: redo
Parameters:
  - None
Return Type:
  - None

*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

std::vector<std::string> text_history;
std::vector<std::string> redo_stack;
std::string current_text;

void type(const std::string &text)
{
    text_history.push_back(current_text);
    current_text += text;
    redo_stack.clear();
}

void undo()
{
    if (text_history.empty())
    {
        throw std::runtime_error("No actions to undo");
    }
    redo_stack.push_back(current_text);
    current_text = text_history.back();
    text_history.pop_back();
}

void redo()
{
    if (redo_stack.empty())
    {
        throw std::runtime_error("No actions to redo");
    }
    text_history.push_back(current_text);
    current_text = redo_stack.back();
    redo_stack.pop_back();
}

std::string get_text()
{
    return current_text;
}
#include <cassert>
int main()
{
    // TEST
    type("Hello");
    type(" World");
    assert(get_text() == "Hello World");
    undo();
    assert(get_text() == "Hello");
    redo();
    assert(get_text() == "Hello World");
    // TEST END

    // TEST
    type(" This");
    type(" is a test.");
    assert(get_text() == "Hello World This is a test.");
    undo();
    undo();
    assert(get_text() == "Hello World");
    redo();
    assert(get_text() == "Hello World This");
    // TEST END

    // TEST
    undo();
    undo();
    assert(get_text() == "Hello");
    undo();
    assert(get_text() == "");
    try
    {
        undo();
    }
    catch (const std::runtime_error &e)
    {
        assert(std::string(e.what()) == "No actions to undo");
    }
    // TEST END
}
