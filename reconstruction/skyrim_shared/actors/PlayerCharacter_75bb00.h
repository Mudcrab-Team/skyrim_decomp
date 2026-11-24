// Source exposure: binary-analysis (the pinned image listing; community names).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PlayerCharacter, Actor, PerkEntryVisitor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to what this function uses
// ForEachPerk, Visit: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; Actor::ForEachPerk is declared non-virtual here
// unk4C0, unk4D0: GUESS(low); the array is at 0x4C0 in this build
#pragma once

#include <cstdint>
#include <cstddef>

class BGSPerkEntry;

class PerkEntryVisitor
{
public:
    virtual int Visit(BGSPerkEntry* perkEntry) = 0;
};

class Actor
{
public:
    void ForEachPerk(PerkEntryVisitor& visitor) const;
};

class PlayerCharacter : public Actor
{
public:
    void ForEachPerk(PerkEntryVisitor& visitor) const;

    char unk000[0x4C0];
    BGSPerkEntry** unk4C0;
    std::uint32_t unk4C8;
    std::uint32_t unk4CC;
    std::uint32_t unk4D0;
};
