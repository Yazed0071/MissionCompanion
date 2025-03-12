#pragma once

#include <stdio.h>
#include <ctime>

enum LogPriority
{
    TracePriority, DebugPriority, InfoPriority, WarnPriority, ErrorPriority, CriticalPriority
};

class Logger
{
private:
    static LogPriority priority;

public:
    static void set_priority(LogPriority new_priority)
    {
        priority = new_priority;
    }

    template<typename... Args>
    static void Trace(const char* message, Args... args)
    {
        if (priority <= TracePriority)
        {
            std::time_t current_time = std::time(0);
            std::tm* timestamp = std::localtime(&current_time);
            char buffer[80];
            strftime(buffer, 80, "%X", timestamp);

            printf("[%s] ", buffer);
            printf("MC log Trace: ");
            printf(message, args...);
            printf("\n");
        }
    }

    template<typename... Args>
    static void Debug(const char* message, Args... args)
    {
        if (priority <= DebugPriority)
        {
            std::time_t current_time = std::time(0);
            std::tm* timestamp = std::localtime(&current_time);
            char buffer[80];
            strftime(buffer, 80, "%X", timestamp);

            printf("[%s] ", buffer);
            printf("MC log Debug:\t");
            printf(message, args...);
            printf("\n");
        }
    }

    template<typename... Args>
    static void Info(const char* message, Args... args)
    {
        if (priority <= InfoPriority)
        {
            std::time_t current_time = std::time(0);
            std::tm* timestamp = std::localtime(&current_time);
            char buffer[80];
            strftime(buffer, 80, "%X", timestamp);

            printf("[%s] ", buffer);
            printf("MC log Info:\t");
            printf(message, args...);
            printf("\n");
        }
    }

    template<typename... Args>
    static void Warn(const char* message, Args... args)
    {
        if (priority <= WarnPriority)
        {
            std::time_t current_time = std::time(0);
            std::tm* timestamp = std::localtime(&current_time);
            char buffer[80];
            strftime(buffer, 80, "%X", timestamp);

            printf("[%s] ", buffer);
            printf("MC log Warn:\t");
            printf(message, args...);
            printf("\n");
        }
    }

    template<typename... Args>
    static void Error(const char* message, Args... args)
    {
        if (priority <= ErrorPriority)
        {
            std::time_t current_time = std::time(0);
            std::tm* timestamp = std::localtime(&current_time);
            char buffer[80];
            strftime(buffer, 80, "%X", timestamp);

            printf("[%s] ", buffer);
            printf("MC log Error:\t");
            printf(message, args...);
            printf("\n");
        }
    }

    template<typename... Args>
    static void Critical(const char* message, Args... args)
    {
        if (priority <= CriticalPriority)
        {
            std::time_t current_time = std::time(0);
            std::tm* timestamp = std::localtime(&current_time);
            char buffer[80];
            strftime(buffer, 80, "%X", timestamp);

            printf("[%s] ", buffer);
            printf("MC log Critical:\t");
            printf(message, args...);
            printf("\n");
        }
    }
};

// Define static member
LogPriority Logger::priority = InfoPriority;
