using System;
using System.Collections.Generic;

namespace FitnessApp
{
    public enum Gender
    {
        Male,
        Female,
        Other
    }

    public enum ActivityLevel
    {
        Low,
        Medium,
        High
    }

    public enum GoalType
    {
        WeightLoss,
        MuscleGain,
        Maintenance
    }

    public enum Difficulty
    {
        Beginner,
        Intermediate,
        Advanced
    }

    public enum Category
    {
        Cardio,
        Strength,
        Yoga
    }

    public enum Muscle
    {
        Chest,
        Back,
        Legs,
        Arms,
        Shoulders,
        Abs
    }

    public enum Equipment
    {
        None,
        Dumbbells,
        Barbell,
        Machine
    }

    public struct Macros
    {
        public double ProteinRatio { get; set; }
        public double FatsRatio { get; set; }
        public double CarbsRatio { get; set; }
    }

    public struct Nutrition
    {
        public double Protein { get; set; }
        public double Carbs { get; set; }
        public double Fats { get; set; }
        public int Calories { get; set; }
    }

    public enum Allergen
    {
        Nuts,
        Dairy,
        Gluten
    }

    public struct LogEntry
    {
        public string Date { get; set; }
        public double Weight { get; set; }
        public string Photo { get; set; }
    }

    public struct DateRange
    {
        public string Start { get; set; }
        public string End { get; set; }
    }

    public struct Reminder
    {
        public string Id { get; set; }
        public string Time { get; set; }
        public string Message { get; set; }
    }

    public enum NotificationType
    {
        Push,
        Email
    }

    public struct ExerciseLog
    {
        public string ExerciseTypeId { get; set; }
        public int DurationMin { get; set; }
        public int Reps { get; set; }
        public double WeightKg { get; set; }
    }
}