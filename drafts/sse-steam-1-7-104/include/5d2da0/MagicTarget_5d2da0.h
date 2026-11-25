// Exposure detail: (community naming and local pinned-image observations).
// Source exposure: mixed
// Code origin: original; no sibling body reused
// SPDX-License-Identifier: CC0-1.0
// MagicTarget, MagicTarget::FindFirstEffectWithArchetype: CRASHLOGGER_PDB(59818@2026.10.24)
// ActiveEffect, EffectSetting, EffectListNode, their members, MagicTarget::GetActiveEffects: STANDIN GUESS(low)

#pragma once
#include <cstdint>
#include <cstddef>

struct EffectSetting {
    std::uint8_t pad00[0xc0];
    std::uint32_t archetype;
};
struct ActiveEffect {
    EffectSetting* GetBaseObject();
    std::uint8_t pad00[0x7c];
    std::uint32_t flags;
};
struct EffectListNode {
    ActiveEffect* effect;
    EffectListNode* next;
};
class MagicTarget {
public:
    virtual void Unk00();
    virtual void Unk08();
    virtual void Unk10();
    virtual void Unk18();
    virtual void Unk20();
    virtual void Unk28();
    virtual void Unk30();
    virtual EffectListNode* GetActiveEffects();
    ActiveEffect* FindFirstEffectWithArchetype(std::uint32_t archetype, bool includeInactive);
};
