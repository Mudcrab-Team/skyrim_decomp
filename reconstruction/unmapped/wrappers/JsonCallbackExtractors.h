// Source exposure: mixed (pinned image and community function boundaries).
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// Code origin: generated structural reconstruction of BNet runtime SBO, allocator, buffer, and guarded-log wrappers.
// JsonCallbackExtractors, helper structs, methods and referenced symbols: GUESS(low) STANDIN; original ownership and layouts unknown.
// Adapted bodies: none
#pragma once

struct JsonCallbackExtractorsJsonErrorState
{
    unsigned long long code;
};

struct JsonCallbackExtractorsJsonReader
{
    const char* name;
    void* doc;
    JsonCallbackExtractorsJsonErrorState* errState;
    void* errBuf;
};

using JsonCallbackExtractorsJsonCallback = void (*)(void* node, void* ctx, JsonCallbackExtractorsJsonErrorState* errState, void* errBuf);

extern "C" unsigned int gLogChannel_20d5040;
extern "C" bool LogFilter_128c360(unsigned int channel, int level);
extern "C" bool LogConsoleEn_128c380();
extern "C" int LogVerbosity_128c340(unsigned int channel);
extern "C" bool LogSinkEn_128c1a0(int level, unsigned int channel);
extern "C" void LogConsole_12d7c70(int level, const char* fmt, ...);
extern "C" void LogSink_12d7cb0(int level, const char* fmt, ...);
extern "C" const char Text_1b01760[];
extern "C" const char Text_1b01780[];
extern "C" int JsonLookup_13e6bd0(void* doc, const char* key, void** outNode);
extern "C" void JsonFormatErr_13a06d0(void* buf, const char* fmt, const char* name, const char* key);

struct JsonCallbackExtractors
{
    static bool Wrap13ec890(JsonCallbackExtractorsJsonReader* reader, const char* key, JsonCallbackExtractorsJsonCallback cb, void* ctx);
    static bool Wrap13ec9a0(JsonCallbackExtractorsJsonReader* reader, const char* key, JsonCallbackExtractorsJsonCallback cb, void* ctx);
    static bool Wrap142c680(JsonCallbackExtractorsJsonReader* reader, const char* key, JsonCallbackExtractorsJsonCallback cb, void* ctx);
    static bool Wrap1438350(JsonCallbackExtractorsJsonReader* reader, const char* key, JsonCallbackExtractorsJsonCallback cb, void* ctx);
    static bool Wrap144e550(JsonCallbackExtractorsJsonReader* reader, const char* key, JsonCallbackExtractorsJsonCallback cb, void* ctx);
};
