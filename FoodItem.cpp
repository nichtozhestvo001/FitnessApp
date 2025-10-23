#include "FoodItem.hpp"

// ����������� � �����������
FoodItem::FoodItem(const std::string& id, const std::string& name, int caloriesPer100g, double proteinPer100g, double carbsPer100g, double fatsPer100g)
    : id(id), name(name), caloriesPer100g(caloriesPer100g), proteinPer100g(proteinPer100g), carbsPer100g(carbsPer100g), fatsPer100g(fatsPer100g) {}

// ������ ����������
Nutrition FoodItem::getNutrition(double amountG) const {
    Nutrition n;
    double factor = amountG / 100.0; // ����������� ��� �����
    n.calories = static_cast<int>(caloriesPer100g * factor);
    n.protein = proteinPer100g * factor;
    n.carbs = carbsPer100g * factor;
    n.fats = fatsPer100g * factor;
    return n;
}

// �������� �� ���������
bool FoodItem::isAllergenFree(const std::set<Allergen>& allergens) const {
    return true; // ��������, ���� ���������� �����������
}