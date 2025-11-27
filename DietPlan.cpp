#include "DietPlan.hpp"
#include "Meal.hpp"

std::vector<Meal> DietPlan::generateDailyMeals() {
    return {}; 
}

void DietPlan::adjustMacros(const Macros& newMacros) {
    macros = newMacros;
}


void DietPlan::trackIntake(const Meal& meal) {
}