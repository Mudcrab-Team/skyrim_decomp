// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatPositionMap.cpp:53
// CombatPosition, LoadGame, fRadius, BGSLoadGameBuffer, LoadDataEndian: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// location: GUESS(low)
#pragma once

#include <cstdint>

class BGSLoadGameBuffer
{
public:
    void LoadDataEndian(void* a_dest, std::uint32_t a_size, std::uint32_t a_width);
};

class CombatPosition
{
public:
    void LoadGame(BGSLoadGameBuffer* a_buffer);  // compared: 0x8ee740

    float location[3];
    float fRadius;
};
