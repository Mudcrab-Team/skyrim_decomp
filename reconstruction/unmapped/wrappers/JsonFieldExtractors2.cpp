// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// JsonFieldExtractors2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x142cd50 ?Wrap142cd50@JsonFieldExtractors2@@SA_NPEAUJsonFieldExtractors2JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x142cf30 ?Wrap142cf30@JsonFieldExtractors2@@SA_NPEAUJsonFieldExtractors2JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x14389a0 ?Wrap14389a0@JsonFieldExtractors2@@SA_NPEAUJsonFieldExtractors2JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x1438b80 ?Wrap1438b80@JsonFieldExtractors2@@SA_NPEAUJsonFieldExtractors2JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x1438d60 ?Wrap1438d60@JsonFieldExtractors2@@SA_NPEAUJsonFieldExtractors2JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x144ea40 ?Wrap144ea40@JsonFieldExtractors2@@SA_NPEAUJsonFieldExtractors2JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x144ec20 ?Wrap144ec20@JsonFieldExtractors2@@SA_NPEAUJsonFieldExtractors2JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x144ee00 ?Wrap144ee00@JsonFieldExtractors2@@SA_NPEAUJsonFieldExtractors2JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x144efe0 ?Wrap144efe0@JsonFieldExtractors2@@SA_NPEAUJsonFieldExtractors2JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x1477a50 ?Wrap1477a50@JsonFieldExtractors2@@SA_NPEAUJsonFieldExtractors2JsonReader@@PEBDPEAX_N3@Z
// 0x142cd50 JsonFieldExtractors2::Wrap142cd50
// 0x142cf30 JsonFieldExtractors2::Wrap142cf30
// 0x14389a0 JsonFieldExtractors2::Wrap14389a0
// 0x1438b80 JsonFieldExtractors2::Wrap1438b80
// 0x1438d60 JsonFieldExtractors2::Wrap1438d60
// 0x144ea40 JsonFieldExtractors2::Wrap144ea40
// 0x144ec20 JsonFieldExtractors2::Wrap144ec20
// 0x144ee00 JsonFieldExtractors2::Wrap144ee00
// 0x144efe0 JsonFieldExtractors2::Wrap144efe0
// 0x1477a50 JsonFieldExtractors2::Wrap1477a50
#include "JsonFieldExtractors2.h"

namespace
{
    constexpr int kLookupMissingField = 34;
    constexpr int kLookupTypeMismatch = 33;
    constexpr unsigned long long kFieldTypeError = 0x1000000010001ull;
    constexpr unsigned long long kFieldLookupError = 0x1000000010002ull;
}

bool JsonFieldExtractors2::Wrap142cd50(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors2JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_13c3890(&node, out);
        return true;
    }
    if (rc == kLookupMissingField)
    {
        if (!quietMissing)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01720, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
        return false;
    }
    if (!quietErr)
    {
        if (rc == kLookupTypeMismatch)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01760, reader->name, key);
            reader->errState->code = kFieldTypeError;
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
        }
        else
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b0fdc8, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
    }
    return false;
}

bool JsonFieldExtractors2::Wrap142cf30(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors2JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_142d920(&node, out);
        return true;
    }
    if (rc == kLookupMissingField)
    {
        if (!quietMissing)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01720, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
        return false;
    }
    if (!quietErr)
    {
        if (rc == kLookupTypeMismatch)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01760, reader->name, key);
            reader->errState->code = kFieldTypeError;
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
        }
        else
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b0fdc8, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
    }
    return false;
}

bool JsonFieldExtractors2::Wrap14389a0(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors2JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_142d3c0(&node, out);
        return true;
    }
    if (rc == kLookupMissingField)
    {
        if (!quietMissing)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01720, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
        return false;
    }
    if (!quietErr)
    {
        if (rc == kLookupTypeMismatch)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01760, reader->name, key);
            reader->errState->code = kFieldTypeError;
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
        }
        else
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b0fdc8, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
    }
    return false;
}

