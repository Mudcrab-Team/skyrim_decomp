// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6d9310 Actor::GetTimingForKind6d9310
// Adapted bodies: none
#include "Actor_6d9310.h"

float gValueA;
float gValueB;

float Actor::GetTimingForKind6d9310(int kind)
{
    switch (kind) {
    case 0:
        return gValueB;
    case 1:
        return gValueA;
    case 2:
        return gValueA;
    }
    return 0.0f;
}
