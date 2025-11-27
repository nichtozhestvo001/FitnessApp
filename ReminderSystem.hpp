#ifndef REMINDERSYSTEM_HPP
#define REMINDERSYSTEM_HPP

#include <vector>
#include "types.hpp"

class ReminderSystem
{
public:
    ReminderSystem() = default;
    ~ReminderSystem() = default;

private:
    std::string userId; 
    std::vector<Reminder> reminders; 
    NotificationType notificationType; 

public:
    void setReminder(const Reminder& reminder);
    void triggerNotifications();
    void cancelReminder(const std::string& id);
};

#endif
