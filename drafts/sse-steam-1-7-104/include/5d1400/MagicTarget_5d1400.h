// Exposure detail: (pinned-image observations; community declarations; permitted sibling algorithm lead).
// Source exposure: mixed
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicTarget, GetActiveEffectList, ActiveEffect: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DispelAllSpells_140552E10: CRASHLOGGER_PDB(59818@2026.10.24)
// EffectNode, DispelVisitor, DispelVisitorTable, dispelVisitorTable, Accept, now: GUESS(low)

#pragma once
#include <cstdint>
class ActiveEffect;
struct EffectNode
{
    ActiveEffect* item;
    EffectNode* next;
};
struct DispelVisitor;
struct DispelVisitorTable
{
    void* destructor;
    std::uint32_t (*Accept)(DispelVisitor*, ActiveEffect*);
};
struct DispelVisitor
{
    const DispelVisitorTable* vptr;
    bool now;
};
extern const DispelVisitorTable dispelVisitorTable;
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
