#include <iostream>
#include <memory>
#include <stdexcept>
#include <windows.h>

#include "FitnessUser.hpp"
#include "GoalSetting.hpp"
#include "DerivedUser.hpp"
#include "ExerciseType.hpp"
#include "CardioExerciseType.hpp"
#include "StrengthExerciseType.hpp"
#include "FitnessEntity.hpp"

int main() {
    SetConsoleOutputCP(1251);

    DerivedUser du("4", "du", "email", "date", Gender::Male, 1.8, 80.0, ActivityLevel::Medium, "info");
    std::cout << "Инфо derived: " << du.getInfo() << std::endl;

    CardioExerciseType cardio(5.0);
    std::cout << "Калории кардио: " << cardio.estimateCalories(10) << std::endl;

    StrengthExerciseType strength(10);
    std::cout << "Калории силовых: " << strength.estimateCalories(10) << std::endl;

    FitnessEntity* ent = new DerivedUser("5", "du2", "email", "date", Gender::Male, 1.8, 90.0, ActivityLevel::Medium, "info2");
    ent->callVirtual();
    std::cout << "Полиморфизм: " << ent->calculateSomething() << std::endl;
    delete ent;

    ExerciseType et;
    ExerciseType shallow = et;
    ExerciseType deep = et.deepClone();
    std::cout << "Клоны созданы" << std::endl;

    FitnessUser baseUser("6", "base", "email", "date", Gender::Male, 1.8, 80.0, ActivityLevel::Medium);
    du = baseUser;
    std::cout << "Присваивание от base: " << du.getInfo() << std::endl;

    std::cout << "\n=== Демонстрация делегирования ===\n";

    CardioExerciseType cardio2(5.0);
    cardio2.setBaseCaloriesPerMin(5);
    std::cout << "Статическое кардио (30 мин): " << cardio2.estimateCalories(30) << std::endl;

    StrengthExerciseType strength2(12);
    strength2.setBaseCaloriesPerMin(4);
    std::cout << "Статическое силовое (30 мин): " << strength2.estimateCalories(30) << std::endl;

    ExerciseType baseExercise;
    baseExercise.setBaseCaloriesPerMin(3);

    std::cout << "Базовое без делегата (30 мин): "
        << baseExercise.estimateCalories(30) << std::endl;

    baseExercise.setCalorieEstimator(new CardioCalorieEstimator());
    std::cout << "Динамическое кардио (30 мин): "
        << baseExercise.estimateCalories(30) << std::endl;

    baseExercise.setCalorieEstimator(new StrengthCalorieEstimator());
    std::cout << "Динамическое силовое (30 мин): "
        << baseExercise.estimateCalories(30) << std::endl;

    return 0;
}
