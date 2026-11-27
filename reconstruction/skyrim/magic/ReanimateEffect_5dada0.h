// Source exposure: mixed (community declarations; the listing of the pinned image).
// Code origin: names from CharmedBaryon/CommonLibSSE-NG (MIT) and the sibling declaration order; only what the compared function uses is modelled
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicTarget::GetTargetAsActor, Actor::GetLevel: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MagicTarget, Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReanimateEffect, ReanimateEffect::CheckTarget, ActiveEffectFactory::CheckTargetArgs, CheckTargetArgs::pTarget, CheckTargetArgs::pCaster, ActiveEffectFactory::CheckTargetLevelMagnitude, MagicUtilities::CanBeReanimated: SIBLING(fo4-private@1b765c70, author-permission); names the sibling body uses, the Skyrim owner of the helpers is not known
#pragma once

class Actor
{
public:
    unsigned short GetLevel() const;  // bound: 0x6797a0
};

class MagicTarget
{
public:
    Actor* GetTargetAsActor();  // bound: 0x5d26e0
};

namespace ActiveEffectFactory
{
    struct CheckTargetArgs
    {
        MagicTarget* pTarget;  // 00
        Actor* pCaster;        // 08
    };

    bool CheckTargetLevelMagnitude(unsigned short a_level, CheckTargetArgs& a_args);  // bound: 0x5ba950
}

namespace MagicUtilities
{
    bool CanBeReanimated(Actor& a_actor);  // bound: 0x5d5800
}

class ReanimateEffect
{
public:
    static bool CheckTarget(ActiveEffectFactory::CheckTargetArgs& a_args);  // compared: 0x5dada0
};
