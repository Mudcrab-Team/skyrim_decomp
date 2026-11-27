// Source exposure: mixed (pinned image, RTTI and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original reconstruction of copyable callable construction.
// SboPayloadBinders2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; wrapper names and capture identities inferred.
// Adapted bodies: none
#pragma once
#include "CopyableCallable.h"

// Only the callback address is stored here. Its call signature is unknown.
using SboPayloadBinders2CleanupFunction = void();

struct SboPayloadBinders2SboBinding
{
    void* instance;
    SboPayloadBinders2CleanupFunction* cleanup;
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" unsigned int gLogChannel_20d5024;
extern "C" bool LogFilter_128c360(unsigned int channel, int level);
extern "C" bool LogConsoleEn_128c380();
extern "C" int LogVerbosity_128c340(unsigned int channel);
extern "C" bool LogSinkEn_128c1a0(int level, unsigned int channel);
extern "C" void LogConsole_12586a0(int level, const char* fmt, ...);
extern "C" void LogSink_12586e0(int level, const char* fmt, ...);
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12ceb90;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12cd3d0;
extern "C" const char Text_1acd8d0[];
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d3a70;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d0640;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d3a80;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d0680;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d3a90;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d06c0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d3ab0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12d0740;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12ec6f0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12eb380;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12ec700;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12eb3c0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12f07e0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12ede10;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12f07f0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12ede50;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12fd0b0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12f7da0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12fd0d0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12f7e20;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12fd0e0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_12f7e60;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_130f110;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_130b7e0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_130f120;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_130b820;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_133b750;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_1331e70;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_133b770;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_1331ef0;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_133b810;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_1332170;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_133b850;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_1332270;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_1388500;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_1386080;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_1398740;
extern "C" SboPayloadBinders2CleanupFunction Cleanup_138bc50;

struct SboPayloadBinders2
{
    template <class Capture, SboPayloadBinders2CleanupFunction* InlineCleanup, SboPayloadBinders2CleanupFunction* HeapCleanup>
    static SboPayloadBinders2SboBinding Bind(const Capture& source, void* storage, unsigned long long capacity);
};
