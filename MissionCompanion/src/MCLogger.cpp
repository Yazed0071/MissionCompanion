#include "MCLogger.h"

LogPriority Logger::priority = InfoPriority;
HANDLE Logger::h = GetStdHandle(STD_OUTPUT_HANDLE);

void Logger::set_priority(LogPriority new_priority)
{
    priority = new_priority;
}

const char* Logger::GetCurrentTime()
{
    static char buffer[9];
    std::time_t current_time = std::time(nullptr);
    std::tm* timestamp = std::localtime(&current_time);
    strftime(buffer, sizeof(buffer), "%H:%M:%S", timestamp);
    return buffer;
}

void Logger::LogMessage(const char* level, WORD color, const char* message, ...)
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

