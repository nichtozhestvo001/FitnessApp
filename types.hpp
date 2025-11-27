#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>
#include <vector>
#include <set>

using IdType = std::string; 
using DateType = std::string; 
using TimeType = std::string; 


enum class Gender {
    Male, 
    Female
};


enum class ActivityLevel {
    Low, 
    Medium,
    High 
};


enum class GoalType {
    WeightLoss, 
    MuscleGain,
    Maintenance
};


enum class Difficulty {
    Beginner, 
    Intermediate,
    Advanced 
};

enum class Category {
    Cardio, 
    Strength,
    Yoga 
};


enum class Muscle {
    Chest, 
    Back, 
    Legs, 
    Arms, 
    Shoulders, 
    Abs
};

enum class Equipment {
    None, 
    Dumbbells,
    Barbell,
    Machine 
};

struct Macros {
    double proteinRatio; 
    double fatsRatio; 
    double carbsRatio; 
};


struct Nutrition {
    double protein; 
    double carbs; 
    double fats; 
    int calories;
};

enum class Allergen {
    Nuts, 
    Dairy, 
    Gluten 
};


struct LogEntry {
    DateType date; 
    double weight; 
    std::string photo; 
};


struct DateRange {
    DateType start; 
    DateType end; 
};


struct Reminder {
    IdType id;
    TimeType time; 
    std::string message;
};


enum class NotificationType {
    Push, 
    Email 
};


struct ExerciseLog {
    IdType exerciseTypeId;
    int durationMin; 
    int reps;
    double weightKg;
};

#endif