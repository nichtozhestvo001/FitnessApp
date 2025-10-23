#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>
#include <vector>
#include <set>

using IdType = std::string; // Уникальный идентификатор
using DateType = std::string; // Дата в строковом формате
using TimeType = std::string; // Время в строковом формате

// Пол пользователя
enum class Gender {
    Male, // Мужской
    Female, // Женский
    Other // Другое :)
};

// Уровень активности пользователя
enum class ActivityLevel {
    Low, 
    Medium,
    High 
};

// Тип цели пользователя
enum class GoalType {
    WeightLoss, // Снижение веса
    MuscleGain, // Набор мышечной массы
    Maintenance // Поддержание формы
};

// Уровень сложности программы тренировок
enum class Difficulty {
    Beginner, // Начинающий
    Intermediate, // Средний
    Advanced // Продвинутый
};

// Категория упражнения
enum class Category {
    Cardio, // Кардио
    Strength, // Силовые
    Yoga // Йога
};

// Целевые группы мышц
enum class Muscle {
    Chest, // Грудь
    Back, // Спина
    Legs, // Ноги
    Arms, // Руки
    Shoulders, // Плечи
    Abs // Пресс
};

// Необходимое оборудование
enum class Equipment {
    None, // Без оборудования
    Dumbbells, // Гантели
    Barbell, // Штанга
    Machine // Тренажер
};

// Структура для макронутриентов
struct Macros {
    double proteinRatio; // Доля белков
    double fatsRatio; // Доля жиров
    double carbsRatio; // Доля углеводов
};

// Структура для нутриентов
struct Nutrition {
    double protein; // Белки
    double carbs; // Углеводы
    double fats; // Жиры
    int calories; // Калории
};

// Возможные аллергены
enum class Allergen {
    Nuts, // Орехи
    Dairy, // Молочные продукты
    Gluten // Глютен
};

// Запись в журнале прогресса
struct LogEntry {
    DateType date; // Дата записи
    double weight; // Вес
    std::string photo; // Фото (путь или ссылка)
};

// Диапазон дат
struct DateRange {
    DateType start; // Начало периода
    DateType end; // Конец периода
};

// Напоминание
struct Reminder {
    IdType id;
    TimeType time; 
    std::string message;
};

// Тип уведомления
enum class NotificationType {
    Push, // Push-уведомление
    Email // Электронная почта
};

// Лог выполненного упражнения
struct ExerciseLog {
    IdType exerciseTypeId; // Идентификатор типа упражнения
    int durationMin; // Длительность в минутах
    int reps; // Количество повторений
    double weightKg; // Вес (если применимо)
};

#endif