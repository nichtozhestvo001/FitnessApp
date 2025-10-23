#ifndef GOALSETTING_HPP
#define GOALSETTING_HPP

#include "types.hpp"

class GoalSetting
{
public:
    GoalSetting() = default;
    GoalSetting(const std::string& id, const std::string& userId, GoalType goalType, double targetValue, const std::string& startDate, const std::string& deadline);
    ~GoalSetting() = default;

private:
    std::string id; // ������������� ����
    std::string userId; // ������������� ������������
    GoalType goalType; // ��� ����
    double targetValue; // ������� �������� (��������, ���)
    std::string startDate; // ���� ������
    std::string deadline; // ���� ����������
    double initialValue; // ��������� �������� ��� ������� ���������

public:
    // ��������� �������� � ���������� ������� ����������
    double updateProgress(double currentValue);
    // ���������, ���������� �� ����
    bool isAchieved();
    // ���������� ���� ����������
    void extendDeadline(const std::string& newDate);
    // ������������� ��������� ��������
    void setInitialValue(double val);
};

#endif