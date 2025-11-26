using System;

namespace FitnessApp
{
    public class GoalSetting
    {
        private string id;
        private string userId;
        private GoalType goalType;
        private double targetValue; 
        private string startDate;
        private string deadline;
        private double initialValue;

        public GoalSetting() { }

        public GoalSetting(string id, string userId, GoalType goalType, double targetValue, string startDate, string deadline)
        {
            this.id = id;
            this.userId = userId;
            this.goalType = goalType;
            this.TargetValue = targetValue; 
            this.startDate = startDate;
            this.deadline = deadline;
            this.initialValue = 0.0;
        }

        public double TargetValue
        {
            get { return targetValue; }
            set
            {
                if (value <= 0) throw new ArgumentOutOfRangeException("TargetValue", "Целевое значение должно быть положительным");
                targetValue = value;
            }
        }

        public double UpdateProgress(double currentValue)
        {
            try
            {
                if (initialValue == 0.0) return 0.0;
                if (initialValue == targetValue) throw new InvalidOperationException("Начальное и целевое значения не могут быть равны - деление на ноль");
                double progress = 0.0;
                if (goalType == GoalType.WeightLoss)
                {
                    progress = (initialValue - currentValue) / (initialValue - targetValue) * 100.0;
                }
                return progress;
            }
            catch (InvalidOperationException ex)
            {
                Console.WriteLine($"Ошибка обновления прогресса: {ex.Message}");
                return 0.0;
            }
        }

        public bool IsAchieved() { return false; }

        public void ExtendDeadline(string newDate) { deadline = newDate; }

        public void SetInitialValue(double val) { initialValue = val; }
    }
}