// Source exposure: mixed (pinned image, RTTI and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original reconstruction of copyable callable construction.
// SboPayloadBinders1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; wrapper names and capture identities inferred.
// Adapted bodies: none
#pragma once
#include "CopyableCallable.h"

// Only the callback address is stored here. Its call signature is unknown.
using SboPayloadBinders1CleanupFunction = void();

struct SboPayloadBinders1SboBinding
{
    void* instance;
    SboPayloadBinders1CleanupFunction* cleanup;
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" unsigned int gLogChannel_20d5024;
extern "C" bool LogFilter_128c360(unsigned int channel, int level);
extern "C" bool LogConsoleEn_128c380();
extern "C" int LogVerbosity_128c340(unsigned int channel);
extern "C" bool LogSinkEn_128c1a0(int level, unsigned int channel);
extern "C" void LogConsole_12586a0(int level, const char* fmt, ...);
extern "C" void LogSink_12586e0(int level, const char* fmt, ...);
extern "C" SboPayloadBinders1CleanupFunction Cleanup_125a820;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12585b0;
extern "C" const char Text_1acd8d0[];
extern "C" SboPayloadBinders1CleanupFunction Cleanup_1284e40;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_127f2c0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_1295f60;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_1293760;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_1295f70;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12937a0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_129b300;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_1299150;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_129f250;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_129d610;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_129f270;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_129d690;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b1110;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a90a0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b1140;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a9160;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b1150;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a91a0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b1170;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a9220;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b1180;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a9260;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b11b0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a9320;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b11c0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a9360;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b11d0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a93a0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b11e0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12a93e0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b9100;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12b8ba0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12c2570;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12c1c80;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12cbaf0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12c6d60;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12cbba0;
extern "C" SboPayloadBinders1CleanupFunction Cleanup_12c7020;

struct SboPayloadBinders1
{
    template <class Capture, SboPayloadBinders1CleanupFunction* InlineCleanup, SboPayloadBinders1CleanupFunction* HeapCleanup>
    static SboPayloadBinders1SboBinding Bind(const Capture& source, void* storage, unsigned long long capacity);
};
