//
// Created by h4mr3r on 25/11/2023.
//

#ifndef STREAMER_ADS_H
#define STREAMER_ADS_H
#pragma once
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>


extern char* bacon;
extern size_t streamSize;

std::vector<std::wstring> getAlternateDataStreamNames(const std::wstring& fileName);
size_t getDataFromTheStream(const std::wstring& fileName, const std::wstring& streamName);
#endif //STREAMER_ADS_H
