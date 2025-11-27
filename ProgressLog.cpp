#include "ProgressLog.hpp"
#include <iostream>


void ProgressLog::addEntry(const LogEntry& entry) {
    entries.push_back(entry);
}


std::string ProgressLog::generateReport(const DateRange& period) {
    return "Отчет о прогрессе за период с " + period.start + " по " + period.end; 
}


void ProgressLog::visualizeProgress() {
    std::cout << "Визуализация прогресса (заглушка для графика)" << std::endl;
}