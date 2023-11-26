//
// Created by h4mr3r on 25/11/2023.
//
#ifndef STREAMER_UTILITIES_H
#define STREAMER_UTILITIES_H

#include <iostream>
#include <string>
#include <Windows.h>

void Log(const std::wstring& message);
std::wstring ConvertToWString(const std::string& str);


#endif //STREAMER_UTILITIES_H
