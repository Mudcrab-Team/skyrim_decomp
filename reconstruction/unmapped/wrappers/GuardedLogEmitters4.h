// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// GuardedLogEmitters4, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
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

struct GuardedLogEmitters4
{
    static void Wrap141e090(void* unused, bool ok, const char* msg);
    static void Wrap141e110(void* unused, bool ok, const char* msg);
    static void Wrap142eab0(void* unused, bool ok, const char* msg);
    static void Wrap142eb30(void* unused, bool ok, const char* msg);
    static void Wrap1446690(void* unused, bool ok, const char* msg);
    static void Wrap1453a30(void* unused, bool ok, const char* msg);
    static void Wrap1453ab0(void* unused, bool ok, const char* msg);
    static void Wrap1453b30(void* unused, bool ok, const char* msg);
    static void Wrap1464490(void* unused, bool ok, const char* msg);
    static void Wrap1464510(void* unused, bool ok, const char* msg);
    static void Wrap1464590(void* unused, bool ok, const char* msg);
    static void Wrap1464610(void* unused, bool ok, const char* msg);
    static void Wrap1464690(void* unused, bool ok, const char* msg);
    static void Wrap1464710(void* unused, bool ok, const char* msg);
    static void Wrap1471950(void* unused, bool ok, const char* msg);
    static void Wrap147a440(void* unused, bool ok, const char* msg);
};
