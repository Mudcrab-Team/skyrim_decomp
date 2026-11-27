// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboEmptyBinders2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x12c7120 ?Wrap12c7120@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12c72e0 ?Wrap12c72e0@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12c73a0 ?Wrap12c73a0@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12c7460 ?Wrap12c7460@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12c7520 ?Wrap12c7520@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12c75e0 ?Wrap12c75e0@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12c76a0 ?Wrap12c76a0@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12c7760 ?Wrap12c7760@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12c7820 ?Wrap12c7820@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12c78e0 ?Wrap12c78e0@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12c79a0 ?Wrap12c79a0@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12c7b60 ?Wrap12c7b60@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12c7c20 ?Wrap12c7c20@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12c7ce0 ?Wrap12c7ce0@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12d0a80 ?Wrap12d0a80@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12f8210 ?Wrap12f8210@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x12f83d0 ?Wrap12f83d0@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x1302a30 ?Wrap1302a30@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x1309e70 ?Wrap1309e70@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// CI hash: 0x1332b20 ?Wrap1332b20@SboEmptyBinders2@@SA?AUSboEmptyBinders2SboBinding@@PEAXPEAUSboEmptyBinders2EmptyBox@@_K@Z
// 0x12c7120 SboEmptyBinders2::Wrap12c7120
// 0x12c72e0 SboEmptyBinders2::Wrap12c72e0
// 0x12c73a0 SboEmptyBinders2::Wrap12c73a0
// 0x12c7460 SboEmptyBinders2::Wrap12c7460
// 0x12c7520 SboEmptyBinders2::Wrap12c7520
// 0x12c75e0 SboEmptyBinders2::Wrap12c75e0
// 0x12c76a0 SboEmptyBinders2::Wrap12c76a0
// 0x12c7760 SboEmptyBinders2::Wrap12c7760
// 0x12c7820 SboEmptyBinders2::Wrap12c7820
// 0x12c78e0 SboEmptyBinders2::Wrap12c78e0
// 0x12c79a0 SboEmptyBinders2::Wrap12c79a0
// 0x12c7b60 SboEmptyBinders2::Wrap12c7b60
// 0x12c7c20 SboEmptyBinders2::Wrap12c7c20
// 0x12c7ce0 SboEmptyBinders2::Wrap12c7ce0
// 0x12d0a80 SboEmptyBinders2::Wrap12d0a80
// 0x12f8210 SboEmptyBinders2::Wrap12f8210
// 0x12f83d0 SboEmptyBinders2::Wrap12f83d0
// 0x1302a30 SboEmptyBinders2::Wrap1302a30
// 0x1309e70 SboEmptyBinders2::Wrap1309e70
// 0x1332b20 SboEmptyBinders2::Wrap1332b20
#include "SboEmptyBinders2.h"

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12c7120(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae02a0;
        result.instance = buf;
        result.cleanup = Cleanup_12cbae0;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae02a0;
    result.cleanup = Cleanup_12c6d20;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12c72e0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae0430;
        result.instance = buf;
        result.cleanup = Cleanup_12cbb00;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae0430;
    result.cleanup = Cleanup_12c6da0;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12c73a0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae0200;
        result.instance = buf;
        result.cleanup = Cleanup_12cbb10;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae0200;
    result.cleanup = Cleanup_12c6de0;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12c7460(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae02f0;
        result.instance = buf;
        result.cleanup = Cleanup_12cbb20;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae02f0;
    result.cleanup = Cleanup_12c6e20;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12c7520(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae01b0;
        result.instance = buf;
        result.cleanup = Cleanup_12cbb30;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae01b0;
    result.cleanup = Cleanup_12c6e60;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12c75e0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae0390;
        result.instance = buf;
        result.cleanup = Cleanup_12cbb40;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae0390;
    result.cleanup = Cleanup_12c6ea0;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12c76a0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae0480;
        result.instance = buf;
        result.cleanup = Cleanup_12cbb50;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae0480;
    result.cleanup = Cleanup_12c6ee0;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12c7760(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae03e0;
        result.instance = buf;
        result.cleanup = Cleanup_12cbb60;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae03e0;
    result.cleanup = Cleanup_12c6f20;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12c7820(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae0340;
        result.instance = buf;
        result.cleanup = Cleanup_12cbb70;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae0340;
    result.cleanup = Cleanup_12c6f60;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12c78e0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae0110;
        result.instance = buf;
        result.cleanup = Cleanup_12cbb80;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae0110;
    result.cleanup = Cleanup_12c6fa0;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12c79a0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae0160;
        result.instance = buf;
        result.cleanup = Cleanup_12cbb90;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae0160;
    result.cleanup = Cleanup_12c6fe0;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12c7b60(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae00c0;
        result.instance = buf;
        result.cleanup = Cleanup_12cbbb0;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae00c0;
    result.cleanup = Cleanup_12c7060;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12c7c20(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae0250;
        result.instance = buf;
        result.cleanup = Cleanup_12cbbc0;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae0250;
    result.cleanup = Cleanup_12c70a0;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12c7ce0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae0570;
        result.instance = buf;
        result.cleanup = Cleanup_12cbbd0;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae0570;
    result.cleanup = Cleanup_12c70e0;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12d0a80(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae1890;
        result.instance = buf;
        result.cleanup = Cleanup_12d3aa0;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae1890;
    result.cleanup = Cleanup_12d0700;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12f8210(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae6c68;
        result.instance = buf;
        result.cleanup = Cleanup_12fd0a0;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae6c68;
    result.cleanup = Cleanup_12f7d60;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap12f83d0(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae6ca8;
        result.instance = buf;
        result.cleanup = Cleanup_12fd0c0;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae6ca8;
    result.cleanup = Cleanup_12f7de0;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap1302a30(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae7c80;
        result.instance = buf;
        result.cleanup = Cleanup_13062d0;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae7c80;
    result.cleanup = Cleanup_13029f0;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap1309e70(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ae89f0;
        result.instance = buf;
        result.cleanup = Cleanup_130ae60;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ae89f0;
    result.cleanup = Cleanup_1309df0;
    return result;
}

SboEmptyBinders2SboBinding SboEmptyBinders2::Wrap1332b20(void* unused, SboEmptyBinders2EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders2SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1aefce0;
        result.instance = buf;
        result.cleanup = Cleanup_133b7b0;
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
    SboEmptyBinders2EmptyBox* heap = static_cast<SboEmptyBinders2EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1aefce0;
    result.cleanup = Cleanup_1331ff0;
    return result;
}
