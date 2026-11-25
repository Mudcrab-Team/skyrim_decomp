// Source exposure: mixed (the listing of the pinned image; names from the sibling declarations used by the adapted body).
// Code origin: names and the member array adapted from the sibling; width and callee checked against the listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/ActorValueStorage.cpp:66
// Modifiers, Modifiers::LoadGame, Modifiers::fModifiers, BGSLoadFormBuffer: SIBLING(fo4-private@1b765c70, author-permission)
// BGSLoadFormBuffer::LoadDataEndian: SIBLING(fo4-private@1b765c70, author-permission); the community header names it in BGSLoadGameBuffer
#pragma once

class BGSLoadFormBuffer
{
public:
    void LoadDataEndian(void* a_data, unsigned int a_size, unsigned int a_count);  // bound: 0x637e70
};

class Modifiers
{
public:
    void LoadGame(BGSLoadFormBuffer* a_buffer);  // compared: 0x6e2ac0

    float fModifiers[3];  // 00
};
static_assert(sizeof(Modifiers) == 0xC, "Modifiers size");
