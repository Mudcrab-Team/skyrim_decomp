// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// JsonCallbackExtractors, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x13ec890 ?Wrap13ec890@JsonCallbackExtractors@@SA_NPEAUJsonCallbackExtractorsJsonReader@@PEBDP6AXPEAX2PEAUJsonCallbackExtractorsJsonErrorState@@2@Z2@Z
// CI hash: 0x13ec9a0 ?Wrap13ec9a0@JsonCallbackExtractors@@SA_NPEAUJsonCallbackExtractorsJsonReader@@PEBDP6AXPEAX2PEAUJsonCallbackExtractorsJsonErrorState@@2@Z2@Z
// CI hash: 0x142c680 ?Wrap142c680@JsonCallbackExtractors@@SA_NPEAUJsonCallbackExtractorsJsonReader@@PEBDP6AXPEAX2PEAUJsonCallbackExtractorsJsonErrorState@@2@Z2@Z
// CI hash: 0x1438350 ?Wrap1438350@JsonCallbackExtractors@@SA_NPEAUJsonCallbackExtractorsJsonReader@@PEBDP6AXPEAX2PEAUJsonCallbackExtractorsJsonErrorState@@2@Z2@Z
// CI hash: 0x144e550 ?Wrap144e550@JsonCallbackExtractors@@SA_NPEAUJsonCallbackExtractorsJsonReader@@PEBDP6AXPEAX2PEAUJsonCallbackExtractorsJsonErrorState@@2@Z2@Z
// 0x13ec890 JsonCallbackExtractors::Wrap13ec890
// 0x13ec9a0 JsonCallbackExtractors::Wrap13ec9a0
// 0x142c680 JsonCallbackExtractors::Wrap142c680
// 0x1438350 JsonCallbackExtractors::Wrap1438350
// 0x144e550 JsonCallbackExtractors::Wrap144e550
#include "JsonCallbackExtractors.h"

namespace
{
    constexpr unsigned long long kCallbackLookupError = 0x1000000010001ull;
}

bool JsonCallbackExtractors::Wrap13ec890(JsonCallbackExtractorsJsonReader* reader, const char* key, JsonCallbackExtractorsJsonCallback cb, void* ctx)
{
    void* node;
    if (JsonLookup_13e6bd0(reader->doc, key, &node) == 0)
    {
        cb(node, ctx, reader->errState, reader->errBuf);
        return reader->errState->code == 0;
    }
    JsonFormatErr_13a06d0(reader->errBuf, Text_1b01760, reader->name, key);
    reader->errState->code = kCallbackLookupError;
    if (!LogFilter_128c360(gLogChannel_20d5040, 1))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
        {
            LogConsole_12d7c70(1, Text_1b01780, reader->name, key);
        }
        if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
        {
            LogSink_12d7cb0(1, Text_1b01780, reader->name, key);
        }
    }
    return false;
}

bool JsonCallbackExtractors::Wrap13ec9a0(JsonCallbackExtractorsJsonReader* reader, const char* key, JsonCallbackExtractorsJsonCallback cb, void* ctx)
{
    void* node;
    if (JsonLookup_13e6bd0(reader->doc, key, &node) == 0)
    {
        cb(node, ctx, reader->errState, reader->errBuf);
        return reader->errState->code == 0;
    }
    JsonFormatErr_13a06d0(reader->errBuf, Text_1b01760, reader->name, key);
    reader->errState->code = kCallbackLookupError;
    if (!LogFilter_128c360(gLogChannel_20d5040, 1))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
        {
            LogConsole_12d7c70(1, Text_1b01780, reader->name, key);
        }
        if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
        {
            LogSink_12d7cb0(1, Text_1b01780, reader->name, key);
        }
    }
    return false;
}

bool JsonCallbackExtractors::Wrap142c680(JsonCallbackExtractorsJsonReader* reader, const char* key, JsonCallbackExtractorsJsonCallback cb, void* ctx)
{
    void* node;
    if (JsonLookup_13e6bd0(reader->doc, key, &node) == 0)
    {
        cb(node, ctx, reader->errState, reader->errBuf);
        return reader->errState->code == 0;
    }
    JsonFormatErr_13a06d0(reader->errBuf, Text_1b01760, reader->name, key);
    reader->errState->code = kCallbackLookupError;
    if (!LogFilter_128c360(gLogChannel_20d5040, 1))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
        {
            LogConsole_12d7c70(1, Text_1b01780, reader->name, key);
        }
        if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
        {
            LogSink_12d7cb0(1, Text_1b01780, reader->name, key);
        }
    }
    return false;
}

bool JsonCallbackExtractors::Wrap1438350(JsonCallbackExtractorsJsonReader* reader, const char* key, JsonCallbackExtractorsJsonCallback cb, void* ctx)
{
    void* node;
    if (JsonLookup_13e6bd0(reader->doc, key, &node) == 0)
    {
        cb(node, ctx, reader->errState, reader->errBuf);
        return reader->errState->code == 0;
    }
    JsonFormatErr_13a06d0(reader->errBuf, Text_1b01760, reader->name, key);
    reader->errState->code = kCallbackLookupError;
    if (!LogFilter_128c360(gLogChannel_20d5040, 1))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
        {
            LogConsole_12d7c70(1, Text_1b01780, reader->name, key);
        }
        if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
        {
            LogSink_12d7cb0(1, Text_1b01780, reader->name, key);
        }
    }
    return false;
}

bool JsonCallbackExtractors::Wrap144e550(JsonCallbackExtractorsJsonReader* reader, const char* key, JsonCallbackExtractorsJsonCallback cb, void* ctx)
{
    void* node;
    if (JsonLookup_13e6bd0(reader->doc, key, &node) == 0)
    {
        cb(node, ctx, reader->errState, reader->errBuf);
        return reader->errState->code == 0;
    }
    JsonFormatErr_13a06d0(reader->errBuf, Text_1b01760, reader->name, key);
    reader->errState->code = kCallbackLookupError;
    if (!LogFilter_128c360(gLogChannel_20d5040, 1))
    {
        if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
        {
            LogConsole_12d7c70(1, Text_1b01780, reader->name, key);
        }
        if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
        {
            LogSink_12d7cb0(1, Text_1b01780, reader->name, key);
        }
    }
    return false;
}
