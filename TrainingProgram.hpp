
#ifndef TRAININGPROGRAM_HPP
#define TRAININGPROGRAM_HPP

#include <vector>
#include "types.hpp"

class Session;
class ExerciseType;
class FitnessUser;

class TrainingProgram
{
public:
    TrainingProgram() = default;
    ~TrainingProgram() = default;

private:
    std::string id; 
    std::string name; 
    int durationWeeks; 
    int frequency; 
    std::vector<ExerciseType> exerciseTypes; 
    Difficulty difficulty; 

public:
    std::vector<Session> generateWeeklySchedule();
    void adjustForUser(const FitnessUser& user);
    void addExerciseType(const ExerciseType& newType);
};

#endif
