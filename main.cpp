#include <iostream>
#include <memory>
#include <stdexcept>
#include <windows.h>
#include "FitnessUser.hpp"
#include "GoalSetting.hpp"
#include "DerivedUser.hpp"

int main() {

    SetConsoleOutputCP(1251);

    try {
        std::unique_ptr<FitnessUser> uniqueUser = std::make_unique<FitnessUser>("1", "user1", "email", "date", Gender::Male, 1.8, 80.0, ActivityLevel::Medium);
        std::shared_ptr<FitnessUser> sharedUser = std::make_shared<FitnessUser>(*uniqueUser); 
        std::cout << "Смарт-указатели: BMI = " << sharedUser->calculateBMI() << std::endl;


        std::cout << "Статическое поле: Всего пользователей = " << FitnessUser::getTotalUsers() << std::endl;

        uniqueUser->setNewWeight(-10);
    }
    catch (const std::exception& ex) {
        std::cerr << "Перехвачено исключение: " << ex.what() << std::endl;
    }

    FitnessUser user("2", "user2", "email", "date", Gender::Female, 1.65, 60.0, ActivityLevel::High);
    printPrivateInfo(user);

    if (user == FitnessUser(user)) std::cout << "Оператор ==: Равны" << std::endl;
    user += 5.0; 
    std::cout << user << std::endl;

    std::string str = std::string("Дата: ") + user.getBirthDate();
    std::cout << str << std::endl;

    DerivedUser derived("3", "derived", "email", "date", Gender::Male, 1.7, 70.0, ActivityLevel::Low, "Доп. инфо");
    DerivedUser copyDerived(derived); 
    std::cout << "Наследование: Доп. инфо = " << copyDerived.getAdditionalInfo() << std::endl;

    GoalSetting goal("g1", "1", GoalType::WeightLoss, 70.0, "start", "end");
    GoalSetting combined = goal + goal; 
    std::cout << "Оператор +: Комбинированное значение = " << combined[0] << std::endl;

    return 0;
}