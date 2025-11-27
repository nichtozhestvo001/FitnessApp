#include "Session.hpp"


void Session::startSession() {

    actualDuration = 0;
}


void Session::logExercise(const ExerciseLog& exercise) {
    completedExercises.push_back(exercise);
}


void Session::completeSession() {
    burnedCalories = completedExercises.size() * 100;
}


int Session::getBurnedCalories() const {
    return burnedCalories;
}