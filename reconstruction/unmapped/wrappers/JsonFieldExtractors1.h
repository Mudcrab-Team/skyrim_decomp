// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// JsonFieldExtractors1, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct JsonFieldExtractors1JsonErrorState
{
    unsigned long long code;
};

struct JsonFieldExtractors1JsonErrorBuf
{
    unsigned char unk00[0x10];
    char text[1];
};

struct JsonFieldExtractors1JsonReader
{
    const char* name;
    void* doc;
    JsonFieldExtractors1JsonErrorState* errState;
    JsonFieldExtractors1JsonErrorBuf* errBuf;
};

struct JsonFieldExtractors1JsonNode
{
    unsigned long long low;
    unsigned long long high;
};

extern "C" unsigned int gLogChannel_20d5040;
extern "C" bool LogFilter_128c360(unsigned int channel, int level);
extern "C" bool LogConsoleEn_128c380();
extern "C" int LogVerbosity_128c340(unsigned int channel);
extern "C" bool LogSinkEn_128c1a0(int level, unsigned int channel);
extern "C" void LogConsole_12d7c70(int level, const char* fmt, ...);
extern "C" void LogSink_12d7cb0(int level, const char* fmt, ...);
extern "C" const char Text_1b01720[];
extern "C" const char Text_1b01760[];
extern "C" const char Text_1b01780[];
extern "C" const char Text_1b0fdc8[];
extern "C" const char Text_1b01740[];
extern "C" int JsonLookup_13e71d0(void* doc, const char* key, JsonFieldExtractors1JsonNode* out);
extern "C" void JsonDecode_13ef780(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonFormatErr_13a06d0(JsonFieldExtractors1JsonErrorBuf* buf, const char* fmt, const char* name, const char* key);
extern "C" void JsonDecode_13efa30(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_13efce0(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_13eff90(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_13f0240(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_13bf730(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_13f04f0(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_13f07a0(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_13bf9e0(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_13f0a50(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_13f0d00(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_13f0fb0(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_137f030(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_14068d0(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_1406b80(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_140de80(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_140e3e0(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_140e690(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_1370d90(JsonFieldExtractors1JsonNode* node, void* out);
extern "C" void JsonDecode_142d110(JsonFieldExtractors1JsonNode* node, void* out);

struct JsonFieldExtractors1
{
    static bool Wrap13ed8a0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap13eda80(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap13edc60(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap13ee180(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap13ee360(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap13ee540(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap13ee720(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap13ee900(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap13eeae0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap13eecc0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap13ef1e0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap13ef3c0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap13ef5a0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap1406510(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap14066f0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap140d700(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap140d8e0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap140dac0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap140dca0(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap142cb70(JsonFieldExtractors1JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
};
