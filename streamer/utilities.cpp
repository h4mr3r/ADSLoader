//
// Created by h4mr3r on 25/11/2023.
//

#include "utilities.h"

void Log(const std::wstring& message) {
    // Get the current time for a timestamp
    SYSTEMTIME st;
    GetLocalTime(&st);
    char timestamp[100];
    sprintf(timestamp, "%04d-%02d-%02d %02d:%02d:%02d",
            st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);

    // Format the log message
    std::wstring logMessage = L"[" + ConvertToWString(timestamp) + L"] " + message + L"\n";

    // Get a handle to the console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole != INVALID_HANDLE_VALUE) {
        // Write the message to the console
        DWORD written;
        WriteConsoleW(hConsole, logMessage.c_str(), logMessage.size(), &written, NULL);
    }
}

std::wstring ConvertToWString(const std::string& str) {
    if (str.empty()) {
        return {};
    }
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}

