// Source exposure: mixed (community declarations; the listing of the pinned image).
// Code origin: names and slot order from CharmedBaryon/CommonLibSSE-NG (MIT); only the compared virtual is modelled
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AbsorbEffect, AbsorbEffect::ModifyOnFinish, ValueModifierEffect::ModifyOnFinish: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ValueModifierEffect, Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); empty or one-slot stand-ins, the slots before 1F are not modelled
#pragma once

class Actor;

class ValueModifierEffect
{
public:
    virtual void ModifyOnFinish(Actor* a_caster, Actor* a_target, float a_value);  // 1F
};

class AbsorbEffect : public ValueModifierEffect
{
public:
    void ModifyOnFinish(Actor* a_caster, Actor* a_target, float a_value) override;  // 1F, compared: 0x5b9fc0
};
