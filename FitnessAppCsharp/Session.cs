using System;
using System.Collections.Generic;

namespace FitnessApp
{
    public class Session
    {
        private string id;
        private string programId;
        private string scheduledDate;
        private int actualDuration;
        private int burnedCalories;
        private List<ExerciseLog> completedExercises = new List<ExerciseLog>();

        public void StartSession()
        {
            actualDuration = 0;
        }

        public void LogExercise(ExerciseLog exercise)
        {
            completedExercises.Add(exercise);
        }

        public void CompleteSession()
        {
            burnedCalories = completedExercises.Count * 100;
        }

        public int GetBurnedCalories()
        {
            return burnedCalories;
        }
    }
}