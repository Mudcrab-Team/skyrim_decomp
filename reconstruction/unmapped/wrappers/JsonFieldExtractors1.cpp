// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// JsonFieldExtractors1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
// CI hash: 0x13ed8a0 ?Wrap13ed8a0@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x13eda80 ?Wrap13eda80@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x13edc60 ?Wrap13edc60@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x13ee180 ?Wrap13ee180@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x13ee360 ?Wrap13ee360@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x13ee540 ?Wrap13ee540@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x13ee720 ?Wrap13ee720@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x13ee900 ?Wrap13ee900@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x13eeae0 ?Wrap13eeae0@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x13eecc0 ?Wrap13eecc0@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x13ef1e0 ?Wrap13ef1e0@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x13ef3c0 ?Wrap13ef3c0@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x13ef5a0 ?Wrap13ef5a0@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x1406510 ?Wrap1406510@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x14066f0 ?Wrap14066f0@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x140d700 ?Wrap140d700@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x140d8e0 ?Wrap140d8e0@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x140dac0 ?Wrap140dac0@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x140dca0 ?Wrap140dca0@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// CI hash: 0x142cb70 ?Wrap142cb70@JsonFieldExtractors1@@SA_NPEAUJsonFieldExtractors1JsonReader@@PEBDPEAX_N3@Z
// 0x13ed8a0 JsonFieldExtractors1::Wrap13ed8a0
// 0x13eda80 JsonFieldExtractors1::Wrap13eda80
// 0x13edc60 JsonFieldExtractors1::Wrap13edc60
// 0x13ee180 JsonFieldExtractors1::Wrap13ee180
// 0x13ee360 JsonFieldExtractors1::Wrap13ee360
// 0x13ee540 JsonFieldExtractors1::Wrap13ee540
// 0x13ee720 JsonFieldExtractors1::Wrap13ee720
// 0x13ee900 JsonFieldExtractors1::Wrap13ee900
// 0x13eeae0 JsonFieldExtractors1::Wrap13eeae0
// 0x13eecc0 JsonFieldExtractors1::Wrap13eecc0
// 0x13ef1e0 JsonFieldExtractors1::Wrap13ef1e0
// 0x13ef3c0 JsonFieldExtractors1::Wrap13ef3c0
// 0x13ef5a0 JsonFieldExtractors1::Wrap13ef5a0
// 0x1406510 JsonFieldExtractors1::Wrap1406510
// 0x14066f0 JsonFieldExtractors1::Wrap14066f0
// 0x140d700 JsonFieldExtractors1::Wrap140d700
// 0x140d8e0 JsonFieldExtractors1::Wrap140d8e0
// 0x140dac0 JsonFieldExtractors1::Wrap140dac0
// 0x140dca0 JsonFieldExtractors1::Wrap140dca0
// 0x142cb70 JsonFieldExtractors1::Wrap142cb70
#include "JsonFieldExtractors1.h"

namespace
{
    constexpr int kLookupMissingField = 34;
    constexpr int kLookupTypeMismatch = 33;
    constexpr unsigned long long kFieldTypeError = 0x1000000010001ull;
    constexpr unsigned long long kFieldLookupError = 0x1000000010002ull;
}

bool JsonFieldExtractors1::Wrap13ed8a0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_13ef780(&node, out);
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

bool JsonFieldExtractors1::Wrap13eda80(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_13efa30(&node, out);
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

bool JsonFieldExtractors1::Wrap13edc60(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_13efce0(&node, out);
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

bool JsonFieldExtractors1::Wrap13ee180(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_13eff90(&node, out);
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

bool JsonFieldExtractors1::Wrap13ee360(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_13f0240(&node, out);
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

bool JsonFieldExtractors1::Wrap13ee540(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_13bf730(&node, out);
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

bool JsonFieldExtractors1::Wrap13ee720(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_13f04f0(&node, out);
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

bool JsonFieldExtractors1::Wrap13ee900(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_13f07a0(&node, out);
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

bool JsonFieldExtractors1::Wrap13eeae0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_13bf9e0(&node, out);
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

bool JsonFieldExtractors1::Wrap13eecc0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_13f0a50(&node, out);
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

bool JsonFieldExtractors1::Wrap13ef1e0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_13f0d00(&node, out);
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

bool JsonFieldExtractors1::Wrap13ef3c0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_13f0fb0(&node, out);
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

bool JsonFieldExtractors1::Wrap13ef5a0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_137f030(&node, out);
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

bool JsonFieldExtractors1::Wrap1406510(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_14068d0(&node, out);
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

bool JsonFieldExtractors1::Wrap14066f0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_1406b80(&node, out);
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

bool JsonFieldExtractors1::Wrap140d700(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_140de80(&node, out);
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

bool JsonFieldExtractors1::Wrap140d8e0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_140e3e0(&node, out);
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

bool JsonFieldExtractors1::Wrap140dac0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_140e690(&node, out);
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

bool JsonFieldExtractors1::Wrap140dca0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_1370d90(&node, out);
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

bool JsonFieldExtractors1::Wrap142cb70(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing)
{
    JsonFieldExtractors1JsonNode node = { 0, 0 };
    int rc = JsonLookup_13e71d0(reader->doc, key, &node);
    if (rc == 0)
    {
        JsonDecode_142d110(&node, out);
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
