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
    std::string id; // Идентификатор плана
    std::string userId; // Идентификатор пользователя
    int dailyCalories; // Суточные калории
    Macros macros; // Макронутриенты
    std::vector<Meal> mealsPerDay; // Список приемов пищи

public:
    // Генерация блюд на день
    std::vector<Meal> generateDailyMeals();
    // Обновление макронутриентов
    void adjustMacros(const Macros& newMacros);
    // Отслеживание потребления
    void trackIntake(const Meal& meal);
};

#endif