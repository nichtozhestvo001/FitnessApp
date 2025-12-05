#ifndef FITNESSUSER_HPP
#define FITNESSUSER_HPP
#include <string>
#include "types.hpp"
#include <memory>
#include "FitnessEntity.hpp" 
class DerivedUser;
class FitnessUser : public FitnessEntity
{
public:
	FitnessUser() = default;
	FitnessUser(const std::string& id, const std::string& username, const std::string& email, const std::string& birthDate, Gender gender, double heightM, double currentWeight, ActivityLevel activityLevel);
	FitnessUser(const FitnessUser& other) = delete; 
	FitnessUser& operator=(const FitnessUser& other); 
	std::string getBirthDate() const;
	~FitnessUser() override { std::cout << "FitnessUser destructor" << std::endl; }
protected: 
	std::string id;
	std::string username;
	std::string email;
	std::string birthDate;
	Gender gender;
	double heightM;
	double currentWeight;
	ActivityLevel activityLevel;
private:
	static int totalUsers;
protected: 
	double getProtectedHeight() const { return heightM; }
public:
	double calculateBMI() const;
	void setNewWeight(double newWeight);
	int getRecommendedCalories() const;
	static int getTotalUsers();
	friend void printPrivateInfo(const FitnessUser& user);
	bool operator==(const FitnessUser& other) const;
	FitnessUser& operator+=(double weightDelta);
	friend std::ostream& operator<<(std::ostream& os, const FitnessUser& user);
	std::string getInfo() const override;
	FitnessEntity* clone() const override;
	double calculateSomething() const override { return currentWeight; } 
};
#endif