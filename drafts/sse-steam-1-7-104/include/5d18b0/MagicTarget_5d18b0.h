// Exposure detail: (community declarations; pinned-image observations).
// Source exposure: mixed
// Code origin: original; declarations from labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// MagicTarget, MagicTarget::HasMagicEffectThatCausesDamage: CRASHLOGGER_PDB(59818@2026.10.24)
// ActiveEffect, EffectNode, DamageVisitor, remaining members: STANDIN GUESS(low)

#pragma once
#include <cstdint>

struct ActiveEffect;
struct EffectNode { ActiveEffect* effect; EffectNode* next; };
class DamageVisitor
{
public:
    virtual ~DamageVisitor() {}
    virtual std::uint32_t Accept(ActiveEffect* effect);
    bool found = false;
};
class MagicTarget
{
public:
    virtual ~MagicTarget();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual EffectNode* GetActiveEffectList();
    bool HasMagicEffectThatCausesDamage();
};
