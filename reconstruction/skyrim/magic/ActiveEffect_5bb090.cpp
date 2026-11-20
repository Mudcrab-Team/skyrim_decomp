// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0x5bb090 ActiveEffect::GetBaseObject
// 0x5bb910 ActiveEffect::Function5bb910
// 0x5bb950 ActiveEffect::Function5bb950
// 0x5bcbc0 ActiveEffect::Function5bcbc0
// 0x5bcda0 ActiveEffect::CanFinish
#include "ActiveEffect_5bb090.h"

// dataHandler: GUESS(low)
extern TESDataHandler* dataHandler;

// TestBit: GUESS(low)
inline bool TestBit(std::uint32_t flags, std::uint32_t bit)
{
    return ((flags >> bit) & 1u) != 0;
}

// IsFlagClear: GUESS(low)
inline bool IsFlagClear(std::uint32_t flags, std::uint32_t bit)
{
    return (~(flags >> bit) & 1u) != 0;
}

const EffectSetting* ActiveEffect::GetBaseObject() const noexcept
{
    return effect->baseEffect;
}

bool ActiveEffect::Function5bb910() const
{
    if (flags & 0x4100u) {
        return false;
    }
    if (!TestBit(effect->baseEffect->effectFlags, 9) && duration > elapsedSeconds) {
        return false;
    }
    return true;
}

void ActiveEffect::Function5bb950(bool enabled)
{
    auto changed = flags;
    changed = !enabled ? changed | 4u : changed & ~4u;
    changed = !enabled ? changed | 2u : changed & ~2u;
    changed = !enabled ? changed | 8u : changed & ~8u;
    flags = changed;
}

void ActiveEffect::Function5bcbc0()
{
    if (dataHandler && !dataHandler->Function1c2280()) {
        Function5bac30();
        if (target) {
            ClearTargetImpl();
            target = nullptr;
        }
    }
}

bool ActiveEffect::CanFinish() const
{
    if (!(flags & 0x60u) || !IsFlagClear(flags, 15) || spell->IsValid()) {
        return true;
    }
    return false;
}
