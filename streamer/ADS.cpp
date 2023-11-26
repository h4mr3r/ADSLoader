//
// Created by h4mr3r on 25/11/2023.
//

#include "ADS.h"
#include "utilities.h"


char* bacon;
size_t streamSize;

std::vector<std::wstring> getAlternateDataStreamNames(const std::wstring& fileName) {
    std::vector<std::wstring> streamNames;
    WIN32_FIND_STREAM_DATA streamData;
    HANDLE streamHandle = FindFirstStreamW(fileName.c_str(), FindStreamInfoStandard, &streamData, 0);

    if (streamHandle != INVALID_HANDLE_VALUE) {
        do {
            streamNames.emplace_back(streamData.cStreamName);
        } while (FindNextStreamW(streamHandle, &streamData) != 0);

        FindClose(streamHandle);
    }
    return streamNames;
}

size_t getDataFromTheStream(const std::wstring& fileName, const std::wstring& streamName) {
    std::wstring fullStreamName = fileName + streamName;
    HANDLE fileHandle = CreateFileW(fullStreamName.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (fileHandle == INVALID_HANDLE_VALUE) {
        Log( L"Cannot open stream: " +  streamName) ;
        return 0;
    }

    DWORD bytesRead;

    // Calculate the size of the stream
    DWORD fileSize = GetFileSize(fileHandle, NULL);

    if (fileSize == INVALID_FILE_SIZE) {
        Log( L"Failed to determine the size of the stream.");
        CloseHandle(fileHandle);
        return 0;
    }

    streamSize = fileSize;

    bacon = new char[streamSize];
    if (!bacon) {
        Log(L"Memory allocation for bacon failed");
        CloseHandle(fileHandle);
        return 0;
    }

    // Read data from the stream to the array
    if (!ReadFile(fileHandle, bacon, streamSize, &bytesRead, NULL) || bytesRead != streamSize) {
        Log( L"Failed to read the stream.");
        delete[] bacon;
        CloseHandle(fileHandle);
        return 0;
    }

    CloseHandle(fileHandle);
    return streamSize;  // Return the size of the stream
}