#ifndef EXERCISETYPE_HPP
#define EXERCISETYPE_HPP
#include <vector>
#include <set>
#include "types.hpp"
class FitnessUser;
class ExerciseType
{
public:
	ExerciseType() = default;
	~ExerciseType() = default;
private:
	std::string id;
	std::string title;
	Category category;
	std::set<Muscle> targetMuscles;
	std::set<Equipment> requiredEquipment;
protected:
	int baseCaloriesPerMin; 
public:
	virtual int estimateCalories(int duration);
	std::vector<ExerciseType> findSimilar(Category category);
	bool isCompatible(const FitnessUser& user);
	ExerciseType(const ExerciseType&) = default; 
	ExerciseType deepClone() const {
		ExerciseType clone = *this;
		clone.targetMuscles = targetMuscles;
		clone.requiredEquipment = requiredEquipment;
		return clone;
	}
};
#endif