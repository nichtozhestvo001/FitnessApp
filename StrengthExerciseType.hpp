#pragma once
#include "ExerciseType.hpp"

class StrengthCalorieEstimator : public ICalorieEstimator {
public:
    int estimate(int baseCaloriesPerMin, int duration) override {
        return (baseCaloriesPerMin * 2) * duration;
    }
};

class StrengthExerciseType : public ExerciseType {
public:
    StrengthExerciseType(int intensity)
    {
        baseCaloriesPerMin = intensity;
        estimator = new StrengthCalorieEstimator();
    }
};
