// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// Actor, BGSInventoryItem, CalcArmorRating, GetArmorBaseFactorSum, GetWalkSpeed, GetRunSpeed, GetMovementSpeed, ActorMover, GetCurrentActorMover, IsPathing, TESObjectREFR, SetDelete, ProcessLists, processLists, AddActorToTempChangeList: GUESS(low)
#pragma once
class BGSInventoryItem;
class Actor;
class TESObjectREFR { public: void SetDelete(bool); };
class ProcessLists { public: void AddActorToTempChangeList(Actor*); };
extern ProcessLists* processLists;
class ActorMover { public: bool IsPathing() const; };
class Actor : public TESObjectREFR {
public:
    float CalcArmorRating(const BGSInventoryItem&, unsigned int) const;
    float GetArmorBaseFactorSum();
    float GetMovementSpeed(unsigned int, unsigned int) const;
    float GetWalkSpeed() const;
    float GetRunSpeed() const;
    ActorMover* GetCurrentActorMover() const;
    bool IsPathing() const;
    void SetDelete(bool);
};
