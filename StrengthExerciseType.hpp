#ifndef STRENGTHEXERCISETYPE_HPP
#define STRENGTHEXERCISETYPE_HPP
#include "ExerciseType.hpp"

class StrengthExerciseType : 
	public ExerciseType {
		public:
			StrengthExerciseType(int r) : reps(r) {}
			int estimateCalories(int duration) override { 
			return ExerciseType::estimateCalories(duration) + reps * 5;
	}
	private:
		int reps;
};
#endif