using System;
using System.Collections.Generic;

namespace FitnessApp
{
    public interface ICalorieEstimator
    {
        int EstimateCalories(ExerciseType exercise, int duration);
    }

    public class BaseCalorieEstimator : ICalorieEstimator
    {
        public int EstimateCalories(ExerciseType exercise, int duration)
        {
            return exercise.BaseCaloriesPerMin * duration;
        }
    }

    public class CardioCalorieEstimator : ICalorieEstimator
    {
        public int EstimateCalories(ExerciseType exercise, int duration)
        {
            return exercise.BaseCaloriesPerMin * duration + duration * 10;
        }
    }

    public class StrengthCalorieEstimator : ICalorieEstimator
    {
        public int EstimateCalories(ExerciseType exercise, int duration)
        {
            int reps = exercise is StrengthExerciseType s ? s.reps : 0;
            return exercise.BaseCaloriesPerMin * duration + reps * 5;
        }
    }

    public class ExerciseType : ICloneable
    {
        private string id;
        private string title;
        private Category category;
        private HashSet<Muscle> targetMuscles = new HashSet<Muscle>();
        private HashSet<Equipment> requiredEquipment = new HashSet<Equipment>();
        protected int baseCaloriesPerMin;

        protected ICalorieEstimator calorieEstimator;

        public int BaseCaloriesPerMin
        {
            get { return baseCaloriesPerMin; }
            set { baseCaloriesPerMin = value; }
        }

        public ExerciseType()
        {
            calorieEstimator = new BaseCalorieEstimator();
        }

        public int EstimateCalories(int duration)
        {
            return calorieEstimator.EstimateCalories(this, duration);
        }

        public void SetCalorieEstimator(ICalorieEstimator newEstimator)
        {
            calorieEstimator = newEstimator;
        }

        public List<ExerciseType> FindSimilar(Category category)
        {
            return new List<ExerciseType>();
        }

        public bool IsCompatible(FitnessUser user)
        {
            return user != null;
        }

        public object Clone()
        {
            return this.MemberwiseClone();
        }

        public ExerciseType DeepClone()
        {
            ExerciseType clone = (ExerciseType)this.MemberwiseClone();
            clone.targetMuscles = new HashSet<Muscle>(targetMuscles);
            clone.requiredEquipment = new HashSet<Equipment>(requiredEquipment);
            return clone;
        }
    }
}