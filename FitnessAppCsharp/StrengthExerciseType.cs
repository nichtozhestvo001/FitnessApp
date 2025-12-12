using System;
using System.Collections.Generic;

namespace FitnessApp
{
    public class StrengthExerciseType : ExerciseType
    {
        public int reps;

        public StrengthExerciseType()
        {
            reps = 0;
            calorieEstimator = new StrengthCalorieEstimator();
        }
    }
}