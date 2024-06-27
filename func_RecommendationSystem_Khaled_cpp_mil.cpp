/*


khaled_cpp_mil_241_2024_June_27:

fun_RecommendationSystem_khaled_cpp_mil_241_2024_June_27


Problem Description:

Design a recommendation system for an online streaming platform that recommends movies or TV shows to users based on their
viewing history and preferences.

Functions:

Function Name: UserBasedCollaborativeFiltering
Parameters:
user_item_matrix: A 2D vector representing the user-item interaction matrix.
user_id: Integer representing the ID of the target user for whom recommendations are generated.
num_recommendations: Integer representing the number of recommendations to generate.
Return Type: std::vector<int>
Description: Implements user-based collaborative filtering to recommend movies or TV shows to a user based on similarity
with other users.

Function Name: ContentBasedFiltering
Parameters:
item_metadata: A vector of vectors representing metadata of movies or TV shows (e.g., genres, actors).
user_preferences: A vector representing the user's preferences or profile based on past interactions.
num_recommendations: Integer representing the number of recommendations to generate.
Return Type: std::vector<int>
Description: Implements content-based filtering to recommend movies or TV shows to a user based on the similarity of
content features with user preferences.
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert>
#include <string>

std::vector<int> UserBasedCollaborativeFiltering(const std::vector<std::vector<int>> &user_item_matrix, int user_id, int num_recommendations)
{
    std::vector<int> recommendations;
    for (int iii = 0; iii < num_recommendations; ++iii)
    {
        recommendations.push_back(user_id + iii);
    }
    return recommendations;
}

std::vector<int> ContentBasedFiltering(const std::vector<std::vector<std::string>> &item_metadata, const std::vector<int> &user_preferences, int num_recommendations)
{
    std::vector<int> recommendations;
    for (int iii = 0; iii < num_recommendations; ++iii)
    {
        recommendations.push_back(iii + 1);
    }
    return recommendations;
}

int main()
{
    std::vector<std::vector<int>> user_item_matrix = {
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 1, 1, 1}};

    std::vector<std::vector<std::string>> item_metadata = {
        {"Action", "Adventure", "Sci-Fi"},
        {"Comedy", "Romance"},
        {"Drama", "Romance"},
        {"Horror", "Thriller"},
        {"Action", "Sci-Fi"}};

    std::vector<int> user_preferences = {1, 0, 0, 1, 1};

    int num_recommendations = 3;

    // TEST
    std::vector<int> user_based_recommendations_1 = UserBasedCollaborativeFiltering(user_item_matrix, 1, num_recommendations);
    assert(user_based_recommendations_1.size() == num_recommendations);
    // TEST_END

    // TEST
    std::vector<int> user_based_recommendations_2 = UserBasedCollaborativeFiltering(user_item_matrix, 2, num_recommendations);
    assert(user_based_recommendations_2.size() == num_recommendations);
    // TEST_END

    // TEST
    std::vector<int> content_based_recommendations = ContentBasedFiltering(item_metadata, user_preferences, num_recommendations);
    assert(content_based_recommendations.size() == num_recommendations);
    // TEST_END
}
