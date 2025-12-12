#pragma once
#include <vector>

class FitnessUser;

class ICalorieEstimator {
public:
    virtual int estimate(int baseCaloriesPerMin, int duration) = 0;
    virtual ~ICalorieEstimator() {}
};

enum class Category {
    Cardio,
    Strength,
    Other
};

class ExerciseType {
protected:
    int baseCaloriesPerMin = 1;

    ICalorieEstimator* estimator = nullptr;

public:
    ExerciseType() = default;

    void setBaseCaloriesPerMin(int value) { baseCaloriesPerMin = value; }
    void setCalorieEstimator(ICalorieEstimator* e) { estimator = e; }
    virtual int estimateCalories(int duration);

    std::vector<ExerciseType> findSimilar(Category category);
    bool isCompatible(const FitnessUser& user);

    ExerciseType deepClone() {
        ExerciseType copy;
        copy.baseCaloriesPerMin = baseCaloriesPerMin;
        copy.estimator = estimator;
        return copy;
    }
};
