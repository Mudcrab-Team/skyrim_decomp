// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6b6590 Actor::IsFlagClear6b6590
// Adapted bodies: none
#include "Actor_6b6590.h"

static int GetFlag137(const ActorProcess* process)
{
    if (process) {
        return process->flag137;
    }
    return -1;
}

bool Actor::IsFlagClear6b6590() const
{
    return GetFlag137(process) == 0;
}
