#include "ExerciseType.hpp"
#include "FitnessUser.hpp"

int ExerciseType::estimateCalories(int duration) {
    if (estimator) {
        return estimator->estimate(baseCaloriesPerMin, duration);
    }
    return baseCaloriesPerMin * duration;
}

std::vector<ExerciseType> ExerciseType::findSimilar(Category category) {
    return {};
}

bool ExerciseType::isCompatible(const FitnessUser& user) {
    return true;
}
