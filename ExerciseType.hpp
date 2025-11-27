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
    int baseCaloriesPerMin; 

public:
    int estimateCalories(int duration);
    std::vector<ExerciseType> findSimilar(Category category);
    bool isCompatible(const FitnessUser& user);
};

#endif