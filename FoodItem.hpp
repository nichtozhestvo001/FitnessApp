#ifndef FOODITEM_HPP
#define FOODITEM_HPP

#include <set>
#include "types.hpp"

class FoodItem
{
public:
    FoodItem() = default;
    FoodItem(const std::string& id, const std::string& name, int caloriesPer100g, double proteinPer100g, double carbsPer100g, double fatsPer100g);
    ~FoodItem() = default;

private:
    std::string id; 
    std::string name; 
    int caloriesPer100g; 
    double proteinPer100g;
    double carbsPer100g;
    double fatsPer100g;

public:
    Nutrition getNutrition(double amountG) const;
    bool isAllergenFree(const std::set<Allergen>& allergens) const;
};

#endif