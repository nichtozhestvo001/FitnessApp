#include "TrainingProgram.hpp"
#include "Session.hpp"
#include "ExerciseType.hpp"
#include "FitnessUser.hpp"

// Генерация расписания на неделю
std::vector<Session> TrainingProgram::generateWeeklySchedule() {
    std::vector<Session> schedule;
    // Заглушка: создание сессий по частоте
    for (int i = 0; i < frequency; ++i) {
        Session s;
        schedule.push_back(s);
    }
    return schedule;
}

// Адаптация программы под пользователя
void TrainingProgram::adjustForUser(const FitnessUser& user) {
    // Заглушка: изменение сложности или типов упражнений
}

// Добавление типа упражнения
void TrainingProgram::addExerciseType(const ExerciseType& newType) {
    exerciseTypes.push_back(newType);
}