#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility> // For std::pair

class FoodRatings {
public:
    std::map<std::string, std::set<std::pair<int, std::string>>> cuisine_to_foods;
    std::map<std::string, std::string> food_to_cuisine;
    std::map<std::string, int> food_to_rating;

    FoodRatings(std::vector<std::string>& foods, std::vector<std::string>& cuisines, std::vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            food_to_cuisine[foods[i]] = cuisines[i];
            food_to_rating[foods[i]] = ratings[i];
            cuisine_to_foods[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(std::string food, int newRating) {
        std::string cuisine = food_to_cuisine[food];
        int oldRating = food_to_rating[food];

        cuisine_to_foods[cuisine].erase({-oldRating, food});
        food_to_rating[food] = newRating;
        cuisine_to_foods[cuisine].insert({-newRating, food});
    }

    std::string highestRated(std::string cuisine) {
        return cuisine_to_foods[cuisine].begin()->second;
    }
};