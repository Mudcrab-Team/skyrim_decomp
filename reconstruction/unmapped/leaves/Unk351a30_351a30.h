// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Unk351a30: GUESS(low)
// Unk351a30::DispelAllSpells: GUESS(low); AddressLibraryDatabase and CrashLogger name the handler DispelAllSpells
// MagicTarget::DispelAllSpells: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// TESObjectREFR, Actor, MagicTarget: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the layout the handler uses
// GameFunc__handler::DispelAllSpells: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectREFR
{
public:
    virtual ~TESObjectREFR();
    std::uint8_t unknown08[0x98];  // 08
};
static_assert(sizeof(TESObjectREFR) == 0xA0, "TESObjectREFR stand-in size");

class MagicTarget
{
public:
    virtual ~MagicTarget();
    void DispelAllSpells(bool a_force);
};

class Actor : public TESObjectREFR, public MagicTarget
{
public:
    ~Actor() override;
};

class Unk351a30
{
public:
    static bool DispelAllSpells(void* a_params, void* a_scriptData, TESObjectREFR* a_thisObj);  // compared: 0x351a30
};
