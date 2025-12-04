using System;
using System.Collections.Generic;

namespace FitnessApp
{
    public class ExerciseType : ICloneable
    {
        private string id;
        private string title;
        private Category category;
        private HashSet<Muscle> targetMuscles = new HashSet<Muscle>();
        private HashSet<Equipment> requiredEquipment = new HashSet<Equipment>();
        protected int baseCaloriesPerMin;

        public virtual int EstimateCalories(int duration)
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