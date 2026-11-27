// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboEmptyBinders3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

// Only the callback address is stored here. Its call signature is unknown.
using SboEmptyBinders3CleanupFunction = void();

struct SboEmptyBinders3SboBinding
{
    void* instance;
    SboEmptyBinders3CleanupFunction* cleanup;
};

struct SboEmptyBinders3EmptyBox
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
extern "C" unsigned char Table_1af0230[];
extern "C" SboEmptyBinders3CleanupFunction Cleanup_133b7c0;
extern "C" SboEmptyBinders3CleanupFunction Cleanup_1332030;
extern "C" const char Text_1acd8d0[];
extern "C" unsigned char Table_1aeffb0[];
extern "C" SboEmptyBinders3CleanupFunction Cleanup_133b7f0;
extern "C" SboEmptyBinders3CleanupFunction Cleanup_13320f0;
extern "C" unsigned char Table_1af0050[];
extern "C" SboEmptyBinders3CleanupFunction Cleanup_133b800;
extern "C" SboEmptyBinders3CleanupFunction Cleanup_1332130;
extern "C" unsigned char Table_1af0140[];
extern "C" SboEmptyBinders3CleanupFunction Cleanup_133b820;
extern "C" SboEmptyBinders3CleanupFunction Cleanup_13321b0;
extern "C" unsigned char Table_1af0000[];
extern "C" SboEmptyBinders3CleanupFunction Cleanup_133b830;
extern "C" SboEmptyBinders3CleanupFunction Cleanup_13321f0;
extern "C" unsigned char Table_1aefdd0[];
extern "C" SboEmptyBinders3CleanupFunction Cleanup_133b840;
extern "C" SboEmptyBinders3CleanupFunction Cleanup_1332230;
extern "C" unsigned char Table_1af00f0[];
extern "C" SboEmptyBinders3CleanupFunction Cleanup_133b860;
extern "C" SboEmptyBinders3CleanupFunction Cleanup_13322b0;
extern "C" unsigned char Table_1b03588[];
extern "C" SboEmptyBinders3CleanupFunction Cleanup_13abe90;
extern "C" SboEmptyBinders3CleanupFunction Cleanup_13a6bd0;
extern "C" unsigned char Table_1b05368[];
extern "C" SboEmptyBinders3CleanupFunction Cleanup_13b46b0;
extern "C" SboEmptyBinders3CleanupFunction Cleanup_13b2f60;
extern "C" unsigned char Table_1b15d40[];
extern "C" SboEmptyBinders3CleanupFunction Cleanup_1434940;
extern "C" SboEmptyBinders3CleanupFunction Cleanup_1431310;

struct SboEmptyBinders3
{
    static SboEmptyBinders3SboBinding Wrap1332be0(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders3SboBinding Wrap1332ef0(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders3SboBinding Wrap1332fb0(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders3SboBinding Wrap1333170(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders3SboBinding Wrap1333230(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders3SboBinding Wrap13332f0(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders3SboBinding Wrap13334b0(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders3SboBinding Wrap13a6fd0(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders3SboBinding Wrap13b32a0(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders3SboBinding Wrap1431a00(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap);
};
