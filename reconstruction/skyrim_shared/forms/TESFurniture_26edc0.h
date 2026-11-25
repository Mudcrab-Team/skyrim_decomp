// Source exposure: mixed (pinned-image observations; community declarations).
// Code origin: original; partial declarations from labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESFurniture, EntryPointData, entryPointDataArray, entryPoint, keyword: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// disabledEntryPoints: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSKeyword: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESFurniture::GetEntryPointFlags: SIBLING(fo4-private@1b765c70, author-permission)
// Function26edc0, unknown00, capacity, unknownD4, count, unknownDC: GUESS(low); unknown storage and descriptive array metadata
#pragma once
#include <cstddef>
#include <cstdint>
class BGSKeyword;
class TESFurniture
{
public:
    struct EntryPointData
    {
        std::uint32_t entryPoint;
        std::uint32_t disabledEntryPoints;
        BGSKeyword* keyword;
    };
    BGSKeyword* Function26edc0(std::uint32_t entryPoint) const;
    std::uint32_t GetEntryPointFlags(std::uint32_t entryPoint) const;
    std::uint8_t unknown00[0xc8];
    EntryPointData* entryPointDataArray;
    std::uint32_t capacity;
    std::uint32_t unknownD4;
    std::uint32_t count;
    std::uint32_t unknownDC;
};
static_assert(offsetof(TESFurniture, entryPointDataArray) == 0xc8, "Observed array offset");
static_assert(offsetof(TESFurniture, count) == 0xd8, "Observed count offset");
static_assert(sizeof(TESFurniture::EntryPointData) == 0x10, "Community entry layout");
