// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// NameComponent1c50d0, Race1c50d0, Obj1c50d0, SortRaceArray: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" {
    __declspec(dllimport) int __cdecl _stricmp(const char* a_lhs, const char* a_rhs);
}

struct NameComponent1c50d0
{
    virtual ~NameComponent1c50d0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual const char* GetName() const;
};

struct Race1c50d0
{
    std::uint8_t unk00[0x20];       // 00
    NameComponent1c50d0 fullName20; // 20
};

struct Obj1c50d0
{
    static std::int32_t SortRaceArray(const Race1c50d0* a_lhs, const Race1c50d0* a_rhs);  // compared: 0x1c50d0
};
