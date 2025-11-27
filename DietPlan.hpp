#ifndef DIETPLAN_HPP
#define DIETPLAN_HPP

#include <vector>
#include "types.hpp"

class Meal;

class DietPlan
{
public:
    DietPlan() = default;
    ~DietPlan() = default;

private:
    std::string id; 
    std::string userId; 
    int dailyCalories; 
    Macros macros; 
    std::vector<Meal> mealsPerDay; 

public:
    std::vector<Meal> generateDailyMeals();
    void adjustMacros(const Macros& newMacros);
    void trackIntake(const Meal& meal);
};

#endif