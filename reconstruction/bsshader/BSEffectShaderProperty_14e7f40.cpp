// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x14e7f40 BSEffectShaderProperty::SetAlpha
// Adapted bodies: none
#include "BSEffectShaderProperty_14e7f40.h"

void BSEffectShaderProperty::SetAlpha(float a_alpha)
{
    // crossing the opaque threshold in either direction invalidates the cached render pass state
    const float old = alpha;
    if ((old >= 1.0f && a_alpha < 1.0f) || (old < 1.0f && a_alpha >= 1.0f)) {
        lastRenderPassState = 0x7FFFFFFF;
    }
    alpha = a_alpha;
}
