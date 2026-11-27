// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// TESFile, TESFile::IsHigherVersionThanSupported, TESFile::fileName, TESFile::version: CRASHLOGGER_PDB(59818@2026.10.24)
// TESFile::unk000, TESFile::unk15C, g_warningSuppressionCount, g_higherVersionFormat, FormatWarningMessage: GUESS(low); offsets, globals, and call observed in listing
#pragma once

#include <cstddef>
#include <cstdint>

extern long g_warningSuppressionCount;
extern const char g_higherVersionFormat[];

std::int32_t FormatWarningMessage(char* a_buffer, std::size_t a_size, const char* a_format, ...);

class TESFile
{
public:
    bool IsHigherVersionThanSupported() const;

    std::uint8_t unk000[0x58];   // 000
    char         fileName[260];  // 058
    std::uint8_t unk15C[0x2D0];  // 15C
    float        version;        // 42C
};
static_assert(offsetof(TESFile, fileName) == 0x58, "TESFile::fileName offset");
static_assert(offsetof(TESFile, version) == 0x42C, "TESFile::version offset");
