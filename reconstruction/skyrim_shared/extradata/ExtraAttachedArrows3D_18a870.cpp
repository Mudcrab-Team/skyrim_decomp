// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x18a870 ExtraAttachedArrows3D::Function18a870
// Adapted bodies: none
#include "ExtraAttachedArrows3D_18a870.h"

bool ExtraAttachedArrows3D::Function18a870()
{
    std::uint32_t now = GetTickCount();
    float elapsed = static_cast<float>(now - startTime);
    return elapsed >= g_arrowDelay * 1000.0f;
}
