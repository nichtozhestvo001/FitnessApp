using System;
using System.Collections.Generic;
using System.Text;

namespace FitnessApp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;

            Console.WriteLine("Тест 1: Статическая инициализация");
            FitnessUser staticUser = new FitnessUser("1", "user1", "user1@gmail.com", "2000-01-01", Gender.Male, 1.8, 80.0, ActivityLevel.Medium);
            Console.WriteLine(" Статический FitnessUser создан, BMI: " + staticUser.CalculateBMI() + " (ожидается ~24.69)");
            Console.WriteLine(" Рекомендуемые калории: " + staticUser.GetRecommendedCalories() + " (ожидается 2250)");

            Console.WriteLine("\nТест 2: Динамическая инициализация");
            FitnessUser dynamicUser = new FitnessUser("2", "user2", "user1@gmail.com", "1995-05-05", Gender.Female, 1.65, 60.0, ActivityLevel.High);
            Console.WriteLine(" Динамический FitnessUser создан, BMI: " + dynamicUser.CalculateBMI() + " (ожидается ~22.04)");
            Console.WriteLine(" Рекомендуемые калории: " + dynamicUser.GetRecommendedCalories() + " (ожидается 2500)");

            Console.WriteLine("\nТест 3: Работа с ссылками");
            GoalSetting goal = new GoalSetting("g1", "1", GoalType.WeightLoss, 70.0, "2025-10-01", "2025-12-31");
            goal.SetInitialValue(80.0);
            GoalSetting goalRef = goal; // В C# это ссылка по умолчанию
            goalRef.ExtendDeadline("2026-01-31");
            Console.WriteLine(" Ссылка на GoalSetting: срок продлён, прогресс: " + goalRef.UpdateProgress(75.0) + " (ожидается 50)");

            Console.WriteLine("\nТест 4: Работа с указателями");
            ReminderSystem reminderSystem = new ReminderSystem();
            ReminderSystem reminderPtr = reminderSystem; // Ссылка
            Reminder r = new Reminder { Id = "r1", Time = "10:00", Message = "Время тренировки" };
            reminderPtr.SetReminder(r);
            Console.WriteLine(" Указатель на ReminderSystem: напоминание добавлено");
            reminderPtr.CancelReminder("r1");
            Console.WriteLine(" Указатель на ReminderSystem: напоминание удалено");

            Console.WriteLine("\nТест 5: Динамический массив объектов");
            Session[] sessionArray = new Session[3];
            for (int i = 0; i < 3; i++) sessionArray[i] = new Session();
            sessionArray[0].StartSession();
            sessionArray[0].LogExercise(new ExerciseLog { ExerciseTypeId = "ex1", DurationMin = 10, Reps = 12, WeightKg = 20.0 });
            sessionArray[0].LogExercise(new ExerciseLog { ExerciseTypeId = "ex2", DurationMin = 15, Reps = 10, WeightKg = 15.0 });
            sessionArray[0].CompleteSession();
            Console.WriteLine(" Динамический массив Session: калории первой сессии: " + sessionArray[0].GetBurnedCalories() + " (ожидается 200)");

            sessionArray[1].StartSession();
            sessionArray[1].LogExercise(new ExerciseLog { ExerciseTypeId = "ex3", DurationMin = 12, Reps = 15, WeightKg = 25.0 });
            sessionArray[1].LogExercise(new ExerciseLog { ExerciseTypeId = "ex4", DurationMin = 20, Reps = 8, WeightKg = 30.0 });
            sessionArray[1].LogExercise(new ExerciseLog { ExerciseTypeId = "ex5", DurationMin = 10, Reps = 10, WeightKg = 10.0 });
            sessionArray[1].CompleteSession();
            Console.WriteLine(" Динамический массив Session: калории второй сессии: " + sessionArray[1].GetBurnedCalories() + " (ожидается 300)");

            Console.WriteLine("\nТест 6: Массив динамических объектов");
            List<FoodItem> foodVector = new List<FoodItem>();
            foodVector.Add(new FoodItem("f1", "Apple", 52, 0.3, 13.8, 0.2));
            foodVector.Add(new FoodItem("f2", "Banana", 89, 1.1, 22.8, 0.3));
            Console.WriteLine(" Массив FoodItem: добавлено " + foodVector.Count + " объекта");
            foreach (var item in foodVector)
            {
                Nutrition n = item.GetNutrition(150.0);
                Console.WriteLine(" Калории для 150 г: " + n.Calories + " (ожидается 78 для Apple или 133 для Banana)");
            }
            Console.WriteLine(" Массив динамических объектов очищен");
        }
    }
}