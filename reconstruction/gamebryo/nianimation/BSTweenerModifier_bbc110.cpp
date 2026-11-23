// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xbbc110 BSTweenerModifier::ResetFromSource
// Adapted bodies: none
#include "BSTweenerModifier_bbc110.h"

void BSTweenerModifier::ResetFromSource(Source* const* a_source)
{
    block90 = *(*a_source)->block;
    blendC0 = 0.0f;
    blend80 = 0.0f;
}
