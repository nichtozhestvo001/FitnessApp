using System;
using System.Collections.Generic;

namespace FitnessApp
{
    public class CardioExerciseType : ExerciseType
    {
        protected double distanceKm;

        public CardioExerciseType()
        {
            calorieEstimator = new CardioCalorieEstimator();
        }
    }
}