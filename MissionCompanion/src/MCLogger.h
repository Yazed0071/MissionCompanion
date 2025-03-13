#pragma once
#include <stdio.h>
#include <ctime>
#include <Windows.h>

enum LogPriority
{
    TracePriority, DebugPriority, InfoPriority, WarnPriority, ErrorPriority, CriticalPriority
};

class Logger
{
private:
    static LogPriority priority;
    static HANDLE h;
    static void LogMessage(const char* level, WORD color, const char* message, ...);
    static const char* GetCurrentTime();

public:
    static void set_priority(LogPriority new_priority);

    template<typename... Args>
    static void Trace(const char* message, Args... args)
    {
        if (priority <= TracePriority) LogMessage("Trace", 8, message, args...);
    }

    template<typename... Args>
    static void Debug(const char* message, Args... args)
    {
        if (priority <= DebugPriority) LogMessage("Debug", 7, message, args...);
    }

    template<typename... Args>
    static void Info(const char* message, Args... args)
    {
        if (priority <= InfoPriority) LogMessage("Info", 2, message, args...);
    }

    template<typename... Args>
    static void Warn(const char* message, Args... args)
    {
        if (priority <= WarnPriority) LogMessage("Warn", 14, message, args...);
    }

    template<typename... Args>
    static void Error(const char* message, Args... args)
    {
        if (priority <= ErrorPriority) LogMessage("Error", 12, message, args...);
    }

    template<typename... Args>
    static void Critical(const char* message, Args... args)
    {
        if (priority <= CriticalPriority) LogMessage("Critical", 4, message, args...);
    }
};
