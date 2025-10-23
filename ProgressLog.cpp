#include "ProgressLog.hpp"
#include <iostream>

// Добавление записи
void ProgressLog::addEntry(const LogEntry& entry) {
    entries.push_back(entry);
}

// Генерация отчета
std::string ProgressLog::generateReport(const DateRange& period) {
    return "Отчет о прогрессе за период с " + period.start + " по " + period.end; // Заглушка
}

// Визуализация прогресса
void ProgressLog::visualizeProgress() {
    std::cout << "Визуализация прогресса (заглушка для графика)" << std::endl;
}