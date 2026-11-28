// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// TESFullName, TESFullName::GetFullName_14038EE10: CRASHLOGGER_PDB(59818@2026.10.24)
// BSFixedString3ee420, GetCStr, DefaultNameEntry, DefaultNameHolder, gDefaultNames, fullName, defaultNameIndex: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct BSFixedString3ee420
{
    const char* GetCStr() const;

    const char* data;  // 00
};
static_assert(sizeof(BSFixedString3ee420) == 0x08, "BSFixedString3ee420 size");

struct DefaultNameHolder
{
    std::uint64_t unk00;  // 00
    const char*   name;   // 08
};
static_assert(offsetof(DefaultNameHolder, name) == 0x08, "name offset");

struct DefaultNameEntry
{
    DefaultNameHolder* holder;       // 00
    std::uint8_t       unk08[0x20];  // 08
};
static_assert(sizeof(DefaultNameEntry) == 0x28, "DefaultNameEntry size");

extern DefaultNameEntry gDefaultNames[];

class TESFullName
{
public:
    const char* GetFullName_14038EE10() const;  // compared: 0x3ee420

    std::uint8_t        unk00[0x08];       // 00
    BSFixedString3ee420 fullName;          // 08
    std::uint16_t       unk10;             // 10
    std::uint16_t       defaultNameIndex;  // 12
};
static_assert(offsetof(TESFullName, fullName) == 0x08, "fullName offset");
static_assert(offsetof(TESFullName, defaultNameIndex) == 0x12, "defaultNameIndex offset");
