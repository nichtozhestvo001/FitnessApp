#ifndef FITNESSENTITY_HPP
#define FITNESSENTITY_HPP
#include <string>
#include <iostream>
class FitnessEntity {
public:
	virtual ~FitnessEntity() { std::cout << "FitnessEntity destructor" << std::endl; } 
	virtual std::string getInfo() const = 0; 
	virtual FitnessEntity* clone() const = 0; 
	virtual double calculateSomething() const { return 0.0; } 
	void callVirtual() const { 
		std::cout << "Результат виртуального: " << calculateSomething() << std::endl;
	}
};
#endif