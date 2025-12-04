using System;
using System.Collections.Generic;

namespace FitnessApp
{
    public class CardioExerciseType : ExerciseType
    {
        protected double distanceKm; 

        public CardioExerciseType() 
        {
        }

        public override int EstimateCalories(int duration)
        {
            return (int)(duration * 10 + baseCaloriesPerMin);
        }
    }
}
