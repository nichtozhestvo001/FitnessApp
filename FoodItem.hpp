#ifndef FOODITEM_HPP
#define FOODITEM_HPP

#include <set>
#include "types.hpp"

class FoodItem
{
public:
    FoodItem() = default;
    // Конструктор с параметрами
    FoodItem(const std::string& id, const std::string& name, int caloriesPer100g, double proteinPer100g, double carbsPer100g, double fatsPer100g);
    ~FoodItem() = default;

private:
    std::string id; // Идентификатор продукта
    std::string name; // Название
    int caloriesPer100g; // Калории на 100 г
    double proteinPer100g; // Белки на 100 г
    double carbsPer100g; // Углеводы на 100 г
    double fatsPer100g; // Жиры на 100 г

public:
    // Расчет нутриентов для заданного веса
    Nutrition getNutrition(double amountG) const;
    // Проверка на отсутствие аллергенов
    bool isAllergenFree(const std::set<Allergen>& allergens) const;
};

#endif