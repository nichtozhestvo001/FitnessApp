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
    std::string id; // Идентификатор приема пищи
    std::string dietId; // Идентификатор плана питания
    std::string mealTime; // Время приема
    std::vector<FoodItem> foodItems; // Список продуктов
    int totalCalories; // Общие калории
    Nutrition nutrition; // Нутриенты

public:
    // Добавление продукта
    void addFoodItem(const FoodItem& item);
    // Пересчет итогов
    void calculateTotals();
    // Замена продукта
    void substituteItem(const FoodItem& oldItem, const FoodItem& newItem);
};

#endif