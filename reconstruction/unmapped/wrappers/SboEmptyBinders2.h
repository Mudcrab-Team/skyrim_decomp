// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboEmptyBinders2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

// Only the callback address is stored here. Its call signature is unknown.
using SboEmptyBinders2CleanupFunction = void();

struct SboEmptyBinders2SboBinding
{
    void* instance;
    SboEmptyBinders2CleanupFunction* cleanup;
};

struct SboEmptyBinders2EmptyBox
{
    void* table;
};

extern "C" void* (*gAllocFn_3356368)(unsigned long long size);
extern "C" unsigned int gLogChannel_20d5024;
extern "C" bool LogFilter_128c360(unsigned int channel, int level);
extern "C" bool LogConsoleEn_128c380();
extern "C" int LogVerbosity_128c340(unsigned int channel);
extern "C" bool LogSinkEn_128c1a0(int level, unsigned int channel);
extern "C" void LogConsole_12586a0(int level, const char* fmt, ...);
extern "C" void LogSink_12586e0(int level, const char* fmt, ...);
extern "C" unsigned char Table_1ae02a0[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12cbae0;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12c6d20;
extern "C" const char Text_1acd8d0[];
extern "C" unsigned char Table_1ae0430[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12cbb00;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12c6da0;
extern "C" unsigned char Table_1ae0200[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12cbb10;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12c6de0;
extern "C" unsigned char Table_1ae02f0[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12cbb20;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12c6e20;
extern "C" unsigned char Table_1ae01b0[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12cbb30;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12c6e60;
extern "C" unsigned char Table_1ae0390[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12cbb40;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12c6ea0;
extern "C" unsigned char Table_1ae0480[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12cbb50;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12c6ee0;
extern "C" unsigned char Table_1ae03e0[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12cbb60;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12c6f20;
extern "C" unsigned char Table_1ae0340[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12cbb70;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12c6f60;
extern "C" unsigned char Table_1ae0110[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12cbb80;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12c6fa0;
extern "C" unsigned char Table_1ae0160[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12cbb90;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12c6fe0;
extern "C" unsigned char Table_1ae00c0[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12cbbb0;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12c7060;
extern "C" unsigned char Table_1ae0250[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12cbbc0;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12c70a0;
extern "C" unsigned char Table_1ae0570[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12cbbd0;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12c70e0;
extern "C" unsigned char Table_1ae1890[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12d3aa0;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12d0700;
extern "C" unsigned char Table_1ae6c68[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12fd0a0;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12f7d60;
extern "C" unsigned char Table_1ae6ca8[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12fd0c0;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_12f7de0;
extern "C" unsigned char Table_1ae7c80[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_13062d0;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_13029f0;
extern "C" unsigned char Table_1ae89f0[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_130ae60;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_1309df0;
extern "C" unsigned char Table_1aefce0[];
extern "C" SboEmptyBinders2CleanupFunction Cleanup_133b7b0;
extern "C" SboEmptyBinders2CleanupFunction Cleanup_1331ff0;

struct SboEmptyBinders2
{
    static SboEmptyBinders2SboBinding Wrap12c7120(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12c72e0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12c73a0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12c7460(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12c7520(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12c75e0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12c76a0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12c7760(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12c7820(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12c78e0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12c79a0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12c7b60(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12c7c20(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12c7ce0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12d0a80(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12f8210(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap12f83d0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap1302a30(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap1309e70(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders2SboBinding Wrap1332b20(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap);
};
