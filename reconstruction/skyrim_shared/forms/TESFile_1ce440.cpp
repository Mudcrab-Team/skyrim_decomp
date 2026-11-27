// Source exposure: mixed (permitted sibling game code; pinned-image observations).
// Code origin: adapted from labelled sibling game code with target-observed layout
// Cookbook: 0x1ce440 16
// 0x1ce440 TESFile::FixFormIdForThisFile
// TESFile::FixFormIdForThisFile: CRASHLOGGER_PDB(59818@2026.10.24)
// Adapted bodies: TESFile::FixFormIdForThisFile from AdjustFormIDFileIndex in fo4-private@1b765c70 (author-permission); TestBit is original from cookbook rule 16
// Sibling source: fo4-private@1b765c70 src/Shared/FileIO/TESFile.cpp:68
// TESFile::AdjustFormIDFileIndex: SIBLING(fo4-private@1b765c70, author-permission)
#include "TESFile_1ce440.h"

// TestBit: GUESS(low)
inline bool TestBit(std::uint32_t flags, std::uint32_t bit)
{
    return ((flags >> bit) & 1) != 0;
}

// Replace the file index while preserving the local form identifier.
void TESFile::FixFormIdForThisFile(std::uint32_t& formID) const
{
    reinterpret_cast<std::uint8_t*>(&formID)[3] = 0;
    if (TestBit(recordFlags, 9)) {
        formID &= 0xFFF;
        formID |= 0xFE000000;
        formID |= smallFileCompileIndex << 12;
        return;
    }
    formID |= static_cast<std::uint32_t>(compileIndex) << 24;
}
