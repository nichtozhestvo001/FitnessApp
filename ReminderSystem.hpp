#ifndef REMINDERSYSTEM_HPP
#define REMINDERSYSTEM_HPP

#include <vector>
#include "types.hpp"

class ReminderSystem
{
public:
    // Конструктор по умолчанию
    ReminderSystem() = default;
    // Деструктор
    ~ReminderSystem() = default;

private:
    std::string userId; // Идентификатор пользователя
    std::vector<Reminder> reminders; // Список напоминаний
    NotificationType notificationType; // Тип уведомления

public:
    // Добавление напоминания
    void setReminder(const Reminder& reminder);
    // Отправка уведомлений
    void triggerNotifications();
    // Отмена напоминания
    void cancelReminder(const std::string& id);
};

#endif
