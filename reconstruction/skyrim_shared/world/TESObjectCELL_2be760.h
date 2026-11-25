// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original; naming and layout declarations from the labelled community source.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectCELL, TESWorldSpace, BGSEncounterZone, ExtraDataList, cellFlags, extraList, worldSpace, encounterZone, GetEncounterZone: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function2be760: GUESS(low); placeholder for the observed lookup without the loaded-cell shortcut.
// TESObjectCELL, TESWorldSpace, ExtraDataList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); accessed layout only.
#pragma once
#include <cstddef>
#include <cstdint>

class BGSEncounterZone;
class ExtraDataList {
public:
    BGSEncounterZone* GetEncounterZone() const;
    std::uint8_t unknown00[0x18];
};
class TESWorldSpace {
public:
    std::uint8_t unknown00[0x220];
    BGSEncounterZone* encounterZone;
};
class TESObjectCELL {
public:
    BGSEncounterZone* Function2be760() const;
    std::uint8_t unknown00[0x40];
    std::uint16_t cellFlags;
    std::uint8_t unknown42[6];
    ExtraDataList extraList;
    std::uint8_t unknown60[0xc8];
    TESWorldSpace* worldSpace;
};
static_assert(offsetof(TESObjectCELL, cellFlags) == 0x40, "cell flags offset");
static_assert(offsetof(TESObjectCELL, extraList) == 0x48, "extra list offset");
static_assert(offsetof(TESObjectCELL, worldSpace) == 0x128, "world space offset");
static_assert(offsetof(TESWorldSpace, encounterZone) == 0x220, "encounter zone offset");
