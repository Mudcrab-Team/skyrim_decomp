// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// NullCheckedLogForwarders, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
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
extern "C" const char Text_1acd328[];
extern "C" unsigned long long StrLen_128eb90(const char* str);
extern "C" void Forward_1270500(void* ctx, const char* str, unsigned long long len);
extern "C" void Forward_1259dd0(void* ctx, const char* str, unsigned long long len);
extern "C" void Forward_1270a00(void* ctx, const char* str, unsigned long long len);
extern "C" void Forward_1270cc0(void* ctx, const char* str, unsigned long long len);
extern "C" void Forward_1270740(void* ctx, const char* str, unsigned long long len);
extern "C" void Forward_131b000(void* ctx, const char* str, unsigned long long len);
extern "C" void Forward_128baf0(void* ctx, const char* str, unsigned long long len);
extern "C" unsigned long long StrLen_128ebf0(const char* str);
extern "C" void Forward_12ddef0(void* ctx, const char* str, unsigned long long len);
extern "C" void Forward_12716a0(void* ctx, const char* str, unsigned long long len);
extern "C" void Forward_1379590(void* ctx, const char* str, unsigned long long len);
extern "C" void Forward_13d4d20(void* ctx, const char* str, unsigned long long len);
extern "C" void Forward_12fb060(void* ctx, const char* str, unsigned long long len);
extern "C" void Forward_13e5ca0(void* ctx, const char* str, unsigned long long len);
extern "C" void Forward_12ae090(void* ctx, const char* str, unsigned long long len);
extern "C" void Forward_1463e90(void* ctx, const char* str, unsigned long long len);

struct NullCheckedLogForwarders
{
    static void Wrap1270450(void* ctx, const char* str);
    static void Wrap1270690(void* ctx, const char* str);
    static void Wrap1270950(void* ctx, const char* str);
    static void Wrap1270c10(void* ctx, const char* str);
    static void Wrap12f5c70(void* ctx, const char* str);
    static void Wrap131af50(void* ctx, const char* str);
    static void Wrap1328a50(void* ctx, const char* str);
    static void Wrap134a850(void* ctx, const char* str);
    static void Wrap1371f50(void* ctx, const char* str);
    static void Wrap13d4bc0(void* ctx, const char* str);
    static void Wrap13d4c70(void* ctx, const char* str);
    static void Wrap13d4f30(void* ctx, const char* str);
    static void Wrap13e5bf0(void* ctx, const char* str);
    static void Wrap1458f90(void* ctx, const char* str);
    static void Wrap1463de0(void* ctx, const char* str);
};
