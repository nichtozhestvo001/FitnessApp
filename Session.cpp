#include "Session.hpp"

// Начало сессии
void Session::startSession() {
    // Заглушка: фиксация времени начала
    actualDuration = 0;
}

// Логирование упражнения
void Session::logExercise(const ExerciseLog& exercise) {
    completedExercises.push_back(exercise);
}

// Завершение сессии
void Session::completeSession() {
    // Заглушка: расчет калорий
    burnedCalories = completedExercises.size() * 100;
}

// Получение сожженных калорий
int Session::getBurnedCalories() const {
    return burnedCalories;
}