// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// GuardedLogEmitters2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

extern "C" unsigned int gLogChannel_20d5024;
extern "C" bool LogFilter_128c360(unsigned int channel, int level);
extern "C" bool LogConsoleEn_128c380();
extern "C" int LogVerbosity_128c340(unsigned int channel);
extern "C" bool LogSinkEn_128c1a0(int level, unsigned int channel);
extern "C" void LogConsole_12586a0(int level, const char* fmt, ...);
extern "C" void LogSink_12586e0(int level, const char* fmt, ...);
extern "C" const char Text_1acd380[];

struct GuardedLogEmitters2
{
    static void Wrap1272250(void* unused, bool ok, const char* msg);
    static void Wrap12722d0(void* unused, bool ok, const char* msg);
    static void Wrap1283470(void* unused, bool ok, const char* msg);
    static void Wrap128f9d0(void* unused, bool ok, const char* msg);
    static void Wrap12ae2a0(void* unused, bool ok, const char* msg);
    static void Wrap12d28f0(void* unused, bool ok, const char* msg);
    static void Wrap12d2970(void* unused, bool ok, const char* msg);
    static void Wrap12de130(void* unused, bool ok, const char* msg);
    static void Wrap12de1b0(void* unused, bool ok, const char* msg);
    static void Wrap12de230(void* unused, bool ok, const char* msg);
    static void Wrap12fb4a0(void* unused, bool ok, const char* msg);
    static void Wrap1300da0(void* unused, bool ok, const char* msg);
    static void Wrap1300e20(void* unused, bool ok, const char* msg);
    static void Wrap1304bd0(void* unused, bool ok, const char* msg);
    static void Wrap1308420(void* unused, bool ok, const char* msg);
    static void Wrap1318770(void* unused, bool ok, const char* msg);
    static void Wrap131b190(void* unused, bool ok, const char* msg);
    static void Wrap131b210(void* unused, bool ok, const char* msg);
    static void Wrap1347570(void* unused, bool ok, const char* msg);
    static void Wrap134a9a0(void* unused, bool ok, const char* msg);
};
