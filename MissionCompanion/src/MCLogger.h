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

    static void LogMessage(const char* level, WORD color, const char* message, ...)
    {
        SetConsoleTextAttribute(h, color);
        printf("[%s] MC log %s: ", GetCurrentTime(), level);

        va_list args;
        va_start(args, message);
        vprintf(message, args);
        va_end(args);

        printf("\n");
        SetConsoleTextAttribute(h, 7); // Reset color
    }

    static const char* GetCurrentTime()
    {
        static char buffer[9];
        std::time_t current_time = std::time(nullptr);
        std::tm* timestamp = std::localtime(&current_time);
        strftime(buffer, sizeof(buffer), "%H:%M:%S", timestamp);
        return buffer;
    }

public:
    static void set_priority(LogPriority new_priority) { priority = new_priority; }

    template<typename... Args>
    static void Trace(const char* message, Args... args)
    {
        if (priority <= TracePriority) LogMessage("Trace", 8, message, args...); // Gray
    }

    template<typename... Args>
    static void Debug(const char* message, Args... args)
    {
        if (priority <= DebugPriority) LogMessage("Debug", 7, message, args...); // White
    }

    template<typename... Args>
    static void Info(const char* message, Args... args)
    {
        if (priority <= InfoPriority) LogMessage("Info", 11, message, args...); // Light Cyan
    }

    template<typename... Args>
    static void Warn(const char* message, Args... args)
    {
        if (priority <= WarnPriority) LogMessage("Warn", 14, message, args...); // Yellow
    }

    template<typename... Args>
    static void Error(const char* message, Args... args)
    {
        if (priority <= ErrorPriority) LogMessage("Error", 12, message, args...); // Light Red
    }

    template<typename... Args>
    static void Critical(const char* message, Args... args)
    {
        if (priority <= CriticalPriority) LogMessage("Critical", 4, message, args...); // Red
    }
};

// Define static member
LogPriority Logger::priority = InfoPriority;
HANDLE Logger::h = GetStdHandle(STD_OUTPUT_HANDLE);