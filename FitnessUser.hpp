#ifndef FITNESSUSER_HPP
#define FITNESSUSER_HPP

#include <string>
#include "types.hpp"

class FitnessUser
{
public:
    FitnessUser() = default;
    FitnessUser(const std::string& id, const std::string& username, const std::string& email, const std::string& birthDate, Gender gender, double heightM, double currentWeight, ActivityLevel activityLevel);
    ~FitnessUser() = default;

private:
    std::string id;
    std::string username;
    std::string email;
    std::string birthDate;
    Gender gender;
    double heightM;
    double currentWeight;
    ActivityLevel activityLevel;

public:
    double calculateBMI() const;
    void setNewWeight(double newWeight);
    int getRecommendedCalories() const;
};

#endif
