// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// TESForm: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); 0x20-byte polymorphic base of TESRace
// TESRace: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); TESForm and TESFullName bases only
// Actor, Actor::race, Actor::GetRaceFullName: CRASHLOGGER_PDB(59818@2026.10.24)
// TESForm::unk08, Actor::unk00: GUESS(low); unresolved bytes before represented members
#pragma once

#include <cstddef>
#include <cstdint>

#include "../forms/TESFullName.h"

class TESForm
{
public:
    virtual ~TESForm();

    std::uint8_t unk08[0x18];
};
static_assert(sizeof(TESForm) == 0x20, "TESForm size");

class TESRace : public TESForm, public TESFullName
{
};

class Actor
{
public:
    const char* GetRaceFullName() const;

    std::uint8_t unk00[0x1f8];
    TESRace*     race;  // 0x1f8
};
static_assert(offsetof(Actor, race) == 0x1f8, "Actor::race offset");
