// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: TESActorBase::RemoveChange follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesactorbase.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesactorbase.cpp:260
// TESActorBase, TESActorBase::RemoveChange, TESForm, TESForm::formID, TESForm::RemoveChange, actorData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESBoundAnimObject, TESActorBaseData, BGSSaveLoadGame: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESActorBaseData::ClearChangeFlags: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// BGSSaveLoadGame::ShouldRemoveChanges: CRASHLOGGER_PDB(59818@2026.10.24)
// gBGSSaveLoadGame, unk20: GUESS(low)
#pragma once

#include <cstdint>
#include "TESForm.h"

class BGSSaveLoadGame
{
public:
    bool ShouldRemoveChanges(TESForm* a_form);
};
extern BGSSaveLoadGame* gBGSSaveLoadGame;

class TESBoundAnimObject : public TESForm
{
    std::uint8_t unk20[0x10];
};

class TESActorBaseData
{
public:
    void ClearChangeFlags(std::uint32_t a_changeFlags);
};

class TESActorBase : public TESBoundAnimObject
{
public:
    void RemoveChange(std::uint32_t a_changeFlags) override;

    TESActorBaseData actorData;
};
