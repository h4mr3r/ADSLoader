#include <windows.h>
#include <fstream>
#include <iostream>

void AppendToAlternateDataStream(const std::string& sourceFile, const std::string& targetFile, const std::string& streamName) {
    // Create the path for the alternate data stream
    std::string adsPath = targetFile + ":" + streamName;

    // Open the source file
    std::ifstream src(sourceFile, std::ios::binary);
    if (!src) {
        std::cerr << "Could not open source file." << std::endl;
        return;
    }

    // Open the alternate data stream
    std::ofstream dst(adsPath, std::ios::binary);
    if (!dst) {
        std::cerr << "Could not open alternate data stream." << std::endl;
        return;
    }

    // Copy the data
    dst << src.rdbuf();

    src.close();
    dst.close();
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <sourceFile> <targetFile> <streamName>" << std::endl;
        return 1;
    }

    const std::string sourceFile = argv[1];
    const std::string targetFile = argv[2];
    const std::string streamName = argv[3];

    AppendToAlternateDataStream(sourceFile, targetFile, streamName);

    return 0;
}
