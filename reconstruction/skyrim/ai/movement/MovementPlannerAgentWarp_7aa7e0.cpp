// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7aa7e0 MovementPlannerAgentWarp::~MovementPlannerAgentWarp
// Adapted bodies: none
#include "MovementPlannerAgentWarp_7aa7e0.h"
#include <intrin.h>

MovementPlannerAgentWarp::~MovementPlannerAgentWarp()
{
    NiRefObject* released = object;
    if (released) {
        // refcount: atomic release, last owner destroys the object
        if (_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&released->_refCount), -1) == 1) {
            delete released;
        }
    }
}
