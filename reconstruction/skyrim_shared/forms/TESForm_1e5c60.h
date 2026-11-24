// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESForm, TESForm::Function1e5c60, FormTypeEntry, gFormTypeTable, name, unk08: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct FormTypeEntry
{
    const char* name;
    std::uint64_t unk08;
    std::uint64_t unk10;
};

// gFormTypeTable: GUESS(low); 0x8a entries of 0x18 bytes, data at 0x2078218
extern FormTypeEntry gFormTypeTable[0x8A];

extern "C" __declspec(dllimport) int __cdecl _stricmp(const char* a_lhs, const char* a_rhs);

class TESForm
{
public:
    static std::uint32_t Function1e5c60(const char* a_name);  // compared: 0x1e5c60
};
