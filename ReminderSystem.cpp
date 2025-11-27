#include "ReminderSystem.hpp"
#include <algorithm>


void ReminderSystem::setReminder(const Reminder& reminder) {
    reminders.push_back(reminder);
}


void ReminderSystem::triggerNotifications() {
}


void ReminderSystem::cancelReminder(const std::string& id) {
    reminders.erase(std::remove_if(reminders.begin(), reminders.end(), [&](const Reminder& r) { return r.id == id; }), reminders.end());
}