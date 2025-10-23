#include "Meal.hpp"
#include "FoodItem.hpp"

// Добавление продукта
void Meal::addFoodItem(const FoodItem& item) {
    foodItems.push_back(item);
}

// Пересчет калорий и нутриентов
void Meal::calculateTotals() {
    totalCalories = 0; // Заглушка: сумма по продуктам
}

// Замена продукта
void Meal::substituteItem(const FoodItem& oldItem, const FoodItem& newItem) {
    // Заглушка: найти и заменить
}