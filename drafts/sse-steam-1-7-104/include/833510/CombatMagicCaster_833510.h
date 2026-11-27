// Code origin: original reconstruction from local binary analysis; community declarations only.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatMagicCaster, CombatController, MagicItem, Actor, GetMagicTarget, GetDelivery, magicItem, attackerHandle, targetHandle, handleCount, cachedAttacker, cachedTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CombatController, MagicItem, Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TargetResult, handle, actor, unknown00, unknown30, unknown00Slots, VTable, vtable: GUESS(low); partial result and unaccessed storage.

#pragma once

#include <cstddef>
#include <cstdint>

class Actor;
struct TargetResult
{
    std::uint32_t handle;
    Actor* actor;
};

class MagicItem
{
public:
    // Explicit stand-in for the observed virtual dispatch table.
    struct VTable
    {
        void* unknown00Slots[0x57];
        int (*GetDelivery)(const MagicItem*);
    };
    VTable* vtable;
};

struct CombatController
{
    unsigned char unknown00[0x28];
    std::uint32_t attackerHandle;
    std::uint32_t targetHandle;
    unsigned char unknown30[0x98];
    std::uint32_t handleCount;
    Actor* cachedAttacker;
    Actor* cachedTarget;
};

class CombatMagicCaster
{
public:
    TargetResult GetMagicTarget(const CombatController* controller) const;

    unsigned char unknown00[0x18];
    MagicItem* magicItem;
};
static_assert(offsetof(CombatController, handleCount) == 0xC8, "handle count offset");
static_assert(offsetof(CombatController, cachedTarget) == 0xD8, "cached target offset");
static_assert(offsetof(CombatMagicCaster, magicItem) == 0x18, "magic item offset");
