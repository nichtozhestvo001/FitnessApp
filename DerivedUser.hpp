#ifndef DERIVEDUSER_HPP
#define DERIVEDUSER_HPP

#include "FitnessUser.hpp"

class DerivedUser : public FitnessUser {
public:
    DerivedUser(const std::string& id, const std::string& username, const std::string& email, const std::string& birthDate, Gender gender, double heightM, double currentWeight, ActivityLevel activityLevel, std::string additionalInfo)
        : FitnessUser(id, username, email, birthDate, gender, heightM, currentWeight, activityLevel), additionalInfo(additionalInfo) {}

    DerivedUser(const DerivedUser& other) : FitnessUser(other), additionalInfo(other.additionalInfo) {}

private:
    std::string additionalInfo;

public:
    std::string getAdditionalInfo() const { return this->additionalInfo; }
};

#endif