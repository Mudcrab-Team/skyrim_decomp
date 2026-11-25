// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x417330 Sky::Function417330
// Adapted bodies: none
#include "Sky_417330.h"

std::int64_t Sky::Function417330()
{
    SkyTarget* target = g_skyHolder->unkC0;
    if (target) {
        std::int64_t value = GetSkyTargetValue(target);
        if (value) {
            return value;
        }
    }
    return g_skyOther->unk48;
}
