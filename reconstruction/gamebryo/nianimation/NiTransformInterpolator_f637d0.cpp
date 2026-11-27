// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf637d0 NiTransformInterpolator::NiTransformInterpolator
// Adapted bodies: none
#include "NiTransformInterpolator_f637d0.h"

NiTransformInterpolator::NiTransformInterpolator(const NiQuatTransform& a_value) :
    NiInterpolator()
{
    transformValue.translate.x = a_value.translate.x;
    transformValue.translate.y = a_value.translate.y;
    transformValue.translate.z = a_value.translate.z;
    transformValue.rotate = a_value.rotate;
    transformValue.scale = a_value.scale;
    transformData = nullptr;
    unk40 = 0;
    unk44 = 0;
    unk46 = 0;
}
