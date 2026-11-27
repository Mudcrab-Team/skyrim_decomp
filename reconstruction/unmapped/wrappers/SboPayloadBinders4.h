// Source exposure: mixed (pinned image, RTTI and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original reconstruction of copyable callable construction.
// SboPayloadBinders4, helper structs, methods and referenced symbols: GUESS(low) STANDIN; wrapper names and capture identities inferred.
// Adapted bodies: none
#pragma once
#include "CopyableCallable.h"

// Only the callback address is stored here. Its call signature is unknown.
using SboPayloadBinders4CleanupFunction = void();

struct SboPayloadBinders4SboBinding
{
    void* instance;
    SboPayloadBinders4CleanupFunction* cleanup;
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" unsigned int gLogChannel_20d5024;
extern "C" bool LogFilter_128c360(unsigned int channel, int level);
extern "C" bool LogConsoleEn_128c380();
extern "C" int LogVerbosity_128c340(unsigned int channel);
extern "C" bool LogSinkEn_128c1a0(int level, unsigned int channel);
extern "C" void LogConsole_12586a0(int level, const char* fmt, ...);
extern "C" void LogSink_12586e0(int level, const char* fmt, ...);
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13b6db0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13b61a0;
extern "C" const char Text_1acd8d0[];
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13b7860;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13b7010;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c6760;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c5ea0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c7360;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c6a10;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c7f60;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c7610;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c8a10;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c81c0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c94a0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c8c60;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13ca060;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13c9750;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13caa40;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13ca280;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13cb310;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_13cac10;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_14224a0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1421bb0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1423ea0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_14233d0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_14348f0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_14311d0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1434900;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1431210;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1434910;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1431250;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1434920;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1431290;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_1434930;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_14312d0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_146b6b0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_145cc30;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_146b6c0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_145cc70;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_146b6d0;
extern "C" SboPayloadBinders4CleanupFunction Cleanup_145ccb0;

struct SboPayloadBinders4
{
    template <class Capture, SboPayloadBinders4CleanupFunction* InlineCleanup, SboPayloadBinders4CleanupFunction* HeapCleanup>
    static SboPayloadBinders4SboBinding Bind(const Capture& source, void* storage, unsigned long long capacity);
};
