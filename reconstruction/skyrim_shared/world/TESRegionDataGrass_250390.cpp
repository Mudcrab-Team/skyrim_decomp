// Source exposure: binary-analysis (pinned-image observations); sibling game-code declarations inspected.
// Code origin: original; no external implementation body copied.
// SPDX-License-Identifier: CC0-1.0
// 0x250390 TESRegionDataGrass::Function250390
// Adapted bodies: none.
#include "TESRegionDataGrass_250390.h"

DispatchTarget* TESRegionDataGrass::Function250390(void* argument)
{
    DispatchTarget* target = LookupTarget();
    target->Dispatch(argument, 2);
    return target;
}
