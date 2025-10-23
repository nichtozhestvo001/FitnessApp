#include "ReminderSystem.hpp"
#include <algorithm>

// Добавление напоминания
void ReminderSystem::setReminder(const Reminder& reminder) {
    reminders.push_back(reminder);
}

// Отправка уведомлений
void ReminderSystem::triggerNotifications() {
    // Заглушка: симуляция отправки
}

// Отмена напоминания
void ReminderSystem::cancelReminder(const std::string& id) {
    reminders.erase(std::remove_if(reminders.begin(), reminders.end(), [&](const Reminder& r) { return r.id == id; }), reminders.end());
}