bool JsonFieldExtractors2::Wrap1438b80(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors2JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_1438f40(&node, out);
        return true;
    }
    if (rc == kLookupMissingField)
    {
        if (!quietMissing)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01720, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
        return false;
    }
    if (!quietErr)
    {
        if (rc == kLookupTypeMismatch)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01760, reader->name, key);
            reader->errState->code = kFieldTypeError;
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
        }
        else
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b0fdc8, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
    }
    return false;
}

bool JsonFieldExtractors2::Wrap1438d60(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors2JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_1439170(&node, out);
        return true;
    }
    if (rc == kLookupMissingField)
    {
        if (!quietMissing)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01720, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
        return false;
    }
    if (!quietErr)
    {
        if (rc == kLookupTypeMismatch)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01760, reader->name, key);
            reader->errState->code = kFieldTypeError;
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
        }
        else
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b0fdc8, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
    }
    return false;
}

bool JsonFieldExtractors2::Wrap144ea40(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors2JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_14497c0(&node, out);
        return true;
    }
    if (rc == kLookupMissingField)
    {
        if (!quietMissing)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01720, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
        return false;
    }
    if (!quietErr)
    {
        if (rc == kLookupTypeMismatch)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01760, reader->name, key);
            reader->errState->code = kFieldTypeError;
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
        }
        else
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b0fdc8, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
    }
    return false;
}

bool JsonFieldExtractors2::Wrap144ec20(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors2JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_144f1c0(&node, out);
        return true;
    }
    if (rc == kLookupMissingField)
    {
        if (!quietMissing)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01720, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
        return false;
    }
    if (!quietErr)
    {
        if (rc == kLookupTypeMismatch)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01760, reader->name, key);
            reader->errState->code = kFieldTypeError;
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
        }
        else
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b0fdc8, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
    }
    return false;
}

bool JsonFieldExtractors2::Wrap144ee00(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors2JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_144f470(&node, out);
        return true;
    }
    if (rc == kLookupMissingField)
    {
        if (!quietMissing)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01720, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
        return false;
    }
    if (!quietErr)
    {
        if (rc == kLookupTypeMismatch)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01760, reader->name, key);
            reader->errState->code = kFieldTypeError;
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
        }
        else
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b0fdc8, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
    }
    return false;
}

bool JsonFieldExtractors2::Wrap144efe0(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors2JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_144f720(&node, out);
        return true;
    }
    if (rc == kLookupMissingField)
    {
        if (!quietMissing)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01720, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
        return false;
    }
    if (!quietErr)
    {
        if (rc == kLookupTypeMismatch)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01760, reader->name, key);
            reader->errState->code = kFieldTypeError;
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
        }
        else
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b0fdc8, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
    }
    return false;
}

bool JsonFieldExtractors2::Wrap1477a50(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors2JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_1477c30(&node, out);
        return true;
    }
    if (rc == kLookupMissingField)
    {
        if (!quietMissing)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01720, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
        return false;
    }
    if (!quietErr)
    {
        if (rc == kLookupTypeMismatch)
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b01760, reader->name, key);
            reader->errState->code = kFieldTypeError;
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
        }
        else
        {
            JsonFormatErr_13a06d0(reader->errBuf, Text_1b0fdc8, reader->name, key);
            reader->errState->code = kFieldLookupError;
            if (!LogFilter_128c360(gLogChannel_20d5040, 1))
            {
                if (LogConsoleEn_128c380() && LogVerbosity_128c340(gLogChannel_20d5040) <= 1)
                {
                    LogConsole_12d7c70(1, Text_1b01740, reader->errBuf->text);
                }
                if (LogSinkEn_128c1a0(1, gLogChannel_20d5040))
                {
                    LogSink_12d7cb0(1, Text_1b01740, reader->errBuf->text);
                }
            }
        }
    }
    return false;
}
