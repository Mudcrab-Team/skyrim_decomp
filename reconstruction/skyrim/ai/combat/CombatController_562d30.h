// Source exposure: mixed (pinned image listing and CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// CombatController, CombatController::CheckCombatArea, Actor, Actor::GetBoundRadius: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPoint3, CombatAreaBase, CheckLocation, pos, combatArea, unknown00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

class Actor
{
public:
    float GetBoundRadius() const;

    std::uint8_t unknown00[0x54];
    NiPoint3 pos;  // 54
};
static_assert(offsetof(Actor, pos) == 0x54, "pos offset");

class CombatAreaBase
{
public:
    virtual ~CombatAreaBase();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual bool CheckLocation(const NiPoint3& a_pos, float a_radius) const;  // slot 06 (+0x30)
};

class CombatController
{
public:
    bool CheckCombatArea(Actor* a_actor) const;  // compared: 0x562d30

    std::uint8_t unknown00[0x98];
    CombatAreaBase* combatArea;  // 98
};
static_assert(offsetof(CombatController, combatArea) == 0x98, "combatArea offset");
