// Source exposure: mixed (community declarations; pinned image listing; CrashLogger PDB names).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectARMA, TESObjectARMA::race, TESObjectARMA::additionalRaces, TESRace, TESRace::armorParentRace: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectARMA::HasRace: CRASHLOGGER_PDB(59818@2026.10.24)
// RaceArray27ca80: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class TESRace
{
public:
    std::uint8_t unk00[0x440];  // 0x000
    TESRace* armorParentRace;   // 0x440
};

struct RaceArray27ca80
{
    TESRace** data;         // 0x00
    std::uint32_t capacity; // 0x08
    std::uint32_t unk0C;    // 0x0C
    std::uint32_t size;     // 0x10
};

class TESObjectARMA
{
public:
    bool HasRace(const TESRace* a_race) const;

    std::uint8_t unk00[0x28];        // 0x000
    TESRace* race;                   // 0x028
    std::uint8_t unk30[0x120];       // 0x030
    RaceArray27ca80 additionalRaces; // 0x150
};

static_assert(offsetof(TESRace, armorParentRace) == 0x440, "armorParentRace offset");
static_assert(offsetof(TESObjectARMA, race) == 0x28, "race offset");
static_assert(offsetof(TESObjectARMA, additionalRaces) == 0x150, "additionalRaces offset");
static_assert(offsetof(RaceArray27ca80, size) == 0x10, "size offset");
