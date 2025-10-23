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
    // 1. ����������� ������������� ��������
    std::cout << "���� 1: ����������� �������������\n";
    FitnessUser staticUser("1", "user1", "user1@gmail.com", "2000-01-01", Gender::Male, 1.8, 80.0, ActivityLevel::Medium);
    std::cout << "  ����������� FitnessUser ������, BMI: " << staticUser.calculateBMI() << " (��������� ~24.69)\n";
    std::cout << "  ������������� �������: " << staticUser.getRecommendedCalories() << " (��������� 2250)\n";

    // 2. ������������ ������������� � new/delete
    std::cout << "\n���� 2: ������������ �������������\n";
    FitnessUser* dynamicUser = new FitnessUser("2", "user2", "user1@gmail.com", "1995-05-05", Gender::Female, 1.65, 60.0, ActivityLevel::High); // ������ �������������
    std::cout << "  ������������ FitnessUser ������, BMI: " << dynamicUser->calculateBMI() << " (��������� ~22.04)\n";
    std::cout << "  ������������� �������: " << dynamicUser->getRecommendedCalories() << " (��������� 2500)\n";
    delete dynamicUser; // ������������ ������
    std::cout << "  ������������ ������ �����\n";

    // 3. ������ � ��������
    std::cout << "\n���� 3: ������ � ��������\n";
    GoalSetting goal("g1", "1", GoalType::WeightLoss, 70.0, "2025-10-01", "2025-12-31");
    goal.setInitialValue(80.0); // ��������� ���������� �������� ��� ���������
    GoalSetting& goalRef = goal; // ������ �� ������
    goalRef.extendDeadline("2026-01-31");
    std::cout << "  ������ �� GoalSetting: ���� ������, ��������: " << goalRef.updateProgress(75.0) << " (��������� 50)\n";

    // 4. ������ � �����������
    std::cout << "\n���� 4: ������ � �����������\n";
    ReminderSystem reminderSystem;
    ReminderSystem* reminderPtr = &reminderSystem;
    Reminder r{ "r1", "10:00", "����� ����������" };
    reminderPtr->setReminder(r);
    std::cout << "  ��������� �� ReminderSystem: ����������� ���������\n";
    reminderPtr->cancelReminder("r1");
    std::cout << "  ��������� �� ReminderSystem: ����������� �������\n";

    // 5. ������������ ������ ��������
    std::cout << "\n���� 5: ������������ ������ ��������\n";
    Session* sessionArray = new Session[3]; // ������������ ������ �� 3 ������
    // ������ ������: 2 ����������
    sessionArray[0].startSession();
    sessionArray[0].logExercise({ "ex1", 10, 12, 20.0 }); // ������ ����������
    sessionArray[0].logExercise({ "ex2", 15, 10, 15.0 }); // ������ ����������
    sessionArray[0].completeSession();
    std::cout << "  ������������ ������ Session: ������� ������ ������: " << sessionArray[0].getBurnedCalories() << " (��������� 200)\n";
    // ������ ������: 3 ����������
    sessionArray[1].startSession();
    sessionArray[1].logExercise({ "ex3", 12, 15, 25.0 }); // ������ ����������
    sessionArray[1].logExercise({ "ex4", 20, 8, 30.0 }); // ������ ����������
    sessionArray[1].logExercise({ "ex5", 10, 10, 10.0 }); // ������ ����������
    sessionArray[1].completeSession();
    std::cout << "  ������������ ������ Session: ������� ������ ������: " << sessionArray[1].getBurnedCalories() << " (��������� 300)\n";
    delete[] sessionArray;
    std::cout << "  ������������ ������ �����\n";

    // 6. ������ ������������ ��������
    std::cout << "\n���� 6: ������ ������������ ��������\n";
    std::vector<FoodItem*> foodVector;
    foodVector.push_back(new FoodItem("f1", "Apple", 52, 0.3, 13.8, 0.2));
    foodVector.push_back(new FoodItem("f2", "Banana", 89, 1.1, 22.8, 0.3));
    std::cout << "  ������ FoodItem: ��������� " << foodVector.size() << " �������\n";
    for (auto* item : foodVector) {
        Nutrition n = item->getNutrition(150.0);
        std::cout << "  ������� ��� 150 �: " << n.calories << " (��������� 78 ��� Apple ��� 133 ��� Banana)\n";
        delete item;
    }
    std::cout << "  ������ ������������ �������� ������\n";

    return 0;
}