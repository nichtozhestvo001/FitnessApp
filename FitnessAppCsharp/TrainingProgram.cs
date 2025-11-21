using System;
using System.Collections.Generic;

namespace FitnessApp
{
    public class TrainingProgram
    {
        private string id;
        private string name;
        private int durationWeeks;
        private int frequency;
        private List<ExerciseType> exerciseTypes = new List<ExerciseType>();
        private Difficulty difficulty;

        public List<Session> GenerateWeeklySchedule()
        {
            List<Session> schedule = new List<Session>();
            for (int i = 0; i < frequency; i++)
            {
                schedule.Add(new Session());
            }
            return schedule;
        }

        public void AdjustForUser(FitnessUser user)
        {
        }

        public void AddExerciseType(ExerciseType newType)
        {
            exerciseTypes.Add(newType);
        }
    }
}