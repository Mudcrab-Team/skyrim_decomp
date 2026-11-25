// Source exposure: mixed (community declarations; the listing of the pinned image).
// Code origin: body adapted from the sibling function below; argument order and sign checked against the listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/Magic/AbsorbEffect.cpp:51
// 0x5b9fc0 AbsorbEffect::ModifyOnFinish
#include "AbsorbEffect_5b9fc0.h"

// The caster is modified by the magnitude, then the target gets the opposite: the same call with the roles swapped.
void AbsorbEffect::ModifyOnFinish(Actor* a_caster, Actor* a_target, float a_value)
{
    ValueModifierEffect::ModifyOnFinish(a_caster, a_target, a_value);
    ValueModifierEffect::ModifyOnFinish(a_target, a_caster, -a_value);
}
