// Source exposure: mixed (pinned image, RTTI and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: original reconstruction of copyable callable construction.
// SboPayloadBinders3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; wrapper names and capture identities inferred.
// Adapted bodies: none
#pragma once
#include "CopyableCallable.h"

// Only the callback address is stored here. Its call signature is unknown.
using SboPayloadBinders3CleanupFunction = void();

struct SboPayloadBinders3SboBinding
{
    void* instance;
    SboPayloadBinders3CleanupFunction* cleanup;
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" unsigned int gLogChannel_20d5024;
extern "C" bool LogFilter_128c360(unsigned int channel, int level);
extern "C" bool LogConsoleEn_128c380();
extern "C" int LogVerbosity_128c340(unsigned int channel);
extern "C" bool LogSinkEn_128c1a0(int level, unsigned int channel);
extern "C" void LogConsole_12586a0(int level, const char* fmt, ...);
extern "C" void LogSink_12586e0(int level, const char* fmt, ...);
extern "C" SboPayloadBinders3CleanupFunction Cleanup_1398750;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_138bc90;
extern "C" const char Text_1acd8d0[];
extern "C" SboPayloadBinders3CleanupFunction Cleanup_1398760;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_138bcd0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_1398780;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_138bd50;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a5bf0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a4130;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a5c00;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a4170;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a5c10;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a41b0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13abe80;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a6b90;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13abeb0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a6c50;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13abec0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a6c90;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13abed0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a6cd0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13abee0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13a6d10;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13af5c0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13aedc0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b0010;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13af8b0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b0c60;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b0260;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b16e0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b0f20;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b2110;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b1920;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b2af0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b2330;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b46a0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b2f20;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b5dd0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b4e80;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b5de0;
extern "C" SboPayloadBinders3CleanupFunction Cleanup_13b4ec0;

struct SboPayloadBinders3
{
    template <class Capture, SboPayloadBinders3CleanupFunction* InlineCleanup, SboPayloadBinders3CleanupFunction* HeapCleanup>
    static SboPayloadBinders3SboBinding Bind(const Capture& source, void* storage, unsigned long long capacity);
};
