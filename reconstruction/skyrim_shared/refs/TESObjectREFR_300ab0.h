// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectREFR: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR::GetEncounterZone, TESObjectCELL::GetEncounterZone: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// TESObjectREFR::GetWorldspace, TESObjectREFR::parentCell, TESObjectREFR::extraList, TESWorldSpace::encounterZone, ExtraDataList::GetEncounterZone: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the class bodies keep only what the compared code uses
#pragma once

#include <cstdint>
#include <cstddef>

class BGSEncounterZone;

class TESWorldSpace
{
public:
    unsigned char pad00[0x220];
    BGSEncounterZone* encounterZone;  // 220
};

class TESObjectCELL
{
public:
    BGSEncounterZone* GetEncounterZone() const;
};

class ExtraDataList
{
public:
    BGSEncounterZone* GetEncounterZone() const;
};

class TESObjectREFR
{
public:
    TESWorldSpace* GetWorldspace() const;
    BGSEncounterZone* GetEncounterZone() const;  // compared: 0x300ab0

    unsigned char pad00[0x60];
    TESObjectCELL* parentCell;  // 60
    unsigned char pad68[8];
    ExtraDataList extraList;  // 70
};
