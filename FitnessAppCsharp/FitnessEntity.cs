using System;

namespace FitnessApp
{
    public abstract class FitnessEntity
    {
        protected string Id { get; init; }
        protected static int TotalEntities = 0;

        protected FitnessEntity(string id)
        {
            Id = id;
            TotalEntities++;
        }

        public abstract string GetInfo();
        public abstract FitnessEntity Clone(); // Для клонирования

        public virtual double CalculateSomething() // Виртуальный метод для демонстрации
        {
            return 0.0;
        }

        public void CallVirtual() // Невиртуальный вызывает виртуальный
        {
            Console.WriteLine("Результат виртуального: " + CalculateSomething());
        }

        public static int GetTotalEntities() => TotalEntities;
    }
}