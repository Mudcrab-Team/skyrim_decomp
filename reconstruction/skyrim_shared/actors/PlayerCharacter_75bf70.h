// Source exposure: binary-analysis (the pinned image listing; community names).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PlayerCharacter, Actor, PerkEntryVisitor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to what this function uses
// ApplyPerksFromBase, Visit: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; Actor::ApplyPerksFromBase is declared non-virtual here
// PerkApplier, unk4C0, unk4D0: GUESS(low); the array is at 0x4C0 in this build
#pragma once

#include <cstdint>
#include <cstddef>

class BGSPerkEntry;
class PlayerCharacter;

class PerkEntryVisitor
{
public:
    virtual int Visit(BGSPerkEntry* perkEntry) = 0;
};

class PerkApplier : public PerkEntryVisitor
{
public:
    explicit PerkApplier(PlayerCharacter* owner) : owner(owner) {}
    virtual int Visit(BGSPerkEntry* perkEntry);

    PlayerCharacter* owner;
};

class Actor
{
public:
    void ApplyPerksFromBase();
};

class PlayerCharacter : public Actor
{
public:
    void ApplyPerksFromBase();

    char unk000[0x4C0];
    BGSPerkEntry** unk4C0;
    std::uint32_t unk4C8;
    std::uint32_t unk4CC;
    std::uint32_t unk4D0;
};
