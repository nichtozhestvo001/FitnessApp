using System;
using System.Collections.Generic;

namespace FitnessApp
{
    public class FoodItem
    {
        private string id;
        private string name;
        private int caloriesPer100g;
        private double proteinPer100g;
        private double carbsPer100g;
        private double fatsPer100g;

        public FoodItem() { }

        public FoodItem(string id, string name, int caloriesPer100g, double proteinPer100g, double carbsPer100g, double fatsPer100g)
        {
            this.id = id;
            this.name = name;
            this.CaloriesPer100g = caloriesPer100g;
            this.proteinPer100g = proteinPer100g;
            this.carbsPer100g = carbsPer100g;
            this.fatsPer100g = fatsPer100g;
        }

        public int CaloriesPer100g
        {
            get { return caloriesPer100g; }
            set
            {
                if (value < 0) throw new ArgumentOutOfRangeException("CaloriesPer100g", "Калории не могут быть отрицательными");
                caloriesPer100g = value;
            }
        }

        public Nutrition GetNutrition(double amountG)
        {
            try
            {
                if (amountG <= 0) throw new ArgumentOutOfRangeException("amountG", "Количество должно быть положительным");
                Nutrition n = new Nutrition();
                double factor = amountG / 100.0;
                n.Calories = (int)(CaloriesPer100g * factor);
                n.Protein = proteinPer100g * factor;
                n.Carbs = carbsPer100g * factor;
                n.Fats = fatsPer100g * factor;
                return n;
            }
            catch (ArgumentOutOfRangeException ex)
            {
                Console.WriteLine($"Ошибка питания: {ex.Message}");
                return new Nutrition();
            }
        }

        public bool IsAllergenFree(HashSet<Allergen> allergens) { return true; }
    }
}