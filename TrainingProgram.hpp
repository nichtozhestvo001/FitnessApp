// TrainingProgram.hpp
// Описание класса для программы тренировок
#ifndef TRAININGPROGRAM_HPP
#define TRAININGPROGRAM_HPP

#include <vector>
#include "types.hpp"

class Session;
class ExerciseType;
class FitnessUser;

class TrainingProgram
{
public:
    TrainingProgram() = default;
    ~TrainingProgram() = default;

private:
    std::string id; // ID
    std::string name; // Название программы
    int durationWeeks; // Продолжительность в неделях
    int frequency; // Количество сессий в неделю
    std::vector<ExerciseType> exerciseTypes; // Список типов упражнений
    Difficulty difficulty; // Уровень сложности

public:
    // Генерирует расписание на неделю
    std::vector<Session> generateWeeklySchedule();
    // Адаптирует программу под пользователя
    void adjustForUser(const FitnessUser& user);
    // Добавляет новый тип упражнения
    void addExerciseType(const ExerciseType& newType);
};

#endif
