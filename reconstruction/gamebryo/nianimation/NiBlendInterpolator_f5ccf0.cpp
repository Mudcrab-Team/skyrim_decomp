// Source exposure: mixed (local target observations; community declarations).
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// 0xf5ccf0 NiBlendInterpolator::NiBlendInterpolator
#include "NiBlendInterpolator_f5ccf0.h"
#include <cfloat>

NiBlendInterpolator::NiBlendInterpolator() :
    flags(0), arraySize(0), interpolatorCount(0), singleIndex(0xFF),
    highPriority(-128), nextHighPriority(-128),
    interpArray(nullptr), singleInterpolator(nullptr), weightThreshold(0.0f),
    singleTime(-FLT_MAX), highWeightSum(-FLT_MAX), nextHighWeightSum(-FLT_MAX), highEaseSpinner(-FLT_MAX)
{}
