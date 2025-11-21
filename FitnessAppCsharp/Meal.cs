using System;
using System.Collections.Generic;

namespace FitnessApp
{
    public class Meal
    {
        private string id;
        private string dietId;
        private string mealTime;
        private List<FoodItem> foodItems = new List<FoodItem>();
        private int totalCalories;
        private Nutrition nutrition;

        public void AddFoodItem(FoodItem item)
        {
            foodItems.Add(item);
        }

        public void CalculateTotals()
        {
            totalCalories = 0; // Доработать: суммировать из foodItems
        }

        public void SubstituteItem(FoodItem oldItem, FoodItem newItem)
        {
            // Заглушка
        }
    }
}