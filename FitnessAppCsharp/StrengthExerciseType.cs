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
        }

        public override int EstimateCalories(int duration)
        {
            return base.EstimateCalories(duration) + reps * 5;
        }
    }
}