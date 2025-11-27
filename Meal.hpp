#ifndef MEAL_HPP
#define MEAL_HPP

#include <vector>
#include "types.hpp"
#include "FoodItem.hpp"

class Meal
{
public:
    Meal() = default;
    ~Meal() = default;

private:
    std::string id; 
    std::string dietId; 
    std::string mealTime; 
    std::vector<FoodItem> foodItems; 
    int totalCalories; 
    Nutrition nutrition; 

public:
    void addFoodItem(const FoodItem& item);
    void calculateTotals();
    void substituteItem(const FoodItem& oldItem, const FoodItem& newItem);
};

#endif