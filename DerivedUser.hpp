#ifndef DERIVEDUSER_HPP
#define DERIVEDUSER_HPP
#include "FitnessUser.hpp"
class DerivedUser : public FitnessUser {
public:
	DerivedUser(const std::string& id, const std::string& username, const std::string& email, const std::string& birthDate, Gender gender, double heightM, double currentWeight, ActivityLevel activityLevel, std::string additionalInfo)
		: FitnessUser(id, username, email, birthDate, gender, heightM, currentWeight, activityLevel), additionalInfo(additionalInfo) {} 
	DerivedUser(const DerivedUser& other) = delete;
	~DerivedUser() override { std::cout << "DerivedUser destructor" << std::endl; }
private:
	std::string additionalInfo;
public:
	std::string getAdditionalInfo() const { return this->additionalInfo; }
	double calculateSomething() const override { return FitnessUser::calculateSomething() + 10; }
	DerivedUser& operator=(const FitnessUser& base) { 
		if (this != &base) {
			FitnessUser::operator=(base);
			additionalInfo = "default";
		}
		return *this;
	}
	FitnessEntity* clone() const override {
		return new DerivedUser(id, username, email, birthDate, gender, heightM, currentWeight, activityLevel, additionalInfo);
	}
};
#endif