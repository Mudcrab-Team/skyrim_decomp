// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Cookbook: 0x148a20 34
// 0x148a20 Func_148a20::GetMatchingTarget
// Adapted bodies: none
#include "Func_148a20.h"

// Returns the effect's target when both its table kind and target formType equal 0x13.
const Target148a20* Func_148a20::GetMatchingTarget() const
{
    const Target148a20* result = nullptr;
    const EffectData148a20* data = effect;
    if (gEffectTable148a20[data->tableIndex].kind == 0x13)
    {
        const Target148a20* target = data->target;
        if (target != nullptr && target->formType == 0x13)
        {
            result = target;
        }
    }
    return result;
}
