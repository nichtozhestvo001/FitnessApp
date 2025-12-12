using System;
using System.Text;
using System.IO;

namespace FitnessApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;

            Console.WriteLine("Статическая версия приложения: " + FitnessUser.GetAppVersion());
            FitnessUser tempUser = new FitnessUser();
            Console.WriteLine("Общее количество пользователей (статическое поле): " + FitnessUser.TotalUsers);

            try
            {
                FitnessUser user = new FitnessUser("1", "user1", "user1@gmail.com", "2000-01-01", Gender.Male, 1.8, 80.0, ActivityLevel.Medium);
                Console.WriteLine("ИМТ: " + user.CalculateBMI());
                user.CurrentWeight = 75.0;
                Console.WriteLine("Обновлённый вес: " + user.CurrentWeight);

                user.CurrentWeight = -5.0;
            }
            catch (ArgumentOutOfRangeException ex)
            {
                Console.WriteLine("Перехвачено исключение свойства: " + ex.Message);
            }

            try
            {
                GoalSetting goal = new GoalSetting("g1", "1", GoalType.WeightLoss, 70.0, "2023-01-01", "2023-12-31");
                goal.SetInitialValue(80.0);
                Console.WriteLine("Прогресс: " + goal.UpdateProgress(75.0));

                goal = new GoalSetting("g2", "1", GoalType.WeightLoss, 80.0, "date", "date");
                goal.SetInitialValue(80.0);
                goal.UpdateProgress(75.0);
            }
            catch (InvalidOperationException ex)
            {
                Console.WriteLine("Перехвачено исключение прогресса: " + ex.Message);
            }

            try
            {
                FoodItem item = new FoodItem("f1", "Apple", -52, 0.3, 13.8, 0.2);
            }
            catch (ArgumentOutOfRangeException ex)
            {
                Console.WriteLine("Перехвачено исключение еды: " + ex.Message);
            }

            string logFile = "demo_log.txt";
            using (var writer = new StreamWriter(logFile))
            {
                writer.WriteLine("Демонстрация блока using - файл автоматически закроется");
            }
            Console.WriteLine("Файл записан с using - ресурс освобождён");

            if (File.Exists(logFile)) File.Delete(logFile);

            // Демонстрация модификаций для лабораторной

            Console.WriteLine("\nДемонстрация делегирования и конфигурирования:");

            CardioExerciseType cardio = new CardioExerciseType();
            cardio.BaseCaloriesPerMin = 5; 
            Console.WriteLine("Калории для кардио (статическая конфигурация): " + cardio.EstimateCalories(30));

            StrengthExerciseType strength = new StrengthExerciseType();
            strength.BaseCaloriesPerMin = 5; 
            strength.reps = 10;
            Console.WriteLine("Калории для силового (статическая конфигурация): " + strength.EstimateCalories(30));


            strength.SetCalorieEstimator(new CardioCalorieEstimator());
            Console.WriteLine("Калории для силового после динамической смены на кардио: " + strength.EstimateCalories(30));

            strength.SetCalorieEstimator(new StrengthCalorieEstimator());
            Console.WriteLine("Калории для силового после возврата: " + strength.EstimateCalories(30));

        }
    }
}