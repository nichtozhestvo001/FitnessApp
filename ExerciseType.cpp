#include "ExerciseType.hpp"
#include "FitnessUser.hpp"

// Оценка калорий
int ExerciseType::estimateCalories(int duration) {
    return baseCaloriesPerMin * duration;
}

// Поиск похожих упражнений
std::vector<ExerciseType> ExerciseType::findSimilar(Category category) {
    return {}; // Заглушка: требует базы данных
}

// Проверка совместимости
bool ExerciseType::isCompatible(const FitnessUser& user) {
    return true; // Заглушка
}