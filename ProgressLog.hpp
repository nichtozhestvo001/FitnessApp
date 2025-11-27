#ifndef PROGRESSLOG_HPP
#define PROGRESSLOG_HPP

#include <vector>
#include <string>
#include "types.hpp"
#include "GoalSetting.hpp"

class ProgressLog
{
public:
    ProgressLog() = default;
    ~ProgressLog() = default;

private:
    std::string userId; 
    std::vector<LogEntry> entries; 
    std::vector<GoalSetting> goalsLinked; 

public:
    void addEntry(const LogEntry& entry);
    std::string generateReport(const DateRange& period);
    void visualizeProgress();
};

#endif