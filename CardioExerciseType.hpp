#pragma once
#include "ExerciseType.hpp"

class CardioCalorieEstimator : public ICalorieEstimator {
public:
    int estimate(int baseCaloriesPerMin, int duration) override {
        return (baseCaloriesPerMin + 3) * duration;
    }
};

class CardioExerciseType : public ExerciseType {
public:
    CardioExerciseType(double intensity)
    {
        baseCaloriesPerMin = intensity;
        estimator = new CardioCalorieEstimator();
    }
};
