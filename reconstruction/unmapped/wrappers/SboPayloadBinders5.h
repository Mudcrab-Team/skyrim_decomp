// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboPayloadBinders5, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

// Only the callback address is stored here. Its call signature is unknown.
using SboPayloadBinders5CleanupFunction = void();

struct SboPayloadBinders5SboBinding
{
    void* instance;
    SboPayloadBinders5CleanupFunction* cleanup;
};

struct SboPayloadBinders5PayloadBox
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
extern "C" unsigned char Table_1b1db08[];
extern "C" unsigned char Table_1b1db28[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_146b6e0;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_145ccf0;
extern "C" const char Text_1acd8d0[];
extern "C" unsigned char Table_1b1dc48[];
extern "C" unsigned char Table_1b1dc68[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_146b6f0;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_145cd30;
extern "C" unsigned char Table_1b1d8c0[];
extern "C" unsigned char Table_1b1d8e0[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_146b700;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_145cd70;
extern "C" unsigned char Table_1b1d900[];
extern "C" unsigned char Table_1b1d920[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_146b710;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_145cdb0;
extern "C" unsigned char Table_1b1da88[];
extern "C" unsigned char Table_1b1daa8[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_146b720;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_145cdf0;
extern "C" unsigned char Table_1b1d980[];
extern "C" unsigned char Table_1b1d9a0[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_146b730;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_145ce30;
extern "C" unsigned char Table_1b1db48[];
extern "C" unsigned char Table_1b1db68[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_146b740;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_145ce70;
extern "C" unsigned char Table_1b1dc08[];
extern "C" unsigned char Table_1b1dc28[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_146b750;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_145ceb0;
extern "C" unsigned char Table_1b1db88[];
extern "C" unsigned char Table_1b1dba8[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_146b760;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_145cef0;
extern "C" unsigned char Table_1b1dbc8[];
extern "C" unsigned char Table_1b1dbe8[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_146b770;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_145cf30;
extern "C" unsigned char Table_1b1def8[];
extern "C" unsigned char Table_1b1df18[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_146fd10;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_146ee50;
extern "C" unsigned char Table_1b1e1b8[];
extern "C" unsigned char Table_1b1e1d8[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_1471040;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_146fea0;
extern "C" unsigned char Table_1b1e178[];
extern "C" unsigned char Table_1b1e198[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_1471050;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_146fee0;
extern "C" unsigned char Table_1b21200[];
extern "C" unsigned char Table_1b21220[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_1486bb0;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_147de20;
extern "C" unsigned char Table_1b21380[];
extern "C" unsigned char Table_1b213a0[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_1486bd0;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_147dea0;
extern "C" unsigned char Table_1b21240[];
extern "C" unsigned char Table_1b21260[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_1486be0;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_147dee0;
extern "C" unsigned char Table_1b21100[];
extern "C" unsigned char Table_1b21120[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_1486bf0;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_147df20;
extern "C" unsigned char Table_1b211c0[];
extern "C" unsigned char Table_1b211e0[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_1486c00;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_147df60;
extern "C" unsigned char Table_1b212c0[];
extern "C" unsigned char Table_1b212e0[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_1486c10;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_147dfa0;
extern "C" unsigned char Table_1b21140[];
extern "C" unsigned char Table_1b21160[];
extern "C" SboPayloadBinders5CleanupFunction Cleanup_1486c20;
extern "C" SboPayloadBinders5CleanupFunction Cleanup_147dfe0;

struct SboPayloadBinders5
{
    static SboPayloadBinders5SboBinding Wrap145d500(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap145d600(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap145d700(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap145d800(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap145d900(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap145da00(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap145db00(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap145dc00(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap145dd00(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap145de00(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap146ee90(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap146ff20(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap1470020(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap147e420(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap147e620(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap147e720(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap147e820(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap147e920(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap147ea20(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
    static SboPayloadBinders5SboBinding Wrap147eb20(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap);
};
