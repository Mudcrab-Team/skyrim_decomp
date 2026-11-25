// Source exposure: mixed (pinned-image observations; community declarations; permitted sibling algorithm lead).
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicTarget, GetActiveEffectList, ActiveEffect: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DispelAllSpells_140552E10: CRASHLOGGER_PDB(59818@2026.10.24)
// EffectNode, EffectVisitor, DispelVisitor, Accept, now: GUESS(low)
#pragma once
#include <cstdint>
class ActiveEffect;
struct EffectNode
{
    ActiveEffect* item;
    EffectNode* next;
};
class EffectVisitor
{
public:
    virtual ~EffectVisitor() {}
    virtual std::uint32_t Accept(ActiveEffect* effect) = 0;
};
class DispelVisitor : public EffectVisitor
{
public:
    explicit DispelVisitor(bool dispelNow) : now(dispelNow) {}
    std::uint32_t Accept(ActiveEffect* effect) override;
    bool now;
};
class MagicTarget
{
public:
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual EffectNode* GetActiveEffectList() = 0;
    void DispelAllSpells_140552E10(bool now);
};
