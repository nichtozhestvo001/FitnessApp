#ifndef EXERCISETYPE_HPP
#define EXERCISETYPE_HPP

#include <vector>
#include <set>
#include "types.hpp"

class FitnessUser;

class ExerciseType
{
public:
    ExerciseType() = default;
    ~ExerciseType() = default;

private:
    std::string id; // Идентификатор упражнения
    std::string title; // Название
    Category category; // Категория (кардио, силовые, йога)
    std::set<Muscle> targetMuscles; // Целевые мышцы
    std::set<Equipment> requiredEquipment; // Необходимое оборудование
    int baseCaloriesPerMin; // Базовые калории за минуту

public:
    // Оценка сожженных калорий
    int estimateCalories(int duration);
    // Поиск похожих упражнений
    std::vector<ExerciseType> findSimilar(Category category);
    // Проверка совместимости с пользователем
    bool isCompatible(const FitnessUser& user);
};

#endif