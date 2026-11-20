// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned blend and spline code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xf73d60 NiBlendPoint3Interpolator::Ctor
// CI hash: 0xf73d60 ??0NiBlendPoint3Interpolator@@QEAA@_NEM@Z
// 0xf74090 NiBlendPoint3Interpolator::Ctor
// CI hash: 0xf74090 ??0NiBlendPoint3Interpolator@@QEAA@XZ
// Adapted bodies: none
#include "NiBlendPoint3Interpolator_f73d60.h"

extern const NiPoint3 gDefaultValue;

NiBlendPoint3Interpolator::NiBlendPoint3Interpolator(bool managerControlled, std::uint8_t capacity, float weightThreshold) :
    NiBlendInterpolator(managerControlled, capacity, weightThreshold), value{gDefaultValue.x, gDefaultValue.y, gDefaultValue.z}, valid(false)
{

}

NiBlendPoint3Interpolator::NiBlendPoint3Interpolator() :
    value{gDefaultValue.x, gDefaultValue.y, gDefaultValue.z}, valid(false)
{

}
