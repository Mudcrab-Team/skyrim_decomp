// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// NiColorData, NiColorData::ctor: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, numKeys, keys, keyType, keySize: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class NiObject
{
public:
    NiObject();
    virtual ~NiObject();

    std::uint32_t refCount;  // 08
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

class NiColorData : public NiObject
{
public:
    NiColorData();  // compared: 0x2a8a80

    std::uint32_t numKeys;  // 10
    void* keys;  // 18
    std::uint32_t keyType;  // 20
    std::uint8_t keySize;  // 24
};
static_assert(offsetof(NiColorData, numKeys) == 0x10, "numKeys offset");
static_assert(offsetof(NiColorData, keys) == 0x18, "keys offset");
static_assert(offsetof(NiColorData, keyType) == 0x20, "keyType offset");
static_assert(offsetof(NiColorData, keySize) == 0x24, "keySize offset");
