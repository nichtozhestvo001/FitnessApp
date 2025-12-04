using System;

namespace FitnessApp
{
    public class FitnessUser : FitnessEntity, INotifiable, ILoggable
    {
        private string username;
        private string email;
        private string birthDate;
        private Gender gender;
        private double heightM;
        private double currentWeight;
        private ActivityLevel activityLevel;

        private static int totalUsers = 0;
        public static int TotalUsers => totalUsers;

        public static string GetAppVersion()
        {
            return "FitnessApp v1.0 - Демонстрация статического метода";
        }

        public FitnessUser() : base(Guid.NewGuid().ToString()) 
        {
            totalUsers++;
        }

        public FitnessUser(string id, string username, string email, string birthDate, Gender gender, double heightM, double currentWeight, ActivityLevel activityLevel)
            : base(id)
        {
            this.username = username;
            this.email = email;
            this.birthDate = birthDate;
            this.gender = gender;
            this.heightM = heightM;
            this.CurrentWeight = currentWeight;
            this.activityLevel = activityLevel;
            totalUsers++;
        }

        public double CurrentWeight
        {
            get { return currentWeight; }
            set
            {
                if (value <= 0) throw new ArgumentOutOfRangeException("CurrentWeight", "Вес должен быть положительным");
                currentWeight = value;
            }
        }

        public double CalculateBMI()
        {
            try
            {
                if (heightM <= 0) throw new InvalidOperationException("Рост должен быть положительным для расчёта ИМТ");
                return CurrentWeight / (heightM * heightM);
            }
            catch (InvalidOperationException ex)
            {
                Console.WriteLine($"Ошибка расчёта ИМТ: {ex.Message}");
                return 0.0;
            }
        }

        public void SetNewWeight(double newWeight)
        {
            this.CurrentWeight = newWeight;
        }

        public int GetRecommendedCalories()
        {
            int baseCalories = 2000;
            if (this.activityLevel == ActivityLevel.High) baseCalories += 500;
            else if (this.activityLevel == ActivityLevel.Medium) baseCalories += 250;
            return baseCalories;
        }

        public override string GetInfo()
        {
            return $"User ID: {Id}, Username: {username}";
        }

        public override FitnessEntity Clone()
        {
            return new FitnessUser(Id, username, email, birthDate, gender, heightM, currentWeight, activityLevel);
        }

        public override double CalculateSomething()
        {
            return base.CalculateSomething() + CurrentWeight;
        }

        public void SendNotification(string message)
        {
            Console.WriteLine($"Notification to {username}: {message}");
        }

        public void Log(string message)
        {
            Console.WriteLine($"Log for {username}: {message}");
        }

    }
}