#ifndef SESSION_HPP
#define SESSION_HPP

#include <vector>
#include "types.hpp"

class Session
{
public:
    Session() = default;
    ~Session() = default;

private:
    std::string id; // Идентификатор сессии
    std::string programId; // Идентификатор программы
    std::string scheduledDate; // Запланированная дата
    int actualDuration; // Фактическая длительность в минутах
    int burnedCalories; // Сожженные калории
    std::vector<ExerciseLog> completedExercises; // Лог выполненных упражнений

public:
    // Начинает сессию
    void startSession();
    // Логирует выполненное упражнение
    void logExercise(const ExerciseLog& exercise);
    // Завершает сессию
    void completeSession();
    // Возвращает сожженные калории
    int getBurnedCalories() const;
};

#endif
