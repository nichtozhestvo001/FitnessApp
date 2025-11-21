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
            this.targetValue = targetValue;
            this.startDate = startDate;
            this.deadline = deadline;
            this.initialValue = 0.0;
        }

        public double UpdateProgress(double currentValue)
        {
            if (initialValue == 0.0) return 0.0;
            double progress = 0.0;
            if (goalType == GoalType.WeightLoss)
            {
                progress = (initialValue - currentValue) / (initialValue - targetValue) * 100.0;
            }
            return progress;
        }

        public bool IsAchieved()
        {
            return false;
        }

        public void ExtendDeadline(string newDate)
        {
            deadline = newDate;
        }

        public void SetInitialValue(double val)
        {
            initialValue = val;
        }
    }
}