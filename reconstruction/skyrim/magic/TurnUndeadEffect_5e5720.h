// Source exposure: mixed (community declarations; the listing of the pinned image).
// Code origin: names from CharmedBaryon/CommonLibSSE-NG (MIT) and the sibling declaration order; only what the compared function uses is modelled
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicTarget::GetTargetAsActor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MagicTarget, Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TurnUndeadEffect, TurnUndeadEffect::CheckTarget, TargetValueModifierEffect, TargetValueModifierEffect::CheckTarget, ActiveEffectFactory::CheckTargetArgs, CheckTargetArgs::pTarget, CheckTargetArgs::pCaster, Actor::IsUndead: SIBLING(fo4-private@1b765c70, author-permission); names the sibling body uses
#pragma once

class Actor
{
public:
    bool IsUndead() const;  // bound: 0x6aca60
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
}

class TargetValueModifierEffect
{
public:
    static bool CheckTarget(ActiveEffectFactory::CheckTargetArgs& a_args);  // bound: 0x5e55d0
};

class TurnUndeadEffect : public TargetValueModifierEffect
{
public:
    static bool CheckTarget(ActiveEffectFactory::CheckTargetArgs& a_args);  // compared: 0x5e5720
};
