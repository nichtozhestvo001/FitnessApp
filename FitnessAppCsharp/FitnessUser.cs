using System;

namespace FitnessApp
{
    public class FitnessUser
    {
        private string id;
        private string username;
        private string email;
        private string birthDate;
        private Gender gender;
        private double heightM;
        private double currentWeight;
        private ActivityLevel activityLevel;

        public FitnessUser() { }

        public FitnessUser(string id, string username, string email, string birthDate, Gender gender, double heightM, double currentWeight, ActivityLevel activityLevel)
        {
            this.id = id;
            this.username = username;
            this.email = email;
            this.birthDate = birthDate;
            this.gender = gender;
            this.heightM = heightM;
            this.currentWeight = currentWeight;
            this.activityLevel = activityLevel;
        }

        public double CalculateBMI()
        {
            if (heightM <= 0) return 0.0;
            return currentWeight / (heightM * heightM);
        }

        public void SetNewWeight(double newWeight)
        {
            currentWeight = newWeight;
        }

        public int GetRecommendedCalories()
        {
            int baseCalories = 2000;
            if (activityLevel == ActivityLevel.High) baseCalories += 500;
            else if (activityLevel == ActivityLevel.Medium) baseCalories += 250;
            return baseCalories;
        }
    }
}