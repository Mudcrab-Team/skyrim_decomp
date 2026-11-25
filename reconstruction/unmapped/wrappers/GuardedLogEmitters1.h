// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// GuardedLogEmitters1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
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

struct GuardedLogEmitters1
{
    static void Wrap125a220(void* unused, bool ok, const char* msg);
    static void Wrap125a2a0(void* unused, bool ok, const char* msg);
    static void Wrap125a320(void* unused, bool ok, const char* msg);
    static void Wrap125a3a0(void* unused, bool ok, const char* msg);
    static void Wrap125a420(void* unused, bool ok, const char* msg);
    static void Wrap125a4a0(void* unused, bool ok, const char* msg);
    static void Wrap125a520(void* unused, bool ok, const char* msg);
    static void Wrap1271bd0(void* unused, bool ok, const char* msg);
    static void Wrap1271c50(void* unused, bool ok, const char* msg);
    static void Wrap1271cd0(void* unused, bool ok, const char* msg);
    static void Wrap1271d50(void* unused, bool ok, const char* msg);
    static void Wrap1271dd0(void* unused, bool ok, const char* msg);
    static void Wrap1271e50(void* unused, bool ok, const char* msg);
    static void Wrap1271ed0(void* unused, bool ok, const char* msg);
    static void Wrap1271f50(void* unused, bool ok, const char* msg);
    static void Wrap1271fd0(void* unused, bool ok, const char* msg);
    static void Wrap1272050(void* unused, bool ok, const char* msg);
    static void Wrap12720d0(void* unused, bool ok, const char* msg);
    static void Wrap1272150(void* unused, bool ok, const char* msg);
    static void Wrap12721d0(void* unused, bool ok, const char* msg);
};
