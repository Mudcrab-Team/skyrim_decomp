// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboPayloadBinders6, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

// Only the callback address is stored here. Its call signature is unknown.
using SboPayloadBinders6CleanupFunction = void();

struct SboPayloadBinders6SboBinding
{
    void* instance;
    SboPayloadBinders6CleanupFunction* cleanup;
};

struct SboPayloadBinders6PayloadBox
{
    void* table;
    void* payload;
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" unsigned int gLogChannel_20d5024;
extern "C" bool LogFilter_128c360(unsigned int channel, int level);
extern "C" bool LogConsoleEn_128c380();
extern "C" int LogVerbosity_128c340(unsigned int channel);
extern "C" bool LogSinkEn_128c1a0(int level, unsigned int channel);
extern "C" void LogConsole_12586a0(int level, const char* fmt, ...);
extern "C" void LogSink_12586e0(int level, const char* fmt, ...);
extern "C" unsigned char Table_1b210c0[];
extern "C" unsigned char Table_1b210e0[];
extern "C" SboPayloadBinders6CleanupFunction Cleanup_1486c30;
extern "C" SboPayloadBinders6CleanupFunction Cleanup_147e020;
extern "C" const char Text_1acd8d0[];
extern "C" unsigned char Table_1b21180[];
extern "C" unsigned char Table_1b211a0[];
extern "C" SboPayloadBinders6CleanupFunction Cleanup_1486c40;
extern "C" SboPayloadBinders6CleanupFunction Cleanup_147e060;
extern "C" unsigned char Table_1b21340[];
extern "C" unsigned char Table_1b21360[];
extern "C" SboPayloadBinders6CleanupFunction Cleanup_1486c50;
extern "C" SboPayloadBinders6CleanupFunction Cleanup_147e0a0;
extern "C" unsigned char Table_1b21300[];
extern "C" unsigned char Table_1b21320[];
extern "C" SboPayloadBinders6CleanupFunction Cleanup_1486c60;
extern "C" SboPayloadBinders6CleanupFunction Cleanup_147e0e0;

struct SboPayloadBinders6
{
    static SboPayloadBinders6SboBinding Wrap147ec20(void** src, SboPayloadBinders6PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders6SboBinding Wrap147ed20(void** src, SboPayloadBinders6PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders6SboBinding Wrap147ee20(void** src, SboPayloadBinders6PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders6SboBinding Wrap147ef20(void** src, SboPayloadBinders6PayloadBox* buf, unsigned long long cap);
};
