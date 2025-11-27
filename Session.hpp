#ifndef SESSION_HPP
#define SESSION_HPP

#include <vector>
#include "types.hpp"

class Session
{
public:
    Session() = default;
    ~Session() = default;

private:
    std::string id; 
    std::string programId; 
    std::string scheduledDate; 
    int actualDuration; 
    int burnedCalories; 
    std::vector<ExerciseLog> completedExercises; 

public:
    void startSession();
    void logExercise(const ExerciseLog& exercise);
    void completeSession();
    int getBurnedCalories() const;
};

#endif
