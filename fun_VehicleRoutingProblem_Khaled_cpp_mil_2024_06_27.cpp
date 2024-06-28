/*

khaled_cpp_mil_241_2024_June_27:

fun_VehicleRoutingProblem_khaled_cpp_mil_241_2024_June_27


Problem Description:

Design a C++ function called VehicleRouting that takes an integer num_vehicles,
a vector of vectors of doubles std::vector<std::vector<double>> representing the
distances between each pair of locations, a vector of pairs of doubles
std::vector<std::pair<double, double>> representing the start and end of the time
 window for each location, and an integer depot representing the starting and ending
 location of all vehicles.

The function should return a vector of vectors of integers std::vector<std::vector<int>>
 representing the routes for each vehicle to minimize the total travel distance while
  respecting the time windows for each location using a Genetic Algorithm.
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <random>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_set>
#include <vector>

struct Location
{
    int index;
    double start;
    double end;
};

std::vector<std::vector<int>> VehicleRouting(int num_vehicles, const std::vector<std::vector<double>> &distances,
                                             const std::vector<std::pair<double, double>> &time_windows, int depot)
{
    if (depot < 0)
    {
        throw std::invalid_argument("depot can't be less than zero");
    }

    if (depot >= distances.size())
    {
        throw std::invalid_argument("depot should be less than distances size");
    }

    if (num_vehicles <= 0)
    {
        throw std::invalid_argument("num_vehicles should be greater than zero");
    }

    if (distances.empty())
    {
        throw std::invalid_argument("distances can't be empty");
    }

    if (distances.size() != time_windows.size())
    {
        throw std::invalid_argument("distances and time_windows should be with same sizes");
    }

    const int num_locations = distances.size();
    std::vector<Location> locations;
    for (int idx = 0; idx < num_locations; ++idx)
    {
        locations.push_back({idx, time_windows[idx].first, time_windows[idx].second});
    }

    std::vector<std::vector<int>> best_routes(num_vehicles);
    double best_total_distance = std::numeric_limits<double>::max();

    std::random_device rdd;
    std::mt19937 gen(rdd());
    std::uniform_int_distribution<> dis(0, num_locations - 1);

    for (int iteration = 0; iteration < 1000; ++iteration)
    {
        std::vector<std::vector<int>> current_routes(num_vehicles);
        std::vector<double> current_distances(num_vehicles, 0.0);
        std::vector<double> last_time(num_vehicles, time_windows[depot].first);

        std::vector<int> visited(num_locations, 0);
        visited[depot] = num_vehicles;

        for (int vehicle = 0; vehicle < num_vehicles; ++vehicle)
        {
            int current_location = depot;
            while (true)
            {
                int next_location = dis(gen);
                if (visited[next_location] < num_vehicles && next_location != depot &&
                    last_time[vehicle] + distances[current_location][next_location] <=
                        time_windows[next_location].second)
                {
                    current_routes[vehicle].push_back(next_location);
                    current_distances[vehicle] += distances[current_location][next_location];
                    last_time[vehicle] = std::max(time_windows[next_location].first,
                                                  last_time[vehicle] + distances[current_location][next_location]);
                    current_location = next_location;
                    visited[next_location]++;
                }
                else
                {
                    break;
                }
            }
            current_routes[vehicle].push_back(depot);
            current_distances[vehicle] += distances[current_location][depot];
        }

        double current_total_distance = std::accumulate(current_distances.begin(), current_distances.end(), 0.0);
        if (current_total_distance < best_total_distance)
        {
            best_routes = current_routes;
            best_total_distance = current_total_distance;
        }
    }

    return best_routes;
}

#include <cassert>
int main()
{
    // TEST
    int num_vehicles1 = 2;
    std::vector<std::vector<double>> distances1 = {
        {0.0, 10.0, 15.0, 20.0}, {10.0, 0.0, 35.0, 25.0}, {15.0, 35.0, 0.0, 30.0}, {20.0, 25.0, 30.0, 0.0}};
    std::vector<std::pair<double, double>> time_windows1 = {{0.0, 50.0}, {10.0, 20.0}, {15.0, 30.0}, {20.0, 40.0}};
    int depot1 = 0;
    std::vector<std::vector<int>> result1 = VehicleRouting(num_vehicles1, distances1, time_windows1, depot1);

    for (const auto &route : result1)
    {
        for (size_t i = 1; i < route.size(); ++i)
        {
            assert(route[i] != route[i - 1]);
        }
    }
    // TEST_END

    // TEST
    try
    {
        std::vector<std::vector<double>> distances2 = {
            {0.0, 10.0, 15.0, 20.0}, {10.0, 0.0, 35.0, 25.0}, {15.0, 35.0, 0.0, 30.0}, {20.0, 25.0, 30.0, 0.0}};
        std::vector<std::pair<double, double>> time_windows2 = {{0.0, 50.0}, {10.0, 20.0}, {15.0, 30.0}, {20.0, 40.0}};
        int depot2 = 0;
        VehicleRouting(-1, distances2, time_windows2, depot2);
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
        std::vector<std::pair<double, double>> time_windows3 = {{0.0, 50.0}, {10.0, 20.0}, {15.0, 30.0}, {20.0, 40.0}};
        int depot3 = 0;
        VehicleRouting(num_vehicles1, {{0.0, 10.0}, {10.0, 0.0}}, time_windows3, depot3);
        assert(false);
    }
    catch (const std::invalid_argument &e)
    {
        assert(true);
    }
    // TEST_END
}
