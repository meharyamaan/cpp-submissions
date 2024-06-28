/*

khaled_cpp_mil_241_2024_June_26:

fun_ResourceAllocation_khaled_cpp_mil_241_2024_June_26

Problem Description:

Design a C++ function called ResourceAllocation that takes an integer num_tasks,
a vector of integers std::vector<int> representing the required resources for each task,
an integer total_resources representing the total available resources, and an vector of doubles
std::vector<double> representing the priority of each task.

The function should return a vector of integers std::vector<int> representing the indices of the
tasks that should be executed to maximize the total priority of executed tasks without exceeding
the total available resources. Use a Greedy Algorithm to solve this problem.

*/

#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <vector>

struct Task
{
    int index;
    int required_resources;
    double priority;
};

bool compare_tasks(const Task &task_a, const Task &task_b) { return task_a.priority > task_b.priority; }

std::vector<int> resource_allocation(int num_tasks, const std::vector<int> &required_resources, int total_resources,
                                     const std::vector<double> &priority)
{
    if (num_tasks <= 0 || required_resources.size() != num_tasks || priority.size() != num_tasks ||
        total_resources < 0)
    {
        throw std::invalid_argument("Invalid input values");
    }

    std::vector<Task> tasks;
    for (int task_idx = 0; task_idx < num_tasks; ++task_idx)
    {
        tasks.push_back({task_idx, required_resources[task_idx], priority[task_idx]});
    }

    std::sort(tasks.begin(), tasks.end(), compare_tasks);

    std::vector<int> selected_tasks;
    int used_resources = 0;
    for (const Task &task : tasks)
    {
        if (used_resources + task.required_resources <= total_resources)
        {
            selected_tasks.push_back(task.index);
            used_resources += task.required_resources;
        }
    }

    return selected_tasks;
}

int main()
{
    // TEST
    int num_tasks1 = 5;
    std::vector<int> required_resources1 = {10, 20, 30, 40, 50};
    int total_resources1 = 70;
    std::vector<double> priority1 = {5.0, 4.0, 3.0, 2.0, 1.0};
    std::vector<int> result1 = resource_allocation(num_tasks1, required_resources1, total_resources1, priority1);

    int used_resources1 = 0;
    double total_priority1 = 0.0;
    for (int task_idx : result1)
    {
        used_resources1 += required_resources1[task_idx];
        total_priority1 += priority1[task_idx];
    }
    assert(used_resources1 <= total_resources1);
    assert(total_priority1 == 12.0);
    // TEST_END

    // TEST
    try
    {
        resource_allocation(-1, required_resources1, total_resources1, priority1);
        assert(false);
    }
    catch (const std::invalid_argument &e)
    {
        assert(true);
    }
    // TEST_END

    // TEST
    try
    {
        resource_allocation(num_tasks1, {10, 20}, total_resources1, priority1);
        assert(false);
    }
    catch (const std::invalid_argument &e)
    {
        assert(true);
    }
    // TEST_END

    // TEST
    int num_tasks2 = 3;
    std::vector<int> required_resources2 = {50, 30, 20};
    int total_resources2 = 50;
    std::vector<double> priority2 = {3.0, 2.0, 1.0};
    std::vector<int> result2 = resource_allocation(num_tasks2, required_resources2, total_resources2, priority2);

    int used_resources2 = 0;
    double total_priority2 = 0.0;
    for (int task_idx : result2)
    {
        used_resources2 += required_resources2[task_idx];
        total_priority2 += priority2[task_idx];
    }
    assert(used_resources2 <= total_resources2);
    assert(total_priority2 == 3.0);
    // TEST_END
}
