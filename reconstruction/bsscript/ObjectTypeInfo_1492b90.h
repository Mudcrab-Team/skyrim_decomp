// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// ObjectTypeInfo, ObjectTypeInfo::GetVariableCount: CRASHLOGGER_PDB(59818@2026.10.24)
// parent, flags: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class ObjectTypeInfo
{
public:
    std::uint32_t GetVariableCount() const;  // compared: 0x1492b90

    std::uint64_t unk00[2];  // 00
    ObjectTypeInfo* parent;  // 10
    std::uint64_t unk18;  // 18
    std::uint32_t flags;  // 20
};
static_assert(offsetof(ObjectTypeInfo, parent) == 0x10, "parent offset");
static_assert(offsetof(ObjectTypeInfo, flags) == 0x20, "flags offset");
