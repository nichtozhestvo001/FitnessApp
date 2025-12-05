#include <iostream>
#include <memory>
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

	// Демонстрация для лабораторной
	// Производные классы

	DerivedUser du("4", "du", "email", "date", Gender::Male, 1.8, 80.0, ActivityLevel::Medium, "info");
	std::cout << "Инфо derived: " << du.getInfo() << std::endl;

	CardioExerciseType cardio(5.0);
	std::cout << "Калории кардио (protected): " << cardio.estimateCalories(10) << std::endl;

	StrengthExerciseType strength(10);
	std::cout << "Калории strength (с base): " << strength.estimateCalories(10) << std::endl;
	std::cout << "Калории cardio (без base): " << cardio.estimateCalories(10) << std::endl;

	// Виртуальные функции

	FitnessEntity* ent = new DerivedUser("5", "du2", "email", "date", Gender::Male, 1.8, 90.0, ActivityLevel::Medium, "info2");
	ent->callVirtual(); 
	std::cout << "Полиморфизм: " << ent->calculateSomething() << std::endl;
	// Без virtual calculateSomething: вызовет base версию (0.0)
	delete ent; // Вызовет derived и base деструкторы благодаря virtual ~

	// Клонирование

	ExerciseType et;
	ExerciseType shallow = et; 
	ExerciseType deep = et.deepClone();
	std::cout << "Клоны созданы" << std::endl;
	// Абстрактный класс
	// FitnessEntity* absEnt = new FitnessEntity(); // Ошибка, abstract

	FitnessUser baseUser("6", "base", "email", "date", Gender::Male, 1.8, 80.0, ActivityLevel::Medium);
	du = baseUser;
	std::cout << "Присваивание от base: " << du.getInfo() << std::endl;
	return 0;
}