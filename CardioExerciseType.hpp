#ifndef CARDIOEXERCISETYPE_HPP
#define CARDIOEXERCISETYPE_HPP
#include "ExerciseType.hpp"
class CardioExerciseType : public ExerciseType {
public:
	CardioExerciseType(double d) : distance(d) {}
	int estimateCalories(int duration) override { 
		return static_cast<int>(duration * 10 + baseCaloriesPerMin); 
	}
private:
	double distance;
};
#endif