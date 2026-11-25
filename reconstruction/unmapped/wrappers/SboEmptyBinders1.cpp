// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboEmptyBinders1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x1258810 ?Wrap1258810@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x12588d0 ?Wrap12588d0@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x127f3c0 ?Wrap127f3c0@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x127f800 ?Wrap127f800@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x127f8c0 ?Wrap127f8c0@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x12991d0 ?Wrap12991d0@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x1299390 ?Wrap1299390@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x129d7d0 ?Wrap129d7d0@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x12a9520 ?Wrap12a9520@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x12a95e0 ?Wrap12a95e0@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x12a98a0 ?Wrap12a98a0@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x12a9b60 ?Wrap12a9b60@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x12baf20 ?Wrap12baf20@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x12bafe0 ?Wrap12bafe0@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x12bb0a0 ?Wrap12bb0a0@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x12bb160 ?Wrap12bb160@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x12bb220 ?Wrap12bb220@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x12bb2e0 ?Wrap12bb2e0@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x12bb4b0 ?Wrap12bb4b0@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// CI hash: 0x12bb570 ?Wrap12bb570@SboEmptyBinders1@@SA?AUSboEmptyBinders1SboBinding@@PEAXPEAUSboEmptyBinders1EmptyBox@@_K@Z
// 0x1258810 SboEmptyBinders1::Wrap1258810
// 0x12588d0 SboEmptyBinders1::Wrap12588d0
// 0x127f3c0 SboEmptyBinders1::Wrap127f3c0
// 0x127f800 SboEmptyBinders1::Wrap127f800
// 0x127f8c0 SboEmptyBinders1::Wrap127f8c0
// 0x12991d0 SboEmptyBinders1::Wrap12991d0
// 0x1299390 SboEmptyBinders1::Wrap1299390
// 0x129d7d0 SboEmptyBinders1::Wrap129d7d0
// 0x12a9520 SboEmptyBinders1::Wrap12a9520
// 0x12a95e0 SboEmptyBinders1::Wrap12a95e0
// 0x12a98a0 SboEmptyBinders1::Wrap12a98a0
// 0x12a9b60 SboEmptyBinders1::Wrap12a9b60
// 0x12baf20 SboEmptyBinders1::Wrap12baf20
// 0x12bafe0 SboEmptyBinders1::Wrap12bafe0
// 0x12bb0a0 SboEmptyBinders1::Wrap12bb0a0
// 0x12bb160 SboEmptyBinders1::Wrap12bb160
// 0x12bb220 SboEmptyBinders1::Wrap12bb220
// 0x12bb2e0 SboEmptyBinders1::Wrap12bb2e0
// 0x12bb4b0 SboEmptyBinders1::Wrap12bb4b0
// 0x12bb570 SboEmptyBinders1::Wrap12bb570
#include "SboEmptyBinders1.h"

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap1258810(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1acd6d8;
        result.instance = buf;
        result.cleanup = Cleanup_125a830;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1acd6d8;
    result.cleanup = Cleanup_12585f0;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap12588d0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1acd728;
        result.instance = buf;
        result.cleanup = Cleanup_125a840;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1acd728;
    result.cleanup = Cleanup_1258630;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap127f3c0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad1c38;
        result.instance = buf;
        result.cleanup = Cleanup_1284e20;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad1c38;
    result.cleanup = Cleanup_127f240;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap127f800(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad1cd8;
        result.instance = buf;
        result.cleanup = Cleanup_1284e60;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad1cd8;
    result.cleanup = Cleanup_127f340;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap127f8c0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad1c88;
        result.instance = buf;
        result.cleanup = Cleanup_1284e70;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad1c88;
    result.cleanup = Cleanup_127f380;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap12991d0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad4a88;
        result.instance = buf;
        result.cleanup = Cleanup_129b2f0;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad4a88;
    result.cleanup = Cleanup_1299110;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap1299390(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad4ad8;
        result.instance = buf;
        result.cleanup = Cleanup_129b310;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad4ad8;
    result.cleanup = Cleanup_1299190;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap129d7d0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad5888;
        result.instance = buf;
        result.cleanup = Cleanup_129f260;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad5888;
    result.cleanup = Cleanup_129d650;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap12a9520(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad8b80;
        result.instance = buf;
        result.cleanup = Cleanup_12b1120;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad8b80;
    result.cleanup = Cleanup_12a90e0;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap12a95e0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad89a0;
        result.instance = buf;
        result.cleanup = Cleanup_12b1130;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad89a0;
    result.cleanup = Cleanup_12a9120;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap12a98a0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad8a40;
        result.instance = buf;
        result.cleanup = Cleanup_12b1160;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad8a40;
    result.cleanup = Cleanup_12a91e0;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap12a9b60(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1ad8c20;
        result.instance = buf;
        result.cleanup = Cleanup_12b1190;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1ad8c20;
    result.cleanup = Cleanup_12a92a0;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap12baf20(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1addcc8;
        result.instance = buf;
        result.cleanup = Cleanup_12bd540;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1addcc8;
    result.cleanup = Cleanup_12bace0;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap12bafe0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1adde58;
        result.instance = buf;
        result.cleanup = Cleanup_12bd550;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1adde58;
    result.cleanup = Cleanup_12bad20;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap12bb0a0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1addd18;
        result.instance = buf;
        result.cleanup = Cleanup_12bd560;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1addd18;
    result.cleanup = Cleanup_12bad60;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap12bb160(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1adddb8;
        result.instance = buf;
        result.cleanup = Cleanup_12bd570;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1adddb8;
    result.cleanup = Cleanup_12bada0;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap12bb220(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1addd68;
        result.instance = buf;
        result.cleanup = Cleanup_12bd580;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1addd68;
    result.cleanup = Cleanup_12bade0;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap12bb2e0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1adde08;
        result.instance = buf;
        result.cleanup = Cleanup_12bd590;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1adde08;
    result.cleanup = Cleanup_12bae20;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap12bb4b0(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1addea8;
        result.instance = buf;
        result.cleanup = Cleanup_12bd5b0;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1addea8;
    result.cleanup = Cleanup_12baea0;
    return result;
}

SboEmptyBinders1SboBinding SboEmptyBinders1::Wrap12bb570(void* unused, SboEmptyBinders1EmptyBox* buf, unsigned long long cap)
{
    (void)unused;
    SboEmptyBinders1SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1addef8;
        result.instance = buf;
        result.cleanup = Cleanup_12bd5c0;
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
    SboEmptyBinders1EmptyBox* heap = static_cast<SboEmptyBinders1EmptyBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1addef8;
    result.cleanup = Cleanup_12baee0;
    return result;
}
