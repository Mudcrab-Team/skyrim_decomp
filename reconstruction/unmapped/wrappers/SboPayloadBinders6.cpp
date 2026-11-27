// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// SboPayloadBinders6, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x147ec20 ?Wrap147ec20@SboPayloadBinders6@@SA?AUSboPayloadBinders6SboBinding@@PEAPEAXPEAUSboPayloadBinders6PayloadBox@@_K@Z
// CI hash: 0x147ed20 ?Wrap147ed20@SboPayloadBinders6@@SA?AUSboPayloadBinders6SboBinding@@PEAPEAXPEAUSboPayloadBinders6PayloadBox@@_K@Z
// CI hash: 0x147ee20 ?Wrap147ee20@SboPayloadBinders6@@SA?AUSboPayloadBinders6SboBinding@@PEAPEAXPEAUSboPayloadBinders6PayloadBox@@_K@Z
// CI hash: 0x147ef20 ?Wrap147ef20@SboPayloadBinders6@@SA?AUSboPayloadBinders6SboBinding@@PEAPEAXPEAUSboPayloadBinders6PayloadBox@@_K@Z
// 0x147ec20 SboPayloadBinders6::Wrap147ec20
// 0x147ed20 SboPayloadBinders6::Wrap147ed20
// 0x147ee20 SboPayloadBinders6::Wrap147ee20
// 0x147ef20 SboPayloadBinders6::Wrap147ef20
#include "SboPayloadBinders6.h"

SboPayloadBinders6SboBinding SboPayloadBinders6::Wrap147ec20(void** src, SboPayloadBinders6PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders6SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b210c0;
        buf->payload = *src;
        buf->table = Table_1b210e0;
        result.instance = buf;
        result.cleanup = Cleanup_1486c30;
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
    SboPayloadBinders6PayloadBox* heap = static_cast<SboPayloadBinders6PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b210c0;
    heap->payload = *src;
    heap->table = Table_1b210e0;
    result.cleanup = Cleanup_147e020;
    return result;
}

SboPayloadBinders6SboBinding SboPayloadBinders6::Wrap147ed20(void** src, SboPayloadBinders6PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders6SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b21180;
        buf->payload = *src;
        buf->table = Table_1b211a0;
        result.instance = buf;
        result.cleanup = Cleanup_1486c40;
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
    SboPayloadBinders6PayloadBox* heap = static_cast<SboPayloadBinders6PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b21180;
    heap->payload = *src;
    heap->table = Table_1b211a0;
    result.cleanup = Cleanup_147e060;
    return result;
}

SboPayloadBinders6SboBinding SboPayloadBinders6::Wrap147ee20(void** src, SboPayloadBinders6PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders6SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b21340;
        buf->payload = *src;
        buf->table = Table_1b21360;
        result.instance = buf;
        result.cleanup = Cleanup_1486c50;
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
    SboPayloadBinders6PayloadBox* heap = static_cast<SboPayloadBinders6PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b21340;
    heap->payload = *src;
    heap->table = Table_1b21360;
    result.cleanup = Cleanup_147e0a0;
    return result;
}

SboPayloadBinders6SboBinding SboPayloadBinders6::Wrap147ef20(void** src, SboPayloadBinders6PayloadBox* buf, unsigned long long cap)
{
    SboPayloadBinders6SboBinding result;
    if (cap >= 16ull)
    {
        buf->table = Table_1b21300;
        buf->payload = *src;
        buf->table = Table_1b21320;
        result.instance = buf;
        result.cleanup = Cleanup_1486c60;
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
    SboPayloadBinders6PayloadBox* heap = static_cast<SboPayloadBinders6PayloadBox*>(gAllocFn_3356368(16ull));
    result.instance = heap;
    heap->table = Table_1b21300;
    heap->payload = *src;
    heap->table = Table_1b21320;
    result.cleanup = Cleanup_147e0e0;
    return result;
}
