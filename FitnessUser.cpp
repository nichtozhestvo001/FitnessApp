#include "FitnessUser.hpp"

FitnessUser::FitnessUser(const std::string& id, const std::string& username, const std::string& email, const std::string& birthDate, Gender gender, double heightM, double currentWeight, ActivityLevel activityLevel)
    : id(id), username(username), email(email), birthDate(birthDate), gender(gender), heightM(heightM), currentWeight(currentWeight), activityLevel(activityLevel) {}

double FitnessUser::calculateBMI() const {
    if (heightM <= 0) return 0.0;
    return currentWeight / (heightM * heightM);
}

void FitnessUser::setNewWeight(double newWeight) {
    currentWeight = newWeight;
}

int FitnessUser::getRecommendedCalories() const {
    int base = 2000;
    if (activityLevel == ActivityLevel::High) base += 500;
    else if (activityLevel == ActivityLevel::Medium) base += 250;
    return base;
}