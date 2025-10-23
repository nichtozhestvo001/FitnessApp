#include <iostream>
#include <vector>
#include <windows.h>
#include "FitnessUser.hpp"
#include "GoalSetting.hpp"
#include "Session.hpp"
#include "FoodItem.hpp"
#include "ReminderSystem.hpp"

int main() {
    SetConsoleOutputCP(1251);
    // 1. Статическая инициализация объектов
    std::cout << "Тест 1: Статическая инициализация\n";
    FitnessUser staticUser("1", "user1", "user1@gmail.com", "2000-01-01", Gender::Male, 1.8, 80.0, ActivityLevel::Medium);
    std::cout << "  Статический FitnessUser создан, BMI: " << staticUser.calculateBMI() << " (ожидается ~24.69)\n";
    std::cout << "  Рекомендуемые калории: " << staticUser.getRecommendedCalories() << " (ожидается 2250)\n";

    // 2. Динамическая инициализация с new/delete
    std::cout << "\nТест 2: Динамическая инициализация\n";
    FitnessUser* dynamicUser = new FitnessUser("2", "user2", "user1@gmail.com", "1995-05-05", Gender::Female, 1.65, 60.0, ActivityLevel::High); // Полная инициализация
    std::cout << "  Динамический FitnessUser создан, BMI: " << dynamicUser->calculateBMI() << " (ожидается ~22.04)\n";
    std::cout << "  Рекомендуемые калории: " << dynamicUser->getRecommendedCalories() << " (ожидается 2500)\n";
    delete dynamicUser; // Освобождение памяти
    std::cout << "  Динамический объект удалён\n";

    // 3. Работа с ссылками
    std::cout << "\nТест 3: Работа с ссылками\n";
    GoalSetting goal("g1", "1", GoalType::WeightLoss, 70.0, "2025-10-01", "2025-12-31");
    goal.setInitialValue(80.0); // Установка начального значения для прогресса
    GoalSetting& goalRef = goal; // Ссылка на объект
    goalRef.extendDeadline("2026-01-31");
    std::cout << "  Ссылка на GoalSetting: срок продлён, прогресс: " << goalRef.updateProgress(75.0) << " (ожидается 50)\n";

    // 4. Работа с указателями
    std::cout << "\nТест 4: Работа с указателями\n";
    ReminderSystem reminderSystem;
    ReminderSystem* reminderPtr = &reminderSystem;
    Reminder r{ "r1", "10:00", "Время тренировки" };
    reminderPtr->setReminder(r);
    std::cout << "  Указатель на ReminderSystem: напоминание добавлено\n";
    reminderPtr->cancelReminder("r1");
    std::cout << "  Указатель на ReminderSystem: напоминание удалено\n";

    // 5. Динамический массив объектов
    std::cout << "\nТест 5: Динамический массив объектов\n";
    Session* sessionArray = new Session[3]; // Динамический массив из 3 сессий
    // Первая сессия: 2 упражнения
    sessionArray[0].startSession();
    sessionArray[0].logExercise({ "ex1", 10, 12, 20.0 }); // Первое упражнение
    sessionArray[0].logExercise({ "ex2", 15, 10, 15.0 }); // Второе упражнение
    sessionArray[0].completeSession();
    std::cout << "  Динамический массив Session: калории первой сессии: " << sessionArray[0].getBurnedCalories() << " (ожидается 200)\n";
    // Вторая сессия: 3 упражнения
    sessionArray[1].startSession();
    sessionArray[1].logExercise({ "ex3", 12, 15, 25.0 }); // Первое упражнение
    sessionArray[1].logExercise({ "ex4", 20, 8, 30.0 }); // Второе упражнение
    sessionArray[1].logExercise({ "ex5", 10, 10, 10.0 }); // Третье упражнение
    sessionArray[1].completeSession();
    std::cout << "  Динамический массив Session: калории второй сессии: " << sessionArray[1].getBurnedCalories() << " (ожидается 300)\n";
    delete[] sessionArray;
    std::cout << "  Динамический массив удалён\n";

    // 6. Массив динамических объектов
    std::cout << "\nТест 6: Массив динамических объектов\n";
    std::vector<FoodItem*> foodVector;
    foodVector.push_back(new FoodItem("f1", "Apple", 52, 0.3, 13.8, 0.2));
    foodVector.push_back(new FoodItem("f2", "Banana", 89, 1.1, 22.8, 0.3));
    std::cout << "  Массив FoodItem: добавлено " << foodVector.size() << " объекта\n";
    for (auto* item : foodVector) {
        Nutrition n = item->getNutrition(150.0);
        std::cout << "  Калории для 150 г: " << n.calories << " (ожидается 78 для Apple или 133 для Banana)\n";
        delete item;
    }
    std::cout << "  Массив динамических объектов очищен\n";

    return 0;
}