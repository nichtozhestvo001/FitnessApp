#include "GoalSetting.hpp"
#include <stdexcept>
#include <iostream>

GoalSetting::GoalSetting(const std::string& id, const std::string& userId, GoalType goalType, double targetValue, const std::string& startDate, const std::string& deadline)
    : id(id), userId(userId), goalType(goalType), targetValue(targetValue), startDate(startDate), deadline(deadline), initialValue(0.0) {}

GoalSetting::GoalSetting(const GoalSetting& other)
    : id(other.id), userId(other.userId), goalType(other.goalType), targetValue(other.targetValue), startDate(other.startDate), deadline(other.deadline), initialValue(other.initialValue) {}

double GoalSetting::updateProgress(double currentValue) {
    try {
        if (this->initialValue == 0.0) return 0.0;
        if (this->initialValue == this->targetValue) throw std::invalid_argument("Начальное и целевое равны");
        double progress = 0.0;
        if (this->goalType == GoalType::WeightLoss) {
            progress = (this->initialValue - currentValue) / (this->initialValue - this->targetValue) * 100.0;
        }
        return progress;
    }
    catch (const std::invalid_argument& ex) {
        std::cerr << "Ошибка прогресса: " << ex.what() << std::endl;
        return 0.0;
    }
}

bool GoalSetting::isAchieved() { return false; }

void GoalSetting::extendDeadline(const std::string& newDate) {
    this->deadline = newDate + " (продлён)"; 
    size_t pos = this->deadline.find("продлён"); 
    if (pos != std::string::npos) std::cout << "Найдено: " << this->deadline.substr(pos) << std::endl; 
}

void GoalSetting::setInitialValue(double val) { this->initialValue = val; }

GoalSetting GoalSetting::operator+(const GoalSetting& other) const {
    GoalSetting combined = *this; 
    combined.targetValue += other.targetValue;
    return combined;
}

double GoalSetting::operator[](int index) const {
    if (index == 0) return this->targetValue;
    if (index == 1) return this->initialValue;
    throw std::out_of_range("Индекс вне диапазона");
}