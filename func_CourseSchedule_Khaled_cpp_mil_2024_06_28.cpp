/*

khaled_cpp_mil_241_2024_June_28:

func_CourseSchedule_khaled_cpp_mil_241_2024_June_28



Problem Description:
You are developing a system for students to plan their course schedules efficiently.
The university offers a variety of courses, each with prerequisites that must be completed before taking the course.
Determine a valid sequence of courses that a student can take to graduate on time.

Functions:
   - Function name: CourseSchedule
   - Parameters: int num_courses - Total number of courses available.
                 const std::vector<std::vector<int>>& prerequisites - Vector of prerequisites for each course. Each element prerequisites[i] is a vector containing the indices of courses that are prerequisites for course i.
   - Return Type: std::vector<int> - A valid sequence of course indices that a student can take to complete all courses. If no valid sequence exists, return an empty vector.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

std::vector<int> CourseSchedule(int num_courses, const std::vector<std::vector<int>> &prerequisites)
{
    std::vector<int> result;

    // Initialize the in-degree of each course
    std::vector<int> in_degree(num_courses, 0);
    for (const auto &prereq_list : prerequisites)
    {
        for (int course : prereq_list)
        {
            ++in_degree[course];
        }
    }

    // Queue to maintain courses with zero in-degree
    std::queue<int> zero_in_degree_queue;
    for (int i = 0; i < num_courses; ++i)
    {
        if (in_degree[i] == 0)
        {
            zero_in_degree_queue.push(i);
        }
    }

    // Process courses with zero in-degree
    while (!zero_in_degree_queue.empty())
    {
        int course = zero_in_degree_queue.front();
        zero_in_degree_queue.pop();
        result.push_back(course);

        // Decrease the in-degree of dependent courses
        for (int dependent_course : prerequisites[course])
        {
            --in_degree[dependent_course];
            if (in_degree[dependent_course] == 0)
            {
                zero_in_degree_queue.push(dependent_course);
            }
        }
    }

    // Check if all courses are processed
    if (result.size() != num_courses)
    {
        return {};
    }

    return result;
}

int main()
{
    // TEST 1
    int num_courses1 = 4;
    std::vector<std::vector<int>> prerequisites1 = {{1, 0}, {2, 1}, {3, 2}};
    std::vector<int> expected_result1 = {0, 1, 2, 3};
    std::vector<int> result1 = CourseSchedule(num_courses1, prerequisites1);
    assert(result1 == expected_result1);
    std::cout << "Test 1 passed.\n";
    // TEST_END

    // TEST 2
    int num_courses2 = 3;
    std::vector<std::vector<int>> prerequisites2 = {{1, 0}, {2, 1}, {0, 2}};
    std::vector<int> expected_result2 = {};
    std::vector<int> result2 = CourseSchedule(num_courses2, prerequisites2);
    assert(result2 == expected_result2);
    std::cout << "Test 2 passed.\n";
    // TEST_END

    // TEST 3
    int num_courses3 = 4;
    std::vector<std::vector<int>> prerequisites3 = {};
    std::vector<int> expected_result3 = {0, 1, 2, 3};
    std::vector<int> result3 = CourseSchedule(num_courses3, prerequisites3);
    assert(result3 == expected_result3);
    std::cout << "Test 3 passed.\n";
    // TEST_END

    return 0;
}
