// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboPayloadBinders5, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x145d500 ?Wrap145d500@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x145d600 ?Wrap145d600@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x145d700 ?Wrap145d700@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x145d800 ?Wrap145d800@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x145d900 ?Wrap145d900@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x145da00 ?Wrap145da00@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x145db00 ?Wrap145db00@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x145dc00 ?Wrap145dc00@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x145dd00 ?Wrap145dd00@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x145de00 ?Wrap145de00@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x146ee90 ?Wrap146ee90@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x146ff20 ?Wrap146ff20@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x1470020 ?Wrap1470020@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x147e420 ?Wrap147e420@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x147e620 ?Wrap147e620@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x147e720 ?Wrap147e720@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x147e820 ?Wrap147e820@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x147e920 ?Wrap147e920@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x147ea20 ?Wrap147ea20@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// CI hash: 0x147eb20 ?Wrap147eb20@SboPayloadBinders5@@SA?AUSboPayloadBinders5SboBinding@@PEAPEAXPEAUSboPayloadBinders5PayloadBox@@_K@Z
// 0x145d500 SboPayloadBinders5::Wrap145d500
// 0x145d600 SboPayloadBinders5::Wrap145d600
// 0x145d700 SboPayloadBinders5::Wrap145d700
// 0x145d800 SboPayloadBinders5::Wrap145d800
// 0x145d900 SboPayloadBinders5::Wrap145d900
// 0x145da00 SboPayloadBinders5::Wrap145da00
// 0x145db00 SboPayloadBinders5::Wrap145db00
// 0x145dc00 SboPayloadBinders5::Wrap145dc00
// 0x145dd00 SboPayloadBinders5::Wrap145dd00
// 0x145de00 SboPayloadBinders5::Wrap145de00
// 0x146ee90 SboPayloadBinders5::Wrap146ee90
// 0x146ff20 SboPayloadBinders5::Wrap146ff20
// 0x1470020 SboPayloadBinders5::Wrap1470020
// 0x147e420 SboPayloadBinders5::Wrap147e420
// 0x147e620 SboPayloadBinders5::Wrap147e620
// 0x147e720 SboPayloadBinders5::Wrap147e720
// 0x147e820 SboPayloadBinders5::Wrap147e820
// 0x147e920 SboPayloadBinders5::Wrap147e920
// 0x147ea20 SboPayloadBinders5::Wrap147ea20
// 0x147eb20 SboPayloadBinders5::Wrap147eb20
#include "SboPayloadBinders5.h"

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap145d500(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1db08;
        buf->payload = *src;
        buf->table = Table_1b1db28;
        result.instance = buf;
        result.cleanup = Cleanup_146b6e0;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1db08;
    heap->payload = *src;
    heap->table = Table_1b1db28;
    result.cleanup = Cleanup_145ccf0;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap145d600(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1dc48;
        buf->payload = *src;
        buf->table = Table_1b1dc68;
        result.instance = buf;
        result.cleanup = Cleanup_146b6f0;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1dc48;
    heap->payload = *src;
    heap->table = Table_1b1dc68;
    result.cleanup = Cleanup_145cd30;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap145d700(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1d8c0;
        buf->payload = *src;
        buf->table = Table_1b1d8e0;
        result.instance = buf;
        result.cleanup = Cleanup_146b700;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1d8c0;
    heap->payload = *src;
    heap->table = Table_1b1d8e0;
    result.cleanup = Cleanup_145cd70;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap145d800(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1d900;
        buf->payload = *src;
        buf->table = Table_1b1d920;
        result.instance = buf;
        result.cleanup = Cleanup_146b710;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1d900;
    heap->payload = *src;
    heap->table = Table_1b1d920;
    result.cleanup = Cleanup_145cdb0;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap145d900(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1da88;
        buf->payload = *src;
        buf->table = Table_1b1daa8;
        result.instance = buf;
        result.cleanup = Cleanup_146b720;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1da88;
    heap->payload = *src;
    heap->table = Table_1b1daa8;
    result.cleanup = Cleanup_145cdf0;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap145da00(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1d980;
        buf->payload = *src;
        buf->table = Table_1b1d9a0;
        result.instance = buf;
        result.cleanup = Cleanup_146b730;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1d980;
    heap->payload = *src;
    heap->table = Table_1b1d9a0;
    result.cleanup = Cleanup_145ce30;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap145db00(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1db48;
        buf->payload = *src;
        buf->table = Table_1b1db68;
        result.instance = buf;
        result.cleanup = Cleanup_146b740;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1db48;
    heap->payload = *src;
    heap->table = Table_1b1db68;
    result.cleanup = Cleanup_145ce70;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap145dc00(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1dc08;
        buf->payload = *src;
        buf->table = Table_1b1dc28;
        result.instance = buf;
        result.cleanup = Cleanup_146b750;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1dc08;
    heap->payload = *src;
    heap->table = Table_1b1dc28;
    result.cleanup = Cleanup_145ceb0;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap145dd00(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1db88;
        buf->payload = *src;
        buf->table = Table_1b1dba8;
        result.instance = buf;
        result.cleanup = Cleanup_146b760;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1db88;
    heap->payload = *src;
    heap->table = Table_1b1dba8;
    result.cleanup = Cleanup_145cef0;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap145de00(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1dbc8;
        buf->payload = *src;
        buf->table = Table_1b1dbe8;
        result.instance = buf;
        result.cleanup = Cleanup_146b770;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1dbc8;
    heap->payload = *src;
    heap->table = Table_1b1dbe8;
    result.cleanup = Cleanup_145cf30;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap146ee90(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1def8;
        buf->payload = *src;
        buf->table = Table_1b1df18;
        result.instance = buf;
        result.cleanup = Cleanup_146fd10;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1def8;
    heap->payload = *src;
    heap->table = Table_1b1df18;
    result.cleanup = Cleanup_146ee50;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap146ff20(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1e1b8;
        buf->payload = *src;
        buf->table = Table_1b1e1d8;
        result.instance = buf;
        result.cleanup = Cleanup_1471040;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1e1b8;
    heap->payload = *src;
    heap->table = Table_1b1e1d8;
    result.cleanup = Cleanup_146fea0;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap1470020(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b1e178;
        buf->payload = *src;
        buf->table = Table_1b1e198;
        result.instance = buf;
        result.cleanup = Cleanup_1471050;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b1e178;
    heap->payload = *src;
    heap->table = Table_1b1e198;
    result.cleanup = Cleanup_146fee0;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap147e420(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b21200;
        buf->payload = *src;
        buf->table = Table_1b21220;
        result.instance = buf;
        result.cleanup = Cleanup_1486bb0;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b21200;
    heap->payload = *src;
    heap->table = Table_1b21220;
    result.cleanup = Cleanup_147de20;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap147e620(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b21380;
        buf->payload = *src;
        buf->table = Table_1b213a0;
        result.instance = buf;
        result.cleanup = Cleanup_1486bd0;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b21380;
    heap->payload = *src;
    heap->table = Table_1b213a0;
    result.cleanup = Cleanup_147dea0;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap147e720(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b21240;
        buf->payload = *src;
        buf->table = Table_1b21260;
        result.instance = buf;
        result.cleanup = Cleanup_1486be0;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b21240;
    heap->payload = *src;
    heap->table = Table_1b21260;
    result.cleanup = Cleanup_147dee0;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap147e820(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b21100;
        buf->payload = *src;
        buf->table = Table_1b21120;
        result.instance = buf;
        result.cleanup = Cleanup_1486bf0;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b21100;
    heap->payload = *src;
    heap->table = Table_1b21120;
    result.cleanup = Cleanup_147df20;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap147e920(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b211c0;
        buf->payload = *src;
        buf->table = Table_1b211e0;
        result.instance = buf;
        result.cleanup = Cleanup_1486c00;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b211c0;
    heap->payload = *src;
    heap->table = Table_1b211e0;
    result.cleanup = Cleanup_147df60;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap147ea20(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b212c0;
        buf->payload = *src;
        buf->table = Table_1b212e0;
        result.instance = buf;
        result.cleanup = Cleanup_1486c10;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b212c0;
    heap->payload = *src;
    heap->table = Table_1b212e0;
    result.cleanup = Cleanup_147dfa0;
    return result;
}

SboPayloadBinders5SboBinding SboPayloadBinders5::Wrap147eb20(void** src, SboPayloadBinders5PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders5SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b21140;
        buf->payload = *src;
        buf->table = Table_1b21160;
        result.instance = buf;
        result.cleanup = Cleanup_1486c20;
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
    SboPayloadBinders5PayloadBox* heap = static_cast<SboPayloadBinders5PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b21140;
    heap->payload = *src;
    heap->table = Table_1b21160;
    result.cleanup = Cleanup_147dfe0;
    return result;
}
