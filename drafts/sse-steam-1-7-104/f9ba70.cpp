// Near miss: 25.88% | inline-set
// Exposure detail: (pinned-image observations and RTTI).
// Source exposure: binary-analysis
// Code origin: original; observed initialization and RTTI class identity.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xf9ba70 NiPSysEmitterCtlr::ctor

#include "include/f9ba70/NiPSysEmitterCtlr_f9ba70.h"
#include <cfloat>
NiPSysEmitterCtlr::NiPSysEmitterCtlr() :
    visibilityInterpolator(nullptr), unknown68(nullptr), scaledLastTime(-FLT_MAX),
    unknown74(0), unknown78(0), state{}
{}
