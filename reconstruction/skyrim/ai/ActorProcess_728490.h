// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ActorProcess, ActorProcess::VisitActorPerks, ActorPerkVisitor, Actor, TESNPC, PerkRankData: GUESS(low) STANDIN
// BGSPerkRankArray, BGSPerkRankArray::VisitPerks, PerkRankVisitor: GUESS(low) STANDIN; names of the matched unit at 0x1db3d0
// perkRanks, baseForm: GUESS(low); offsets observed in the matched units at 0x1db3d0 and 0x674b70
#pragma once

#include <cstdint>
#include <cstddef>

struct PerkRankData;

class PerkRankVisitor
{
public:
    virtual int Visit(PerkRankData* a_perk) = 0;
};

class BGSPerkRankArray
{
public:
    void VisitPerks(PerkRankVisitor* a_visitor);

    unsigned char unk00[0x18];
};

struct TESNPC
{
    std::uint8_t pad00[0x138];
    BGSPerkRankArray perkRanks;  // 138
};

struct Actor
{
    std::uint8_t pad00[0x40];
    TESNPC* baseForm;  // 040
};

class ActorPerkVisitor : public PerkRankVisitor
{
public:
    explicit ActorPerkVisitor(Actor* a_actor) : actor(a_actor) {}
    int Visit(PerkRankData* a_perk) override;

    Actor* actor;
};

class ActorProcess
{
public:
    void VisitActorPerks(Actor* a_actor);  // compared: 0x728490

    void* unk00;
    void* middleHigh;  // 008
};
