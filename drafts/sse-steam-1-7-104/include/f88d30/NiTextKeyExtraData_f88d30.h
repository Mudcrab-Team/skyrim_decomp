// Exposure detail: (community names; pinned-image observations).
// Source exposure: mixed
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// NiTextKeyExtraData, NiTextKeyExtraData::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiObject::IsEqual, NiTextKey, time, text, keyCount, keys: GUESS(low)
// objectStorage, keyCount offset, keys offset: OBSERVED

#pragma once
#include <cstdint>
#include <cstddef>
class NiObject {
public:
    bool IsEqual(NiObject* other);
    std::uint8_t objectStorage[0x18];
};
struct NiTextKey {
    float time;
    const char* text;
};
class NiTextKeyExtraData : public NiObject {
public:
    bool IsEqual(NiObject* other);
    std::uint32_t keyCount;
    NiTextKey* keys;
};
static_assert(offsetof(NiTextKeyExtraData, keyCount) == 0x18, "key count offset");
static_assert(offsetof(NiTextKeyExtraData, keys) == 0x20, "keys offset");
