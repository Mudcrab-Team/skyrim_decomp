// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: signatures from anonymous sibling hints.
// CalcArmorRating, GetArmorBaseFactorSum, GetWalkSpeed, GetRunSpeed, IsPathing, SetDelete: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:6642
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:6650
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:1015
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:1026
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:3201
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:4273
// 0x6bd520 Actor::CalcArmorRating
// 0x6bdd70 Actor::GetArmorBaseFactorSum
// 0x6926f0 Actor::GetWalkSpeed
// 0x692650 Actor::GetRunSpeed
// 0x6a6980 Actor::IsPathing
// 0x690e50 Actor::SetDelete
#include "Actor.h"
float Actor::CalcArmorRating(const BGSInventoryItem&, unsigned int) const { return 0.0f; }
float Actor::GetArmorBaseFactorSum() { return 0.0f; }
float Actor::GetWalkSpeed() const { return GetMovementSpeed(0, 0); }
float Actor::GetRunSpeed() const { return GetMovementSpeed(1, 1); }
bool Actor::IsPathing() const { return GetCurrentActorMover()->IsPathing(); }
void Actor::SetDelete(bool deleted) { TESObjectREFR::SetDelete(deleted); if (deleted) processLists->AddActorToTempChangeList(this); }
