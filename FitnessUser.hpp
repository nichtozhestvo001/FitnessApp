#ifndef FITNESSUSER_HPP
#define FITNESSUSER_HPP

#include <string>
#include "types.hpp"
#include <memory>

class DerivedUser;

class FitnessUser
{
public:
    FitnessUser() = default;
    FitnessUser(const std::string& id, const std::string& username, const std::string& email, const std::string& birthDate, Gender gender, double heightM, double currentWeight, ActivityLevel activityLevel);
    FitnessUser(const FitnessUser& other);
    std::string getBirthDate() const;
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

    static int totalUsers;

public:
    double calculateBMI() const;
    void setNewWeight(double newWeight);
    int getRecommendedCalories() const;

    static int getTotalUsers(); 

    friend void printPrivateInfo(const FitnessUser& user); 

    bool operator==(const FitnessUser& other) const;
    FitnessUser& operator+=(double weightDelta);
    friend std::ostream& operator<<(std::ostream& os, const FitnessUser& user);
};

#endif