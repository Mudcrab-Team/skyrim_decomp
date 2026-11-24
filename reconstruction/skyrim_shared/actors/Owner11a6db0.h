// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Code origin: Stamped as a twin of matched 0x6926f0 (skyrim_shared/actors/Actor_690e50): source copied, names replaced by placeholders.
// Origin: target listing and anonymous sibling hints.
// BGSInventoryItem, ActorMover: GUESS(low)
// Function11a6db0, Owner11a6db0: GUESS(low) STANDIN
// CalcArmorRating, GetArmorBaseFactorSum, GetRunSpeed, GetMovementSpeed, GetCurrentActorMover, IsPathing, TESObjectREFR, SetDelete: GUESS(low) STANDIN
#pragma once
#include "Actor_690e50.h"

class Owner11a6db0 : public TESObjectREFR {
public:
    float CalcArmorRating(const BGSInventoryItem&, unsigned int) const;
    float GetArmorBaseFactorSum();
    float GetMovementSpeed(unsigned int, unsigned int) const;
    float Function11a6db0() const;
    float GetRunSpeed() const;
    ActorMover* GetCurrentActorMover() const;
    bool IsPathing() const;
    void SetDelete(bool);
};

