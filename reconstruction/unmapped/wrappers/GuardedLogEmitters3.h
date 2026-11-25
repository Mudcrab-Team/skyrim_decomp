// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// GuardedLogEmitters3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
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

struct GuardedLogEmitters3
{
    static void Wrap1379df0(void* unused, bool ok, const char* msg);
    static void Wrap137de80(void* unused, bool ok, const char* msg);
    static void Wrap137df00(void* unused, bool ok, const char* msg);
    static void Wrap1384950(void* unused, bool ok, const char* msg);
    static void Wrap1393650(void* unused, bool ok, const char* msg);
    static void Wrap13bb270(void* unused, bool ok, const char* msg);
    static void Wrap13d0030(void* unused, bool ok, const char* msg);
    static void Wrap13d5710(void* unused, bool ok, const char* msg);
    static void Wrap13d5790(void* unused, bool ok, const char* msg);
    static void Wrap13d5810(void* unused, bool ok, const char* msg);
    static void Wrap13d5890(void* unused, bool ok, const char* msg);
    static void Wrap13de030(void* unused, bool ok, const char* msg);
    static void Wrap13e0240(void* unused, bool ok, const char* msg);
    static void Wrap13e02c0(void* unused, bool ok, const char* msg);
    static void Wrap13e6060(void* unused, bool ok, const char* msg);
    static void Wrap13fc5a0(void* unused, bool ok, const char* msg);
    static void Wrap1407320(void* unused, bool ok, const char* msg);
    static void Wrap1410be0(void* unused, bool ok, const char* msg);
    static void Wrap1410c60(void* unused, bool ok, const char* msg);
    static void Wrap141e010(void* unused, bool ok, const char* msg);
};
