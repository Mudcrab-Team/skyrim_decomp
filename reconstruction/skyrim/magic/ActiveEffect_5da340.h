// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ActiveEffect, ActiveEffect::Function5da340, ActiveEffect::Function5bb090, EffectSetting, EffectSetting::sub_1400FB930, a_other: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class EffectSetting
{
public:
    void* sub_1400FB930();
};

class ActiveEffect
{
public:
    bool Function5da340(ActiveEffect* a_other);
    EffectSetting* Function5bb090();
};
