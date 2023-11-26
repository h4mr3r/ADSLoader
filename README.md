# ADS simple loader

PoC project for loading shellcode into the memory using Alternate Data streams

## ADSadder

Program adds the alternate data stream to the selected file
##### Usage:
    ADSadder.exe <sourceFile> <targetFile> <streamName>

## streamer

Program executes the alternate data stream added by the ADSadder. It does not use default :$DATA but the next one.
