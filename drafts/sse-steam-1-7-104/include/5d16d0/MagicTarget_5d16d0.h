// Exposure detail: (community declarations; pinned-image observations).
// Source exposure: mixed
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicTarget, HasMagicEffect, ActiveEffect, EffectSetting, GetBaseObject, GetActiveEffectList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// EffectListNode, MagicTargetVTable, vtable, slots: STANDIN OBSERVED

#pragma once
#include <cstdint>
class EffectSetting;
class ActiveEffect
{
public:
    EffectSetting* GetBaseObject();
};
struct EffectListNode
{
    ActiveEffect* effect;
    EffectListNode* next;
};
class MagicTarget;
struct MagicTargetVTable
{
    void* slots[7];
    EffectListNode* (*GetActiveEffectList)(MagicTarget*);
};
class MagicTarget
{
public:
    MagicTargetVTable* vtable;
    std::uint32_t HasMagicEffect(EffectSetting* effect);
};
