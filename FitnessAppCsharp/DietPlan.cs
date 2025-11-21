using System;
using System.Collections.Generic;

namespace FitnessApp
{
    public class DietPlan
    {
        private string id;
        private string userId;
        private int dailyCalories;
        private Macros macros;
        private List<Meal> mealsPerDay = new List<Meal>();

        public List<Meal> GenerateDailyMeals()
        {
            return new List<Meal> { new Meal() };
        }

        public void AdjustMacros(Macros newMacros)
        {
            macros = newMacros;
        }

        public void TrackIntake(Meal meal)
        {
        }
    }
}