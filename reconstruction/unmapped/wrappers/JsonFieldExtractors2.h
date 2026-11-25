// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// JsonFieldExtractors2, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct JsonFieldExtractors2JsonErrorState
{
    unsigned long long code;
};

struct JsonFieldExtractors2JsonErrorBuf
{
    unsigned char unk00[0x10];
    char text[1];
};

struct JsonFieldExtractors2JsonReader
{
    const char* name;
    void* doc;
    JsonFieldExtractors2JsonErrorState* errState;
    JsonFieldExtractors2JsonErrorBuf* errBuf;
};

struct JsonFieldExtractors2JsonNode
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
extern "C" int JsonLookup_13e71d0(void* doc, const char* key, JsonFieldExtractors2JsonNode* out);
extern "C" void JsonDecode_13c3890(JsonFieldExtractors2JsonNode* node, void* out);
extern "C" void JsonFormatErr_13a06d0(JsonFieldExtractors2JsonErrorBuf* buf, const char* fmt, const char* name, const char* key);
extern "C" void JsonDecode_142d920(JsonFieldExtractors2JsonNode* node, void* out);
extern "C" void JsonDecode_142d3c0(JsonFieldExtractors2JsonNode* node, void* out);
extern "C" void JsonDecode_1438f40(JsonFieldExtractors2JsonNode* node, void* out);
extern "C" void JsonDecode_1439170(JsonFieldExtractors2JsonNode* node, void* out);
extern "C" void JsonDecode_14497c0(JsonFieldExtractors2JsonNode* node, void* out);
extern "C" void JsonDecode_144f1c0(JsonFieldExtractors2JsonNode* node, void* out);
extern "C" void JsonDecode_144f470(JsonFieldExtractors2JsonNode* node, void* out);
extern "C" void JsonDecode_144f720(JsonFieldExtractors2JsonNode* node, void* out);
extern "C" void JsonDecode_1477c30(JsonFieldExtractors2JsonNode* node, void* out);

struct JsonFieldExtractors2
{
    static bool Wrap142cd50(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap142cf30(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap14389a0(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap1438b80(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap1438d60(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap144ea40(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap144ec20(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap144ee00(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap144efe0(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
    static bool Wrap1477a50(JsonFieldExtractors2JsonReader* reader, const char* key, void* out, bool quietErr, bool quietMissing);
};
