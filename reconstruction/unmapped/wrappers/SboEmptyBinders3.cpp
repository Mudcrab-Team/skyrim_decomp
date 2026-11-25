// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboEmptyBinders3, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x1332be0 ?Wrap1332be0@SboEmptyBinders3@@SA?AUSboEmptyBinders3SboBinding@@PEAXPEAUSboEmptyBinders3EmptyBox@@_K@Z
// CI hash: 0x1332ef0 ?Wrap1332ef0@SboEmptyBinders3@@SA?AUSboEmptyBinders3SboBinding@@PEAXPEAUSboEmptyBinders3EmptyBox@@_K@Z
// CI hash: 0x1332fb0 ?Wrap1332fb0@SboEmptyBinders3@@SA?AUSboEmptyBinders3SboBinding@@PEAXPEAUSboEmptyBinders3EmptyBox@@_K@Z
// CI hash: 0x1333170 ?Wrap1333170@SboEmptyBinders3@@SA?AUSboEmptyBinders3SboBinding@@PEAXPEAUSboEmptyBinders3EmptyBox@@_K@Z
// CI hash: 0x1333230 ?Wrap1333230@SboEmptyBinders3@@SA?AUSboEmptyBinders3SboBinding@@PEAXPEAUSboEmptyBinders3EmptyBox@@_K@Z
// CI hash: 0x13332f0 ?Wrap13332f0@SboEmptyBinders3@@SA?AUSboEmptyBinders3SboBinding@@PEAXPEAUSboEmptyBinders3EmptyBox@@_K@Z
// CI hash: 0x13334b0 ?Wrap13334b0@SboEmptyBinders3@@SA?AUSboEmptyBinders3SboBinding@@PEAXPEAUSboEmptyBinders3EmptyBox@@_K@Z
// CI hash: 0x13a6fd0 ?Wrap13a6fd0@SboEmptyBinders3@@SA?AUSboEmptyBinders3SboBinding@@PEAXPEAUSboEmptyBinders3EmptyBox@@_K@Z
// CI hash: 0x13b32a0 ?Wrap13b32a0@SboEmptyBinders3@@SA?AUSboEmptyBinders3SboBinding@@PEAXPEAUSboEmptyBinders3EmptyBox@@_K@Z
// CI hash: 0x1431a00 ?Wrap1431a00@SboEmptyBinders3@@SA?AUSboEmptyBinders3SboBinding@@PEAXPEAUSboEmptyBinders3EmptyBox@@_K@Z
// 0x1332be0 SboEmptyBinders3::Wrap1332be0
// 0x1332ef0 SboEmptyBinders3::Wrap1332ef0
// 0x1332fb0 SboEmptyBinders3::Wrap1332fb0
// 0x1333170 SboEmptyBinders3::Wrap1333170
// 0x1333230 SboEmptyBinders3::Wrap1333230
// 0x13332f0 SboEmptyBinders3::Wrap13332f0
// 0x13334b0 SboEmptyBinders3::Wrap13334b0
// 0x13a6fd0 SboEmptyBinders3::Wrap13a6fd0
// 0x13b32a0 SboEmptyBinders3::Wrap13b32a0
// 0x1431a00 SboEmptyBinders3::Wrap1431a00
#include "SboEmptyBinders3.h"

SboEmptyBinders3SboBinding SboEmptyBinders3::Wrap1332be0(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1af0230;
        result.instance = buf;
        result.cleanup = Cleanup_133b7c0;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboEmptyBinders3EmptyBox* heap = static_cast<SboEmptyBinders3EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1af0230;
    result.cleanup = Cleanup_1332030;
    return result;
}

SboEmptyBinders3SboBinding SboEmptyBinders3::Wrap1332ef0(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1aeffb0;
        result.instance = buf;
        result.cleanup = Cleanup_133b7f0;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboEmptyBinders3EmptyBox* heap = static_cast<SboEmptyBinders3EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1aeffb0;
    result.cleanup = Cleanup_13320f0;
    return result;
}

SboEmptyBinders3SboBinding SboEmptyBinders3::Wrap1332fb0(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1af0050;
        result.instance = buf;
        result.cleanup = Cleanup_133b800;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboEmptyBinders3EmptyBox* heap = static_cast<SboEmptyBinders3EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1af0050;
    result.cleanup = Cleanup_1332130;
    return result;
}

SboEmptyBinders3SboBinding SboEmptyBinders3::Wrap1333170(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1af0140;
        result.instance = buf;
        result.cleanup = Cleanup_133b820;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboEmptyBinders3EmptyBox* heap = static_cast<SboEmptyBinders3EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1af0140;
    result.cleanup = Cleanup_13321b0;
    return result;
}

SboEmptyBinders3SboBinding SboEmptyBinders3::Wrap1333230(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1af0000;
        result.instance = buf;
        result.cleanup = Cleanup_133b830;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboEmptyBinders3EmptyBox* heap = static_cast<SboEmptyBinders3EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1af0000;
    result.cleanup = Cleanup_13321f0;
    return result;
}

SboEmptyBinders3SboBinding SboEmptyBinders3::Wrap13332f0(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1aefdd0;
        result.instance = buf;
        result.cleanup = Cleanup_133b840;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboEmptyBinders3EmptyBox* heap = static_cast<SboEmptyBinders3EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1aefdd0;
    result.cleanup = Cleanup_1332230;
    return result;
}

SboEmptyBinders3SboBinding SboEmptyBinders3::Wrap13334b0(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1af00f0;
        result.instance = buf;
        result.cleanup = Cleanup_133b860;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboEmptyBinders3EmptyBox* heap = static_cast<SboEmptyBinders3EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1af00f0;
    result.cleanup = Cleanup_13322b0;
    return result;
}

SboEmptyBinders3SboBinding SboEmptyBinders3::Wrap13a6fd0(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b03588;
        result.instance = buf;
        result.cleanup = Cleanup_13abe90;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboEmptyBinders3EmptyBox* heap = static_cast<SboEmptyBinders3EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b03588;
    result.cleanup = Cleanup_13a6bd0;
    return result;
}

SboEmptyBinders3SboBinding SboEmptyBinders3::Wrap13b32a0(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b05368;
        result.instance = buf;
        result.cleanup = Cleanup_13b46b0;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboEmptyBinders3EmptyBox* heap = static_cast<SboEmptyBinders3EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b05368;
    result.cleanup = Cleanup_13b2f60;
    return result;
}

SboEmptyBinders3SboBinding SboEmptyBinders3::Wrap1431a00(void* unused, SboEmptyBinders3EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders3SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b15d40;
        result.instance = buf;
        result.cleanup = Cleanup_1434940;
        return result;
    }
    if (!LogFilter_128c360(gLogChannel_20d5024, 0))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5024) <= 0)
        {
            LogConsole_12586a0(0, Text_1acd8d0, 16ull);
        }
        if (LogSinkEn_128c1a0(0, gLogChannel_20d5024))
        {
            LogSink_12586e0(0, Text_1acd8d0, 16ull);
        }
    }
    SboEmptyBinders3EmptyBox* heap = static_cast<SboEmptyBinders3EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b15d40;
    result.cleanup = Cleanup_1431310;
    return result;
}
