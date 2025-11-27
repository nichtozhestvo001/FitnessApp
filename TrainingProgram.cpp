#include "TrainingProgram.hpp"
#include "Session.hpp"
#include "ExerciseType.hpp"
#include "FitnessUser.hpp"

std::vector<Session> TrainingProgram::generateWeeklySchedule() {
    std::vector<Session> schedule;
    for (int i = 0; i < frequency; ++i) {
        Session s;
        schedule.push_back(s);
    }
    return schedule;
}

void TrainingProgram::adjustForUser(const FitnessUser& user) {
}


void TrainingProgram::addExerciseType(const ExerciseType& newType) {
    exerciseTypes.push_back(newType);
}