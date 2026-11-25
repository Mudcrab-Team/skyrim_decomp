// Source exposure: mixed (community declarations, authorized sibling game code, pinned-image observations).
// Code origin: original; observed accesses and labelled declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ValueModifierEffect, MagicTarget, Actor, actorValue, target: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor::IsInCombat: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function5e7980, ActorVTable, reservedSlots, stateFlags, effectData, actorData, unknown58: GUESS(low) STANDIN
// GetTargetAsActor: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include <cstdint>
#include <cstddef>
struct Actor;
struct ActorVTable {
    void* reservedSlots[0xE3];
    bool (*IsInCombat)(const Actor*);
};
struct Actor {
    ActorVTable* vtable;
    std::uint8_t actorData[0xE0];
    std::uint32_t stateFlags;
};
class MagicTarget {
public:
    Actor* GetTargetAsActor();
};
class ValueModifierEffect {
public:
    bool Function5e7980();
    std::uint8_t effectData[0x50];
    MagicTarget* target;
    std::uint8_t unknown58[0x38];
    std::uint32_t actorValue;
};
static_assert(offsetof(Actor, stateFlags) == 0xE8, "actor flags offset");
static_assert(offsetof(ValueModifierEffect, target) == 0x50, "effect target offset");
static_assert(offsetof(ValueModifierEffect, actorValue) == 0x90, "actor value offset");
