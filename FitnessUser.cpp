#include "FitnessUser.hpp"
#include <stdexcept> 
#include <iostream>

int FitnessUser::totalUsers = 0;

FitnessUser::FitnessUser(const std::string& id, const std::string& username, const std::string& email, const std::string& birthDate, Gender gender, double heightM, double currentWeight, ActivityLevel activityLevel)
    : id(id), username(username), email(email), birthDate(birthDate), gender(gender), heightM(heightM), currentWeight(currentWeight), activityLevel(activityLevel)
{
    totalUsers++;
    if (this->heightM <= 0) throw std::invalid_argument("Рост должен быть положительным"); 
}

FitnessUser::FitnessUser(const FitnessUser& other)
    : id(other.id), username(other.username), email(other.email), birthDate(other.birthDate), gender(other.gender), heightM(other.heightM), currentWeight(other.currentWeight), activityLevel(other.activityLevel)
{
    totalUsers++; 
}

double FitnessUser::calculateBMI() const {
    try {
        if (this->heightM <= 0) throw std::invalid_argument("Рост должен быть положительным");
        return this->currentWeight / (this->heightM * this->heightM); 
    }
    catch (const std::invalid_argument& ex) {
        std::cerr << "Ошибка ИМТ: " << ex.what() << std::endl;
        return 0.0;
    }
}

void FitnessUser::setNewWeight(double newWeight) {
    if (newWeight <= 0) throw std::invalid_argument("Вес должен быть положительным");
    this->currentWeight = newWeight;
}

int FitnessUser::getRecommendedCalories() const {
    int base = 2000;
    if (this->activityLevel == ActivityLevel::High) base += 500;
    else if (this->activityLevel == ActivityLevel::Medium) base += 250;
    return base;
}

int FitnessUser::getTotalUsers() {
    return totalUsers; 
}

void printPrivateInfo(const FitnessUser& user) {
    std::cout << "Приватная информация (friend): ID = " << user.id << std::endl; 
}

bool FitnessUser::operator==(const FitnessUser& other) const {
    return this->id == other.id; 
}

FitnessUser& FitnessUser::operator+=(double weightDelta) {
    this->currentWeight += weightDelta; 
    return *this;
}

std::ostream& operator<<(std::ostream& os, const FitnessUser& user) {
    os << "Пользователь: " << user.username; 
    return os;
}

std::string FitnessUser::getBirthDate() const {
    return this->birthDate;
}