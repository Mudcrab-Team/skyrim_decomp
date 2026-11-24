// Source exposure: mixed (CrashLogger layout, sibling shape and the pinned image listing).
// Code origin: adapted from the cited sibling body; layout checked against the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESFileContainer.cpp:189
// TESFileArray: CRASHLOGGER_PDB(59818@2026.10.24); size 0x10
// TESFileArray::Matches: SIBLING(fo4-private@1b765c70, author-permission)
// pElements, uiNumElements: GUESS(medium); the sibling names them in its BSStaticArray base
// TESFile: STANDIN SIBLING(fo4-private@1b765c70, author-permission)
// AllocateElements: GUESS(low)
#pragma once

#include <cstdint>

class TESFile;

class TESFileArray
{
public:
    bool Matches(const TESFile* const* a_files, std::uint32_t a_size) const;  // compared: 0x1e2840

    TESFile** pElements;  // 00
    std::uint32_t uiNumElements;  // 08
    std::uint32_t pad0C;  // 0C
};
static_assert(sizeof(TESFileArray) == 0x10, "TESFileArray size");
