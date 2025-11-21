using System;
using System.Collections.Generic;
using System.Linq;

namespace FitnessApp
{
    public class ReminderSystem
    {
        private string userId;
        private List<Reminder> reminders = new List<Reminder>();
        private NotificationType notificationType;

        public void SetReminder(Reminder reminder)
        {
            reminders.Add(reminder);
        }

        public void TriggerNotifications()
        {
            // Заглушка
        }

        public void CancelReminder(string id)
        {
            reminders.RemoveAll(r => r.Id == id);
        }
    }
}