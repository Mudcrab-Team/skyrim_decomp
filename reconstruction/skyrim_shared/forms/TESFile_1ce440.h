// Source exposure: mixed (permitted sibling game code; pinned-image observations).
// Code origin: original declarations from target observations and labelled naming sources
// TESFile, TESFile::FixFormIdForThisFile, recordFlags, compileIndex, smallFileCompileIndex: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include <cstdint>
#include <cstddef>

class TESFile {
public:
    void FixFormIdForThisFile(std::uint32_t& formID) const;
    std::uint8_t prefix[0x438];
    std::uint32_t recordFlags;
    std::uint8_t gap43C[0x3C];
    std::uint8_t compileIndex;
    std::uint8_t gap479;
    std::uint16_t smallFileCompileIndex;
};
static_assert(offsetof(TESFile, recordFlags) == 0x438, "flags offset");
static_assert(offsetof(TESFile, compileIndex) == 0x478, "compile index offset");
static_assert(offsetof(TESFile, smallFileCompileIndex) == 0x47A, "small index offset");
