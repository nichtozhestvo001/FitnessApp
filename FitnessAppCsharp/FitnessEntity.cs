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
        public abstract FitnessEntity Clone();

        public virtual double CalculateSomething()
        {
            return 0.0;
        }

        public void CallVirtual()
        {
            Console.WriteLine("Результат виртуального: " + CalculateSomething());
        }

        public static int GetTotalEntities() => TotalEntities;
    }
}