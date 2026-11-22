// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original body from the pinned image listing; declarations are stand-in guesses.
// SPDX-License-Identifier: CC0-1.0
// 0x11cbed0 PathingRequestStopMoving::Function11cbed0
// Adapted bodies: none for Function11cbed0.
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestStopMoving.cpp:17 (PathingRequestStopMoving::GetType)
// PathingRequestStopMoving, GetType, typeId, result, BSCRC32, GenerateCRC: GUESS(low)
#include "PathingRequestStopMoving.h"

// AvoidanceHelper: GUESS(low); unnamed tail-call target.
void AvoidanceHelper(void* a_ptr, int a_flag);

// Body from the pinned image listing.
// 0x11cbed0 PathingRequestStopMoving::Function11cbed0
// Adapted bodies: none
void PathingRequestStopMoving::Function11cbed0()
{
    return AvoidanceHelper(reinterpret_cast<char*>(this) + 0xd8, 1);
}

unsigned int PathingRequestStopMoving::GetType() const
{
    unsigned int result = typeId;
    if (!result) {
        BSCRC32::GenerateCRC(typeId, "PathingRequestStopMoving", 0);
        return typeId;
    }
    return result;
}
