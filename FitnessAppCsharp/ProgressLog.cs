using System;
using System.Collections.Generic;

namespace FitnessApp
{
    public class ProgressLog : ILoggable
    {
        private string userId;
        private List<LogEntry> entries = new List<LogEntry>();
        private List<GoalSetting> goalsLinked = new List<GoalSetting>();

        public void AddEntry(LogEntry entry)
        {
            entries.Add(entry);
        }

        public string GenerateReport(DateRange period)
        {
            return "Отчет о прогрессе за период с " + period.Start + " по " + period.End;
        }

        public void VisualizeProgress()
        {
            Console.WriteLine("Визуализация прогресса (заглушка для графика)");
        }

        public void Log(string message)
        {
            Console.WriteLine($"Progress log: {message}");
        }
    }

}