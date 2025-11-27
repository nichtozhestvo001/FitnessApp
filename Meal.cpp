#include "Meal.hpp"
#include "FoodItem.hpp"


void Meal::addFoodItem(const FoodItem& item) {
    foodItems.push_back(item);
}

void Meal::calculateTotals() {
    totalCalories = 0; 
}


void Meal::substituteItem(const FoodItem& oldItem, const FoodItem& newItem) {
}