#include "GoalSetting.hpp"

// ����������� � �����������
GoalSetting::GoalSetting(const std::string& id, const std::string& userId, GoalType goalType, double targetValue, const std::string& startDate, const std::string& deadline)
    : id(id), userId(userId), goalType(goalType), targetValue(targetValue), startDate(startDate), deadline(deadline), initialValue(0.0) {}

// ���������� ���������
double GoalSetting::updateProgress(double currentValue) {
    if (initialValue == 0.0) return 0.0; // �������� �� ����������
    double progress = 0.0;
    if (goalType == GoalType::WeightLoss) { // ��� �������� ����
        progress = (initialValue - currentValue) / (initialValue - targetValue) * 100.0;
    } // �������� ������ ��� ������ ����� �����
    return progress;
}

// �������� ���������� ����
bool GoalSetting::isAchieved() {
    return false; // ��������, ������� ��������� �������� ��������
}

// ��������� �����
void GoalSetting::extendDeadline(const std::string& newDate) {
    deadline = newDate;
}

// ��������� ���������� ��������
void GoalSetting::setInitialValue(double val) {
    initialValue = val;
}