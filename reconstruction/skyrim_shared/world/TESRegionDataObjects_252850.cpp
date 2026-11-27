// Source exposure: binary-analysis (pinned-image observations); sibling game-code declarations inspected.
// Code origin: original; no external implementation body copied.
// SPDX-License-Identifier: CC0-1.0
// 0x252850 TESRegionDataObjects::Function252850
// Adapted bodies: none.
#include "TESRegionDataObjects_252850.h"

DispatchTarget* TESRegionDataObjects::Function252850(void* argument)
{
    DispatchTarget* target = LookupTarget();
    target->Dispatch(argument, 2);
    return target;
}
