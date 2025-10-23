#include "ProgressLog.hpp"
#include <iostream>

// ���������� ������
void ProgressLog::addEntry(const LogEntry& entry) {
    entries.push_back(entry);
}

// ��������� ������
std::string ProgressLog::generateReport(const DateRange& period) {
    return "����� � ��������� �� ������ � " + period.start + " �� " + period.end; // ��������
}

// ������������ ���������
void ProgressLog::visualizeProgress() {
    std::cout << "������������ ��������� (�������� ��� �������)" << std::endl;
}