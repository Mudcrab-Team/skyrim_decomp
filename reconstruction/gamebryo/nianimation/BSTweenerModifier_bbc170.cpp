// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xbbc170 BSTweenerModifier::UpdateRate
// Adapted bodies: none
#include "BSTweenerModifier_bbc170.h"

void BSTweenerModifier::UpdateRate(void* a_unused, const UpdateContext* a_context)
{
    if (useFixedRate) {
        rate80 = fixedRate;
    } else if (a_context->delta40 != 0.0f) {
        rate80 = 1.0f / a_context->delta40;
    }
}
