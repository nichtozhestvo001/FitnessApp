#include "GoalSetting.hpp"

// Конструктор с параметрами
GoalSetting::GoalSetting(const std::string& id, const std::string& userId, GoalType goalType, double targetValue, const std::string& startDate, const std::string& deadline)
    : id(id), userId(userId), goalType(goalType), targetValue(targetValue), startDate(startDate), deadline(deadline), initialValue(0.0) {}

// Обновление прогресса
double GoalSetting::updateProgress(double currentValue) {
    if (initialValue == 0.0) return 0.0; // Проверка на валидность
    double progress = 0.0;
    if (goalType == GoalType::WeightLoss) { // Для снижения веса
        progress = (initialValue - currentValue) / (initialValue - targetValue) * 100.0;
    } // Добавить логику для других типов целей
    return progress;
}

// Проверка достижения цели
bool GoalSetting::isAchieved() {
    return false; // Заглушка, требует сравнения текущего значения
}

// Продление срока
void GoalSetting::extendDeadline(const std::string& newDate) {
    deadline = newDate;
}

// Установка начального значения
void GoalSetting::setInitialValue(double val) {
    initialValue = val;
}