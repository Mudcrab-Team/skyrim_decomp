// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Func_147ac0::SetKeyValue, treated as adapted: shaped like NiTStringTemplateMap::SetValue in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:4482
// SPDX-License-Identifier: CC0-1.0
// Node147ac0: GUESS(low)
// Func_147ac0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Node147ac0
{
    Node147ac0* next;
    const char* key;
    std::uint64_t value;
};

struct Func_147ac0
{
    void SetKeyValue(Node147ac0* node, const char* key, std::uint64_t value);

    std::uint8_t unk00[0x20];
    bool copyKeys;
};
