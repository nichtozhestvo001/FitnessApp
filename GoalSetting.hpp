#ifndef GOALSETTING_HPP
#define GOALSETTING_HPP

#include "types.hpp"

class GoalSetting
{
public:
    GoalSetting() = default;
    GoalSetting(const std::string& id, const std::string& userId, GoalType goalType, double targetValue, const std::string& startDate, const std::string& deadline);
    ~GoalSetting() = default;

private:
    std::string id; // Идентификатор цели
    std::string userId; // Идентификатор пользователя
    GoalType goalType; // Тип цели
    double targetValue; // Целевое значение (например, вес)
    std::string startDate; // Дата начала
    std::string deadline; // Срок достижения
    double initialValue; // Начальное значение для расчета прогресса

public:
    // Обновляет прогресс и возвращает процент выполнения
    double updateProgress(double currentValue);
    // Проверяет, достигнута ли цель
    bool isAchieved();
    // Продлевает срок достижения
    void extendDeadline(const std::string& newDate);
    // Устанавливает начальное значение
    void setInitialValue(double val);
};

#endif