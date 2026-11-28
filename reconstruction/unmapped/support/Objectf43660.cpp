// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// 0xf43660 Objectf43660::Objectf43660
// CI hash: 0xf43660 ??0Objectf43660@@QEAA@MMMI@Z
// Adapted bodies: none
#include "Objectf43660.h"

// Initializes parameters, reciprocal scale, and default FLT_MAX bounds.
Objectf43660::Objectf43660(float arg1, float arg2, float arg3, std::uint32_t arg4)
{
    u18 = arg4;
    u1c = 0;
    f20 = FLT_MAX;
    f08 = arg1;
    invF0c = 1.0f / arg2;
    f0c = arg2;
    f14 = arg3;
}
