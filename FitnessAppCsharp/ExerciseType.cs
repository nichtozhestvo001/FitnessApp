using System;
using System.Collections.Generic;

namespace FitnessApp
{
    public class ExerciseType
    {
        private string id;
        private string title;
        private Category category;
        private HashSet<Muscle> targetMuscles = new HashSet<Muscle>();
        private HashSet<Equipment> requiredEquipment = new HashSet<Equipment>();
        private int baseCaloriesPerMin;

        public int EstimateCalories(int duration)
        {
            return baseCaloriesPerMin * duration;
        }

        public List<ExerciseType> FindSimilar(Category category)
        {
            return new List<ExerciseType>(); 
        }

        public bool IsCompatible(FitnessUser user)
        {
            return user != null; 
        }
    }
}