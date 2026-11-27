// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESImagespaceManager::IsScreenshotSaved: GUESS(low); the name comes from the inventory
// TESImagespaceManager and its members: STANDIN GUESS(low); only what the function reads
#pragma once

#include <cstdint>
#include <cstddef>

class TESImagespaceManager
{
public:
    bool IsScreenshotSaved();  // compared: 0x14eedf0

    std::uint8_t unk00[0x211];
    bool unk211;               // 211
    std::uint8_t unk212[6];
    void* unk218;              // 218
};
static_assert(offsetof(TESImagespaceManager, unk218) == 0x218, "unk218 offset");
