#ifndef PROGRESSLOG_HPP
#define PROGRESSLOG_HPP

#include <vector>
#include <string>
#include "types.hpp"
#include "GoalSetting.hpp"

class ProgressLog
{
public:
    // Конструктор по умолчанию
    ProgressLog() = default;
    // Деструктор
    ~ProgressLog() = default;

private:
    std::string userId; // Идентификатор пользователя
    std::vector<LogEntry> entries; // Список записей
    std::vector<GoalSetting> goalsLinked; // Связанные цели

public:
    // Добавление записи
    void addEntry(const LogEntry& entry);
    // Генерация отчета за период
    std::string generateReport(const DateRange& period);
    // Визуализация прогресса
    void visualizeProgress();
};

#endif