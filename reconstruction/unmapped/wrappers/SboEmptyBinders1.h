// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboEmptyBinders1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

// Only the callback address is stored here. Its call signature is unknown.
using SboEmptyBinders1CleanupFunction = void();

struct SboEmptyBinders1SboBinding
{
    void* instance;
    SboEmptyBinders1CleanupFunction* cleanup;
};

struct SboEmptyBinders1EmptyBox
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
extern "C" unsigned char Table_1acd6d8[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_125a830;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12585f0;
extern "C" const char Text_1acd8d0[];
extern "C" unsigned char Table_1acd728[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_125a840;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_1258630;
extern "C" unsigned char Table_1ad1c38[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_1284e20;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_127f240;
extern "C" unsigned char Table_1ad1cd8[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_1284e60;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_127f340;
extern "C" unsigned char Table_1ad1c88[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_1284e70;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_127f380;
extern "C" unsigned char Table_1ad4a88[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_129b2f0;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_1299110;
extern "C" unsigned char Table_1ad4ad8[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_129b310;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_1299190;
extern "C" unsigned char Table_1ad5888[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_129f260;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_129d650;
extern "C" unsigned char Table_1ad8b80[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12b1120;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12a90e0;
extern "C" unsigned char Table_1ad89a0[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12b1130;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12a9120;
extern "C" unsigned char Table_1ad8a40[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12b1160;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12a91e0;
extern "C" unsigned char Table_1ad8c20[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12b1190;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12a92a0;
extern "C" unsigned char Table_1addcc8[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12bd540;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12bace0;
extern "C" unsigned char Table_1adde58[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12bd550;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12bad20;
extern "C" unsigned char Table_1addd18[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12bd560;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12bad60;
extern "C" unsigned char Table_1adddb8[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12bd570;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12bada0;
extern "C" unsigned char Table_1addd68[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12bd580;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12bade0;
extern "C" unsigned char Table_1adde08[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12bd590;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12bae20;
extern "C" unsigned char Table_1addea8[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12bd5b0;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12baea0;
extern "C" unsigned char Table_1addef8[];
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12bd5c0;
extern "C" SboEmptyBinders1CleanupFunction Cleanup_12baee0;

struct SboEmptyBinders1
{
    static SboEmptyBinders1SboBinding Wrap1258810(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap12588d0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap127f3c0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap127f800(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap127f8c0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap12991d0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap1299390(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap129d7d0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap12a9520(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap12a95e0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap12a98a0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap12a9b60(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap12baf20(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap12bafe0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap12bb0a0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap12bb160(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap12bb220(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap12bb2e0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap12bb4b0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
    static SboEmptyBinders1SboBinding Wrap12bb570(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap);
};
